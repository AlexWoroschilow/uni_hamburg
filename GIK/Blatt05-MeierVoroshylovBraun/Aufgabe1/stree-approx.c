#include "core/unused_api.h"
#include "gt_suffixtree.h"
#include "stree-approx.h"

/**
 * Custom structure to
 * work with pattern
 */
typedef struct GtPattern {
	const GtUchar * pattern;
	unsigned int length;
} GtPattern;

/**
 * Custom structure to work
 * with leaves set
 */
typedef struct GtLeaves {
	GtUword * collection;
	unsigned int count;
} GtLeaves;

/**
 * Custom method to build
 * a GtPattern from parts
 */
GtPattern * gt_stree_pattern(const GtUchar *pattern, GtUword len) {
	GtPattern * P = malloc(sizeof(GtPattern));
	P->pattern = pattern;
	P->length = (unsigned int) len;
	return P;
}

/**
 * Custom method to build
 * a GtLeaves from parts
 */
GtLeaves * gt_stree_leaves(const GtStree *stree, const GtStreeLoc *loc) {
	unsigned int x;
	const GtUword * collection = gt_stree_loc_positions(stree, loc);
	unsigned int count = gt_stree_loc_leaves_count(loc);
	for (x = 0; x < count; x++) {
		printf("%lu\n", (unsigned long) (collection[x]));
	}
	return NULL;
}

/**
 * Algorithm from Script
 */
void approxmatch(const GtStree *stree, const GtPattern *pattern, unsigned int k, const GtStreeLoc *loc, unsigned int i,
		unsigned int z) {

	if (z > k) {
		return;
	}

	if (i >= pattern->length) {
		gt_stree_leaves(stree, loc);
		return;
	}

	approxmatch(stree, pattern, k, loc, i + 1, z + 1);

	GtUword position;
	for (position = 0; position < gt_stree_numofchars(stree); position++) {

		GtUchar b = gt_stree_encoded_char(stree, position);

		GtStreeLoc * follow = gt_stree_loc_new();
		if (gt_stree_loc_follow(stree, follow, loc, b)) {

			approxmatch(stree, pattern, k, follow, i, z + 1);
			if (b == pattern->pattern[i]) {
				approxmatch(stree, pattern, k, follow, i + 1, z);
			} else {
				approxmatch(stree, pattern, k, follow, i + 1, z + 1);
			}
		}
		free(follow);
	}

	return;
}

/**
 * Predefined method to fill
 */
void stree_approx_pattern_match(const GtStree *stree, const GtUchar *pattern, GtUword len, GtUword differences) {

	GtPattern * P = gt_stree_pattern(pattern, len);

	const GtStreeLoc * loc = gt_stree_root_loc_new(stree);

	unsigned int k = differences;
	unsigned int i = 0;
	unsigned int z = 0;

	approxmatch(stree, P, k, loc, i, z);

	free(P);

	return;
}

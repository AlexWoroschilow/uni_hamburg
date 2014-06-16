#ifndef STREE_EXACT_H
#define STREE_EXACT_H
#include "gt_suffixtree.h"

/* implement this function in stree-exact.c */

const GtUword *stree_exact_pattern_match(GtUword *numofmatches,
                                         const GtStree *stree,
                                         const GtUchar *pattern,
                                         GtUword len);

#endif

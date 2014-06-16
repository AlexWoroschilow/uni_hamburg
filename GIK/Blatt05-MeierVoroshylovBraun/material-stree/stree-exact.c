#include "core/unused_api.h"
#include "gt_suffixtree.h"
#include "stree-exact.h"

/* remove GT_UNUSED once the function is completly implemented */

const GtUword *stree_exact_pattern_match(GtUword *numofmatches,
                                         GT_UNUSED const GtStree *stree,
                                         GT_UNUSED const GtUchar *pattern,
                                         GT_UNUSED GtUword len)
{
  *numofmatches = 0;
  return NULL;
}

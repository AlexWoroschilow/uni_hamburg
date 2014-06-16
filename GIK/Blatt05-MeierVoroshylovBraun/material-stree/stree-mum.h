#ifndef STREE_MUM_H
#define STREE_MUM_H
#include "core/types_api.h"
#include "core/error_api.h"

int gt_stree_mum(const char *indexname,
                 GtUword minlength,
                 bool withsequence,
                 GtError *err);

#endif

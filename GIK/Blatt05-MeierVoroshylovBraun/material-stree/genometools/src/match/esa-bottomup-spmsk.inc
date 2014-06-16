/*
  Copyright (c) 2011-2012 Stefan Kurtz <kurtz@zbh.uni-hamburg.de>
  Copyright (c) 2011-2012 Center for Bioinformatics, University of Hamburg

  Permission to use, copy, modify, and distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

/*
  THIS FILE IS GENERATED by
  scripts/gen-esa-bottomup.rb
  --key spmsk
  --no_process_branchingedge.
  DO NOT EDIT.
*/

#include <limits.h>
#include "core/ma.h"
#include "esa-seqread.h"
#include "seqnumrelpos.h"

static void initBUinfo_spmsk(GtBUinfo_spmsk *,
                              GtBUstate_spmsk *);

static void freeBUinfo_spmsk(GtBUinfo_spmsk *,
                              GtBUstate_spmsk *);

static int processleafedge_spmsk(bool,
    GtUword,
    GtBUinfo_spmsk *,
    GtUword, /* seqnum */
    GtUword, /* relpos */
    GtBUstate_spmsk *,
    GtError *err);

/* no declaration of processbranchingedge_spmsk */

static int processlcpinterval_spmsk(GtUword,
    GtBUinfo_spmsk *,
    GtBUstate_spmsk *,
    GtError *err);

#define TOP_ESA_BOTTOMUP_spmsk\
        stack->spaceGtBUItvinfo[stack->nextfreeGtBUItvinfo-1]

#define POP_ESA_BOTTOMUP_spmsk\
        (stack->spaceGtBUItvinfo + (--stack->nextfreeGtBUItvinfo))

#define PUSH_ESA_BOTTOMUP_spmsk(LCP,LB)\
        if (stack->nextfreeGtBUItvinfo >= stack->allocatedGtBUItvinfo)\
        {\
          gt_assert(stack->nextfreeGtBUItvinfo ==\
                    stack->allocatedGtBUItvinfo);\
          stack->spaceGtBUItvinfo\
            = allocateBUstack_spmsk(stack->spaceGtBUItvinfo,\
                              stack->allocatedGtBUItvinfo,\
                              stack->allocatedGtBUItvinfo+incrementstacksize,\
                              bustate);\
          stack->allocatedGtBUItvinfo += incrementstacksize;\
        }\
        gt_assert(stack->spaceGtBUItvinfo != NULL);\
        stack->spaceGtBUItvinfo[stack->nextfreeGtBUItvinfo].lcp = LCP;\
        stack->spaceGtBUItvinfo[stack->nextfreeGtBUItvinfo].lb = LB;\
        stack->spaceGtBUItvinfo[stack->nextfreeGtBUItvinfo++].rb = ULONG_MAX

typedef struct
{
  GtUword lcp, lb, rb;
  GtBUinfo_spmsk info;
} GtBUItvinfo_spmsk;

typedef struct
{
  GtBUItvinfo_spmsk *spaceGtBUItvinfo;
  GtUword allocatedGtBUItvinfo,
                nextfreeGtBUItvinfo;
} GtArrayGtBUItvinfo_spmsk;

GtArrayGtBUItvinfo_spmsk *gt_GtArrayGtBUItvinfo_new_spmsk(void)
{
  GtArrayGtBUItvinfo_spmsk *stack = gt_malloc(sizeof (*stack));

  stack->spaceGtBUItvinfo = NULL;
  stack->allocatedGtBUItvinfo = stack->nextfreeGtBUItvinfo = 0;
  return stack;
}

void gt_GtArrayGtBUItvinfo_delete_spmsk(
                           GtArrayGtBUItvinfo_spmsk *stack,
                           GtBUstate_spmsk *state)
{
  GtUword idx;

  for (idx=0; idx<stack->allocatedGtBUItvinfo; idx++)
  {
    freeBUinfo_spmsk(&stack->spaceGtBUItvinfo[idx].info,state);
  }
  gt_free(stack->spaceGtBUItvinfo);
  gt_free(stack);
}

static GtBUItvinfo_spmsk *allocateBUstack_spmsk(
                                   GtBUItvinfo_spmsk *ptr,
                                   GtUword currentallocated,
                                   GtUword allocated,
                                   GtBUstate_spmsk *state)
{
  GtUword idx;
  GtBUItvinfo_spmsk *itvinfo;

  itvinfo = gt_realloc(ptr,sizeof (*itvinfo) * allocated);
  gt_assert(allocated > currentallocated);
  for (idx=currentallocated; idx<allocated; idx++)
  {
    initBUinfo_spmsk(&itvinfo[idx].info,state);
  }
  gt_assert(itvinfo != NULL);
  return itvinfo;
}

static int gt_esa_bottomup_RAM_spmsk(const GtUword *bucketofsuffixes,
                        const uint16_t *lcptab_bucket,
                        GtUword numberofsuffixes,
                        GtArrayGtBUItvinfo_spmsk *stack,
                        GtBUstate_spmsk *bustate,
                        const GtSeqnumrelpos *snrp,
                        GtError *err)
{
  const GtUword incrementstacksize = 32UL;
  GtUword lcpvalue,
                previoussuffix,
                idx;
  GtBUItvinfo_spmsk *lastinterval = NULL;
  bool haserr = false, firstedge, firstedgefromroot;

  PUSH_ESA_BOTTOMUP_spmsk(0,0);
  firstedgefromroot = true;
  gt_assert (numberofsuffixes > 0);
  for (idx = 0; !haserr && idx < numberofsuffixes-1; idx++)
  {
    lcpvalue = (GtUword) lcptab_bucket[idx+1];
    previoussuffix = bucketofsuffixes[idx];
    gt_assert(stack->nextfreeGtBUItvinfo > 0);
    if (lcpvalue <= TOP_ESA_BOTTOMUP_spmsk.lcp)
    {
      if (TOP_ESA_BOTTOMUP_spmsk.lcp > 0 || !firstedgefromroot)
      {
        firstedge = false;
      } else
      {
        firstedge = true;
        firstedgefromroot = false;
      }
      if (processleafedge_spmsk(firstedge,
                          TOP_ESA_BOTTOMUP_spmsk.lcp,
                          &TOP_ESA_BOTTOMUP_spmsk.info,
                          gt_seqnumrelpos_decode_seqnum(snrp,previoussuffix),
                          gt_seqnumrelpos_decode_relpos(snrp,previoussuffix),
                          bustate,
                          err) != 0)
      {
        haserr = true;
      }
    }
    gt_assert(lastinterval == NULL);
    while (!haserr && lcpvalue < TOP_ESA_BOTTOMUP_spmsk.lcp)
    {
      lastinterval = POP_ESA_BOTTOMUP_spmsk;
      lastinterval->rb = idx;
      if (processlcpinterval_spmsk(lastinterval->lcp,
                             &lastinterval->info,
                             bustate,
                             err) != 0)
      {
        haserr = true;
      }
      if (lcpvalue <= TOP_ESA_BOTTOMUP_spmsk.lcp)
      {
        if (!(TOP_ESA_BOTTOMUP_spmsk.lcp > 0 || !firstedgefromroot))
        {
          firstedgefromroot = false;
        }
        /* no call to processbranchingedge_spmsk */
        lastinterval = NULL;
      }
    }
    if (!haserr && lcpvalue > TOP_ESA_BOTTOMUP_spmsk.lcp)
    {
      if (lastinterval != NULL)
      {
        GtUword lastintervallb = lastinterval->lb;
        PUSH_ESA_BOTTOMUP_spmsk(lcpvalue,lastintervallb);
        lastinterval = NULL;
      } else
      {
        PUSH_ESA_BOTTOMUP_spmsk(lcpvalue,idx);
        if (processleafedge_spmsk(true,
                            TOP_ESA_BOTTOMUP_spmsk.lcp,
                            &TOP_ESA_BOTTOMUP_spmsk.info,
                            gt_seqnumrelpos_decode_seqnum(snrp,previoussuffix),
                            gt_seqnumrelpos_decode_relpos(snrp,previoussuffix),
                            bustate,
                            err) != 0)
        {
          haserr = true;
        }
      }
    }
  }
  gt_assert(stack->nextfreeGtBUItvinfo > 0);
  if (!haserr && TOP_ESA_BOTTOMUP_spmsk.lcp > 0)
  {
    GtUword lastsuftabvalue = bucketofsuffixes[numberofsuffixes-1];
    if (processleafedge_spmsk(false,
                        TOP_ESA_BOTTOMUP_spmsk.lcp,
                        &TOP_ESA_BOTTOMUP_spmsk.info,
                        gt_seqnumrelpos_decode_seqnum(snrp,lastsuftabvalue),
                        gt_seqnumrelpos_decode_relpos(snrp,lastsuftabvalue),
                        bustate,
                        err) != 0)
    {
      haserr = true;
    } else
    {
      TOP_ESA_BOTTOMUP_spmsk.rb = idx;
      if (processlcpinterval_spmsk(TOP_ESA_BOTTOMUP_spmsk.lcp,
                             &TOP_ESA_BOTTOMUP_spmsk.info,
                             bustate,
                             err) != 0)
      {
        haserr = true;
      }
    }
  }
  stack->nextfreeGtBUItvinfo = 0; /* empty the stack */
  return haserr ? -1 : 0;
}
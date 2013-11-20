/* alignments.h */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./alignments.c"



//typedef enum {
//} edit;
//  
//typedef enum {
//} base;

typedef struct multiedit {
} multiedit;

typedef struct alignment {
} alignment;


int alignment_new(alignment *newalg, char seq1[], char seq2[], char align[])


int alignment_add_operation(alignment *alg, int count, char type)


int alignment_show(alignment alg)


int alignment_evalcost(alignment alg)


int alignment_delete(alignment *alg)

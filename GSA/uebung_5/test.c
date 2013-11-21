

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "alignments.h"



int main() {

    int evalcost;

    char *align = "R7I2R2D1R3I1R3";

    char *seq1 = "acgtagatatatagat";
    char *seq2 = "agaaagaggtaagaggga";
       
    alignment alg = alignment_new(seq1, seq2, align);

    alignment_show(alg);

    evalcost = alignment_evalcost(alg);

    printf("\tCosts: %d\n\n", evalcost);

    printf("\tadding one deletion...\n");
    alignment_add_operation(&alg, 1, 'D');
    alignment_show(alg);

    printf("\tadding one insertion...\n");
    alignment_add_operation(&alg, 1, 'I');
    alignment_show(alg);

    printf("\tadding one replacement...\n");
    alignment_add_operation(&alg, 1, 'R');
    alignment_show(alg);

    return(EXIT_SUCCESS);
}
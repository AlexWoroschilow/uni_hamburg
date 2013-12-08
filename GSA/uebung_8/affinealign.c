#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "alignment.h"
#include "matrix.h"


int main(int argc, char *argv[])
{
    char * seq1;
    char * seq2;
    int gap_start;
    int gap_extend;

    if(argc == 5) {

        seq1 = argv[1];
        seq2 = argv[2];

//        sscanf(argv[1], "%s", seq1);
//        sscanf(argv[2], "%s", seq2);

        sscanf(argv[3], "%d", &gap_start);
        sscanf(argv[4], "%d", &gap_extend);


        DPentry ** matrix = matrix_fill(seq1, seq2);
        Alignment * alignment = alignment_new (seq1, seq2);

        traceback(alignment, matrix, strlen(seq1)-1, strlen(seq2)-1, gap_start, gap_extend);

        alignment_show(alignment);
    }

    return EXIT_SUCCESS;
}

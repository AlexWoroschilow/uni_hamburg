#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "alignments.h"
#include "editmatrix.h"


void traceback(int matrix[6][6], struct alignment *alg, int i, int j)
{
    int lenX = alg->seq1len,
        lenY = alg->seq2len;

    int currentTop = NULL;
    int currentLeft = NULL;
    int currentLeftTop = NULL;

    int x, y, xLeft, yLeft, xTop, yTop, xLeftTop, yLeftTop;


    x = i-1;
    y = j-1;

    printf("\n\t%d\t%d\t", x, y);

    while ( x != 0 && y != 0 ) {

        xTop = x;
        yTop = y-1;
        xLeft = x-1;
        yLeft = y;
        xLeftTop = x-1;
        yLeftTop = y-1;

        if(i < lenX && j < lenY) {

            if (xTop < lenX && yTop < lenY) {
                currentTop = matrix[xTop][yTop];
            }
            if (xLeft < lenX && yLeft < lenY) {
                currentLeft = matrix[xLeft][yLeft];
            }
            if (xLeftTop < lenX && yLeftTop < lenY) {
                currentLeftTop = matrix[xLeftTop][yLeftTop];
            }

            if(currentTop < currentLeft && currentTop < currentLeftTop) {
                x = xTop;
                y = yTop;
                alignment_add_operation(alg, 1, 'D');
            } else if(currentLeft < currentTop && currentLeft < currentLeftTop) {
                x = xLeft;
                y = yLeft;
                alignment_add_operation(alg, 1, 'I');
            } else if(currentLeftTop < currentTop && currentLeftTop < currentLeft) {
                x = xLeftTop;
                y = yLeftTop;
                alignment_add_operation(alg, 1, 'R');
            } else {
                x = xLeftTop;
                y = yLeftTop;
                alignment_add_operation(alg, 1, 'R');
            }
        }

        printf("\n\t%d\t%d\t", x, y);
    }
}


int main (int argc, char *argv[])
{
    int matrix[6][6] = {
        {1,1,0,0,0,0},
        {2,2,1,1,0,0},
        {2,2,3,1,1,0},
        {1,1,0,0,0,0},
        {2,2,1,1,0,0},
        {2,2,3,1,1,0},
    };

    struct alignment alg;

    /* ich will, dass u und v Strings sind, so dass ich die Längen finden kann */
    char *u = argv[1];
    char *v = argv[2];

    /* Überprüfen, ob zwei Kommandozeilenparameter eingegeben sind */
    if(argc != 3 || (sscanf(argv[1], "%s", &*u)) != 1 || (sscanf(argv[2], "%s", &*v)) != 1) {
        printf("\tBitte zwei Sequenzen angeben\n");
        exit(EXIT_FAILURE);
    }


    fillDPtable(u, v);


    char seq1[] = "acgtagatatatagat";
    char seq2[] = "agaaagaggtaagaggga";
    char seq1_seq2_alg[] = "R7I2R2D1R3I1R3";


    alg = alignment_new(seq1, seq2, seq1_seq2_alg);


    traceback(matrix, &alg, 4, 4);


    alignment_show(alg);


    return 0;
}

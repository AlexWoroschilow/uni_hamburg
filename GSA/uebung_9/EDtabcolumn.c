/* header fuer Aufgabe 8.3 by Felix Braun */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EDtabcolumn.h"
// #include "alignments.h"

typedef struct ELEMENT {                /* Struktur der Matrixwert */

    int value;                          /* Tatsaechlicher Distanzwert */        
    int origin;                         /* Ursprung des partiellen Alignments */

} ELEMENT;


int getminA(int a, int b, int c) {

    if(a <= b && a <= c) {

        return(a);                      /* Replacement */

    } else if(b <= a && b <= c) {

        return(b);                      /* Insertion */

    } else {

        return(c);                      /* Deletion */
    }
}


char getminB(int a, int b, int c) {     /* Gibt wieder welche Operation durchgefuehrt wird */
    
        if(a <= b && a <= c) {

                return('R');            /* Replacement */

        } else if(b <= a && b <= c) {

                return('I');            /* Insertion */

        } else {

                return('D');            /* Deletion */
        }
}


void firstEDtabcolumn(int *col, int length) {

    int i;

    col[0] = 0;

    for(i = 1; i < length; i++) {

        col[i] = col[i-1] + 1;
    }
}


int* nextEDtabcolumn(int *col, int length, char b, char *u) {

    int i, x;
    int *ncol = malloc(length * sizeof(ncol));

    ncol[0] = 0;

    for(i = 1; i < length; i++) {

        x = (u[i-1] == b ? 0 : 1);

        ncol[i] = getminA(col[i-1] + x,
            col[i] + 1, ncol[i-1] + 1);
    }

    free(col);

    return(ncol);
}


ELEMENT* firstEDtabRcolumn(ELEMENT *rcol, int lengthu, int j0, char *u, char *v) {

    int i;
    int *col = malloc(lengthu * sizeof(col));

    firstEDtabcolumn(col, lengthu);

    for(i = 0; i < j0; i++) {

        col = nextEDtabcolumn(col, lengthu, v[i], u);
    }

    for(i = 0; i < lengthu; i++) {

        rcol[i].value = col[i];
        rcol[i].origin = i;
    }
    
    free(col);

    return(rcol);
}


int nextEDtabRcolumn(ELEMENT *rcol, int j0, int lengthu, char b, char *u) {

    int i, x;
    ELEMENT *nrcol = malloc(lengthu * sizeof(nrcol));

    nrcol[0].value = 0;
    nrcol[0].origin = 0;

    for(i = 1; i < lengthu; i++) {

        x = (u[i-1] == b ? 0 : 1);

        switch(getminB(rcol[i-1].value + x,
                rcol[i].value + 1, nrcol[i-1].value + 1)) {

                case 'R': 
                nrcol[i].value = rcol[i-1].value + x;
                nrcol[i].origin = rcol[i-1].origin;
                break;

                case 'I': 
                nrcol[i].value = rcol[i].value + 1;
                nrcol[i].origin = rcol[i].origin;
                break;

                case 'D': 
                nrcol[i].value = nrcol[i-1].value + 1;
                nrcol[i].origin = nrcol[i-1].origin;
                break;

                default:
                printf("\n\n\tUnknown Error! Aborting...\n");
                abort();
        }
    }

    rcol = nrcol;

    free(nrcol);

    return(rcol[lengthu-1].origin);
}


void evaluateallcolumns(int lengthu, int lengthv, char *u, char *v) {

    int i, j0;

    int *col = malloc(lengthu * sizeof(col));
    ELEMENT *rcol = malloc(lengthu * sizeof(rcol));

    firstEDtabcolumn(col, lengthu);

    for(i = 1; i < strlen(v); i++) {

        col = nextEDtabcolumn(col, lengthu, v[i-1], u);
    }

    j0 = lengthv / 2;

    firstEDtabRcolumn(rcol, lengthu, j0, u, v);

    for(i = j0; i < lengthv; i++) {

        nextEDtabRcolumn(rcol, j0, lengthu, v[i-1], u);
    }
}

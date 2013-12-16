/* header fuer Aufgabe 9.1 by Felix Braun */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EDtabcolumn.h"
#include "alignment.h"

typedef struct Element {                /* Struktur der Matrixwerte */

    int value;                          /* Tatsaechlicher Distanzwert */        
    int origin;                         /* Ursprung des partiellen Alignments */

} Element;


typedef struct Crosspoint {

    int i;
    int c;

} Crosspoint;


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

void nextEDtabcolumn(int *col, int length, char b, char *u) {

    int i, x;
    int tmp1, tmp2;
    
    col[0] = 0;
    tmp2 = col[0];

    for(i = 1; i < length; i++) {

        tmp1 = col[i];

        x = (u[i-1] == b ? 0 : 1);

        col[i] = getminA(tmp2 + x,
            col[i] + 1, col[i-1] + 1);

        tmp2 = tmp1;
    }
}


void firstEDtabRcolumn(Element *rcol, int lengthu, int j0, char *u, char *v) {

    int i;
    int *col = malloc(lengthu * sizeof(col));

    firstEDtabcolumn(col, lengthu);

    for(i = 0; i < j0; i++) {

        nextEDtabcolumn(col, lengthu, v[i], u);
    }

    for(i = 0; i < lengthu; i++) {

        rcol[i].value = col[i];
        rcol[i].origin = i;

//        if(!(i%3)) {
//
//            printf("\n\t");
//        }
//        
//        printf(" v = %d; o = %d ", rcol[i].value, rcol[i].origin);
    }

//    printf("\n\n");

    free(col);
}


int nextEDtabRcolumn(Element *rcol, int j0, int lengthu, char b, char *u) {

    int i, x;
    Element tmp1, tmp2;
    
    rcol[0].value = 0;
    rcol[0].origin = 0;
    tmp2.value = rcol[0].value;
    tmp2.origin = rcol[0].origin;

    for(i = 1; i < lengthu; i++) {

        tmp1.value = rcol[i].value;
        tmp1.origin = rcol[i].origin;

        x = (u[i-1] == b ? 0 : 1);

        switch(getminB(tmp2.value + x,
                rcol[i].value + 1, rcol[i-1].value + 1)) {

                case 'R': 
                rcol[i].value = tmp2.value + x;
                rcol[i].origin = tmp2.origin;
                break;

                case 'I': 
                rcol[i].value = rcol[i].value + 1;
                rcol[i].origin = rcol[i].origin;
                break;

                case 'D': 
                rcol[i].value = rcol[i-1].value + 1;
                rcol[i].origin = rcol[i-1].origin;
                break;

                default:
                printf("\n\n\tUnknown Error! Aborting...\n");
                abort();
        }

        tmp2.value = tmp1.value;
        tmp2.origin = tmp1.origin;
    }

//    printf("\tvi = %d; oi = %d ", rcol[lengthu-1].value, rcol[lengthu-1].origin);
//    printf("\n");

    return(rcol[lengthu-1].origin);
}


void evaluateallcolumns(int lengthu, int lengthv, char *u, char *v) {

    int i, j0;

    Crosspoint *crosspoints = malloc(lengthv * sizeof(crosspoints));

    crosspoints[0].i = 0;
    crosspoints[0].c = 0;

    int *col = malloc(lengthu * sizeof(col));    

    firstEDtabcolumn(col, lengthu);

    for(i = 1; i < (lengthv / 2); i++) {

        nextEDtabcolumn(col, lengthu, v[i-1], u);
    }

    crosspoints[lengthv-1].i = lengthu;
    crosspoints[lengthv-1].c = col[lengthv-1];

    j0 = lengthv / 2 + (lengthv % 2);

	crosspoints[lengthv-1].c = evaluatecrosspoints(crosspoints, j0, lengthu, lengthv, u, v);


    for(i = 0; i < lengthv; i++) {

        printf(" (%d|%d) -> Value = %d ", i, crosspoints[i].i, crosspoints[i].c);

        if(!(i%3) && i != 0) {

            printf("\n\t");
        }
    }

	printf("\n");    

    free (col);
}


int evaluatecrosspoints(Crosspoint *crosspoints, int j0, int lengthu, int lengthv, char *u, char *v) {

    Element *rcol = malloc(lengthu * sizeof(rcol));

    int r, i;

//    char *uDown, *vDown;
//    char *uUp, *vUp;

    int lengthvDown, lengthuDown;
    int lengthvUp;

    int j0Up, j0Down;

    firstEDtabRcolumn(rcol, lengthu, j0, u, v);

    for(i = 1; i < lengthv; i++) {

        if(i != lengthv -1) {

            nextEDtabRcolumn(rcol, j0, lengthu, v[i-1], u);

        } else {

            crosspoints[j0].i = nextEDtabRcolumn(rcol, j0, lengthu, v[i-1], u);
        }
    }


    if(lengthv > 1) {

        /*rekursiver Aufruf für alle j < j0 */
	
//        lengthuDown = crosspoints[lengthv-1].i;
//        lengthvDown = j0;
//
//        vDown = malloc(lengthvDown * sizeof(vDown));
//
//        for(i = 0; i < lengthvDown; i++) {
//
//            vDown[i] = v[i];
//        }
//    
//    	uDown = malloc(lengthuDown * sizeof(uDown));
//    
//        for(i = 0; i < lengthuDown; i++) {
//    
//    	 	uDown[i] = u[i];
//        }
    
        lengthvDown = lengthv / 2;
        lengthuDown = crosspoints[j0].i + 1;

        j0Down = j0 / 2;
    
    	crosspoints[j0].c = evaluatecrosspoints(crosspoints, j0Down, 
    						lengthuDown, lengthvDown, u, v);
    
    
        /*rekursiver Aufruf für alle j > j0 */
    
//        lengthuUp = crosspoints[lengthv-1].i;
//        lengthvUp = j0;
//    
//    	vUp = malloc(lengthvUp * sizeof(vUp));
//    
//        for(i = 0; i < lengthvUp; i++) {
//    
//        	vUp[i] = v[i + lengthvUp];
//        }
//    
//    	uUp = malloc(lengthuUp * sizeof(uUp));
//    
//        for(i = 0; i < lengthuUp; i++) {
//    
//        	uUp[i] = u[i + lengthuUp];
//        }
    
        lengthvUp = lengthv / 2 + (lengthv % 2);

        j0Up = j0 + (j0 / 2);
    
        evaluatecrosspoints(crosspoints, j0Up, lengthu, lengthvUp, u, v);
    }
        
    r = rcol[crosspoints[j0].i].value;

    free(rcol);

    return(r);    
}

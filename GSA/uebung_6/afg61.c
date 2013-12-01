#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "alignments.h"
#include "editmatrix.h"


void traceback(int E[100][100][4], struct alignment *alg)
{
    int i,j;


	for (i=100;i>=0;i--) {
	
	    for (j=100;j>=0;j--) {

//            printf("%d\t", E[i][j][0]);
    		if (E[i][j][3] != 0 ) {

    			alignment_add_operation(alg, 1, 'R');
            } else if (E[i][j][3] == 0 && E[i][j][2] != 0) {
    			alignment_add_operation(alg, 1, 'D');
    		} else {
    			alignment_add_operation(alg, 1, 'I');
    		}	
    	}
//        printf("\n");
    }
}


int main (int argc, char *argv[]) 
{
    char *u = argv[1];
    char *v = argv[2];
    char *z = ""/*"R1I1R1"*/;

  	if(argc != 3 || (sscanf(argv[1], "%s", &*u)) != 1 || 
  						(sscanf(argv[2], "%s", &*v)) != 1) {
    	printf("\tBitte zwei Sequenzen angeben\n");
    	exit(EXIT_FAILURE);	
    }

    struct alignment alg;

	int E[100][100][4];
    fillDPtable(u,v,E);
    printf("%d\n",E[3][2][0]);


    alg = alignment_new(u, v, z);


    traceback(E, &alg);


    alignment_show(alg);


    return 0;
}

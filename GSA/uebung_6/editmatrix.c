#include <stdio.h>                        	/* use standard output routines */
#include <stdlib.h>                      	/* use standard library functions */
#include <string.h>							/* include string library */
#include "alignments.h"



int min(int a,int b,int c)
{
    if(a <= b && a <= c) {
        return a;
    } else if(b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

void fillDPtable(char u[], char v[])
{
    int i, j, a, b, c, d, m, n;

    m = strlen(u);
    n = strlen(v);


    int E[m+1][n+1];
    for(i = 0; i < n+1; i++) {
        printf("\n");
        for(j = 0; j < m+1; j++) {
            if((i == 0) && (j == 0)) {
                E[j][i] = 0;
            } else if((i == 0) && (j > 0)) {
                E[j][i] = j;
            } else if((i > 0) && (j == 0)) {
                E[j][i] = i;
            } else {
                a = E[j][i-1] + 1;
                b = E[j-1][i] + 1;
                c = E[j-1][i-1];
                d = E[j-1][i-1] + 1;
                if(u[j-1] == v[i-1]) {
                    E[j][i] = min(a, b, c);
                } else {
                    E[j][i] = min(a, b, d);
                }
            }
            printf("\t%d", E[j][i]);
        }
    }
    /*printf("\n\n");*/
    printf("\t edist= %d \n \n",E[m][n]);			 /* Editdistanz Ausgabe */
}

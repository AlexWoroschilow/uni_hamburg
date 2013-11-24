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

int fillDPtable(char u[], char v[])
{
    int i, j, a, b, c, d, m, n;

    m = strlen(u);
    n = strlen(v);

    int E[m+1][n+1][4];
    for(i = 0; i < n+1; i++) {
      printf("\n");
      for(j = 0; j < m+1; j++) {
        E[j][i][1]=0;
        E[j][i][2]=0;
        E[j][i][3]=0;
        if((i == 0) && (j == 0)) {
              E[j][i][0] = 0;
        } else if((i == 0) && (j > 0)) {
              E[j][i][0] = j;
              E[j][i][2] = *"W";				/* W = west */
        } else if((i > 0) && (j == 0)) {
              E[j][i][0] = i;
              E[j][i][1] = *"N";				/* N = north */
        } else {
          a = E[j][i-1][0] + 1;
          b = E[j-1][i][0] + 1;
          c = E[j-1][i-1][0];
          d = E[j-1][i-1][0] + 1;
              if(u[j-1] == v[i-1]) {
                  E[j][i][0] = min(a, b, c);
                  if (min(a,b,c) == a) {
                      E[j][i][1] = *"N";
                  }
                  if (min(a,b,c) == b) {
                      E[j][i][2] = *"W";
                  }
                  if (min(a,b,c) == c) {
                      E[j][i][3] = *"D";		/* D = diagonal */
                  }
              } else {
                  E[j][i][0] = min(a, b, d);
                  if (min(a,b,d) == a) {
                      E[j][i][1] = *"N";
                  }
                  if (min(a,b,d) == b) {
                      E[j][i][2] = *"W";
                  }
                  if (min(a,b,d) == d) {
                      E[j][i][3] = *"D";
                  }
              }
        }
      /*printf("\t%d(%c,%c,%c)", E[j][i][0],E[j][i][1],E[j][i][2],E[j][i][3]);*/
     }
    }
    /*printf("\n\n");*/
    printf("\t edist= %d \n \n",E[m][n][0]);			 /* Editdistanz Ausgabe */
    return E[m+1][n+1][0];
}

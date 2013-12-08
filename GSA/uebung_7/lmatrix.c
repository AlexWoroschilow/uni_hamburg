#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include <ctype.h>
#include "blosum62matrix.h"
#include "lmatrix.h"


/* score speichert den Score-Wert */
/* max_replacement, max_deletion, max_insertion - ob die eingehenden Kanten 
   replacement, deletion, insertion Kanten sind*/


int max(int a,int b,int c, int d) 
{
	if(a >= b && a >= c && a >= d) { 
		return a;
	} else if(b >= a && b >= c && b >= d) {
		return b;
	} else if( c >= a && c >= b && c >= d) {
	    return c;
	} else {
		return d;
	}
}


char *stringupper(char *s) 
{
  unsigned c;
  unsigned char *p = (unsigned char *)s;
  while (c == *p) {
    *p++ = toupper(c);
  }
  return (char *)p;
} 

/* Code von Aufgabe 7.1 */
int fillDPtableL(DPentry **L, int **scorematrix, int m, int n, char u[], char v[], int x)
{
  int i, j, a, b, c, d;
  
  for(i = 0; i < n+1; i++) {
    for(j = 0; j < m+1; j++) {
        L[j][i].max_insertion = false;
        L[j][i].max_deletion = false;
        L[j][i].max_replacement = false;
        L[j][i].score = 0;
        
      if(i == 0 || j == 0) {
        L[j][i].score = 0;
        
        /* Matrix L wird hier ausgedruckt: */
        printf("\t%ld", L[j][i].score);
        
      } else {  
        d = scorematrix[u[j]][v[i]];
        
        //printf("%d\n",d);
        //printf("%d\n",scorematrix[u[j]][v[i]]);
        
        a = L[j][i-1].score + x;
        b = L[j-1][i].score + x;
        c = L[j-1][i-1].score + d;
      
        L[j][i].score = max(0,a,b,c);
        
        /* Matrix L wird hier ausgedruckt: */
        printf("\t%ld", L[j][i].score);
         

        if (max(0,a,b,c) == a) { 
	  	  L[j][i].max_insertion = true;
	    }	  	  
	    if (max(0,a,b,c) == b) { 
	  	  L[j][i].max_deletion = true;
	  	}
	  	if (max(0,a,b,c) == c) { 
	  	  L[j][i].max_replacement = true;
	  	}   
    } 
  }
  printf("\n");
  }
return 0;
}



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include "blosum62matrix.h"


typedef struct DPentry {
  long score;
  bool max_replacement,
       max_deletion,
       max_insertion;
} DPentry;

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
  while (c = *p) {
    *p++ = toupper(c);
  }
} 


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



int main(int argc, char *argv[])
{
	/* get two strings u,v and insertion/deletion score x as parameters */
	char *u = argv[1];
	char *v = argv[2];	
	int x, i;

	/* initialize scorematrix for blosum62matrix function */
    int **scorematrix = malloc(CHAR_MAX * sizeof(int*));
	for(i=0; i< CHAR_MAX; i++) {
	  scorematrix[i] = malloc(CHAR_MAX * sizeof(int));
	}

	/* initialize matrix L */
	DPentry **L = malloc(CHAR_MAX * sizeof(int*));
	for(i=0; i< CHAR_MAX; i++) {
	  L[i] = malloc(CHAR_MAX * sizeof(DPentry));
	}
	
	/* get lengths of strings u and v */
	int m = strlen(u);		
	int n = strlen(v);
	
	/* convert strings to uppercase letters */
	stringupper(u);
	stringupper(v);	
	
	/* Überprüfen, ob zwei Kommandozeilenparameter eingegeben sind */
  	if(argc != 4 || (sscanf(argv[1], "%s", &*u)) != 1 || 
  	    (sscanf(argv[2], "%s", &*v)) != 1 ||
  	    (sscanf(argv[3], "%d", &x)) != 1) {
    printf("\tBitte zwei Sequenzen und ein Insertions/Deletions-Score eingeben\n");
    exit(EXIT_FAILURE);
    }

	/* fill the BLOSUM62 score matrix */
	blosum62matrix(scorematrix);

	/* fill matrix L */
	fillDPtableL(L, scorematrix, m, n, u, v, x);
		
	return(0);
}

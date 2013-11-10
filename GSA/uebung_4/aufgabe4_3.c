#include <stdio.h>                        /* use standard output routines */
#include <stdlib.h>                      /* use standard library functions */
#include <string.h>						/* include string library */

/* will need to use min macro to find minimum in fillDPtable*/
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })


int fillDPtable(int m,int n)
{

	int i, j;
	int u, v;

	int matrix[m+1][n+1];

    for(i = 0; i < n+1; i++) {
		for(j = 0; j < m+1; j++) {
			if( i == 0 && j == 0) {
          		matrix[i][j] = 0;          
         	} 
                        
                        
        	else if( i == 0 && j != 0) {
                matrix[j][i] = matrix[j-1][i] + 1;
           }
                        
            else if( i != 0 && j == 0) {
                matrix[j][i] = matrix[j][i-1] + 1;
           }
                        
            else {
                    
                if(u[i] == v[j]){	/* hier ist das Syntax falsch!! */
                	/* 'error: subscripted value is neither array nor pointer' */
                	/* wie kann ich das richtig machen?? */
                    
                	matrix[j][i] = min( matrix[j][i-1] + 1, min(matrix[j-1][i] + 1, matrix[j-1][i-1]));
                    	
                }
                	matrix[j][i] = min( matrix[j][i-1] + 1, min(matrix[j-1][i] + 1, matrix[j-1][i-1] + 1 ));
            }
       }
    }
    return matrix[m+1][n+1];
}


int main(int argc, char *argv[])
{
	/* ich will, dass u und v Strings sind, so dass ich die Längen finden kann */
	char *u = argv[1];
    char *v = argv[2];	
    
	/* get lengths of strings u and v */
	int m = strlen(u);		
	int n = strlen(v);
	
	/* Ausgabe: */
	printf("u= %s, v= %s \n edist= %d ", u, v, fillDPtable(m,n));
	
	return(EXIT_SUCCESS); /* in order to prevent "warning: control reaches end of non-void function" */
}

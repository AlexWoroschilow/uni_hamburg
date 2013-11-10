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

	int E[m+1][n+1];

    for(i = 0; i < n+1; i++) {
		for(j = 0; j < m+1; j++) {
			if( i == 0 && j == 0) {
          		E[i][j] = 0;          
         	} 
                        
                        
        	else if( i == 0 && j != 0) {
                E[j][i] = E[j-1][i] + 1;
           }
                        
            else if( i != 0 && j == 0) {
                E[j][i] = E[j][i-1] + 1;
           }
                        
            else {
                    
                if(u[i] == v[j]){	/* hier ist das Syntax irgendwie falsch!! */
                	/* 'error: subscripted value is neither array nor pointer' */
                	/* wie kann ich das richtig machen?? */
                    
                	E[j][i] = min( E[j][i-1] + 1, min(E[j-1][i] + 1, E[j-1][i-1]));
                    	
                }
                	E[j][i] = min( E[j][i-1] + 1, min(E[j-1][i] + 1, E[j-1][i-1] + 1 ));
            }
       }
    }
    return E[m+1][n+1];
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
	
	return fillDPtable(m,n); /* in order to prevent "warning: control reaches end of non-void function" */
}

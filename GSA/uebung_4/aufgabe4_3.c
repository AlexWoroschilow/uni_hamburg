#include <stdio.h>                        	/* use standard output routines */
#include <stdlib.h>                      	/* use standard library functions */
#include <string.h>				/* include string library */


int min(int a,int b,int c) 
{
	if(a <= b && a <= c) { 
		return a;
	}
	else if(b <= a && b <= c) {
		return b;
	}
	else {
		return c;
	}


}

 int fillDPtable(int m,int n, char u[], char v[])
 {
  int i, j;

  int E[m+1][n+1];
  printf("\n");
  
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
			if(u[j-1] == v[i-1]) {									
	  			E[j][i] = min((E[j][i-1] + 1), (E[j-1][i] + 1), E[j-1][i-1]);			
			} else {
				E[j][i] = min((E[j][i-1] + 1), (E[j-1][i] + 1), (E[j-1][i-1] + 1));
      		  }
      	}
    /*printf("\t%d", E[j][i]);*/
    }
  }
  printf("\n\n");
  /* Ausgabe: */
  printf("\t edist= %d \n \n",E[m][n]);
  return E[m+1][n+1];
 }


int main(int argc, char *argv[])
{
	/* ich will, dass u und v Strings sind, so dass ich die Längen finden kann */
	char *u = argv[1];
	char *v = argv[2];	
	
	/* Überprüfen, ob zwei Kommandozeilenparameter eingegeben sind */
  	if(argc != 3 || (sscanf(argv[1], "%s", &*u)) != 1 || (sscanf(argv[2], "%s", &*v)) != 1) {
    printf("\tBitte zwei Sequenzen angeben\n");
    exit(EXIT_FAILURE);
    }

    
	/* get lengths of strings u and v */
	int m = strlen(u);		
	int n = strlen(v);
	fillDPtable(m, n, u, v);
	
	/*printf("\tu = %s, v = %s, m = %d, n = %d \n\n", u, v, m, n); */
	
	return(0);
}

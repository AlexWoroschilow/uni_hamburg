/* GSA Aufgabe 5.2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define linelength 500 	/* must be >= maximum line length - line length of FASTA files is
										no longer than 120 characters
										but to do strcat must be maximum stringlength,
										which I have set to 500*/
#define maxlines 1000 		/* must be >= number of lines in FASTA file */



int read_fasta_file(int a, int b)		/* liest eine Sequenz im Multiple-FASTA-Format ein */
{
	char *seqs[2][50];			/* Eine feste maximale Anzahl von Sequenzen = 50 */
	int counter;
	counter = -1;
	char line[maxlines][linelength];
    FILE *f = NULL; 
    int i = 0;
    int numlines = 0;

    f = fopen("input.fasta", "r");
    while(fgets(line[i], linelength, f)) {			/* go through FASTA file line by line */
        line[i][strlen(line[i]) - 1] = '\0';		/* remove end-of-line \n from fgets */
        i++;     
    }
	numlines = i;

   for(i = 0; i < numlines; ++i) {		/* print fasta file line by line */
        printf("%s\n", line[i]);
    }
    printf("\n\n");
    
    
    seqs[1][counter]="cc";
    
    for(i = 0; i < numlines; ++i) { 
        if (line[i][0] == *">") {	
        	counter++;
			seqs[0][counter] = line[i];
        } else {
        	seqs[1][counter]= strcat(seqs[1][counter],line[i]);
        }
    }
	printf("\n\n\n%s\n\n\n",seqs[1][3]);
	return *seqs[a][b];
}


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

 int fillDPtable(int m,int n, char u[], char v[])
 {
  int i, j;
  int E[m+1][n+1];
  /*printf("\n");*/
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
    }
  }
  printf("\t edist= %d \n \n",E[m][n]);		/* Edit-Distanz ausgeben */
  return E[m+1][n+1];
 }


int main(void)
{
	
	int j, k;
	for (j=0;j<50;j++) {
		for (k=0;k<50;k++) {
			char *u = read_fasta_file(1,j);
			char *v = read_fasta_file(1,k);
			int m = strlen(u);				/* get lengths of strings u and v */
			int n = strlen(v);
			fillDPtable(m, n, u, v);
			/*printf("\tu = %s\nv = %s\n\n\n", u, v); */
		}
	}
	return(0);
}

  /* Aufgabe 4.1 GSA Uebungen */
  
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    a = 97, b = 98, o = 99
  } base;
typedef base seq[];
  

int main(int argc, char *argv[])
{
  int k, i, j; 
  int A[5][5];
  seq seq1 = {o, a, a, a, b, a};
  seq seq2 = {o, b, a, a, b, a};  
  printf("\tmc(%c%c%c, %c%c%c) = \n", seq1[1], seq1[2], seq1[3], seq2[1], seq2[2], seq1[3]);
  if(argc != 2 || (sscanf(argv[1], "%d", &k)) != 1) {
    printf("\tBitte Syntax beachten: ./afg41 <Substringlaenge>\n");
    exit(EXIT_FAILURE);
  }
  for(j = 0; j < 6; j++) {
    printf("\n");
    for(i = 0; i < 6; i++) {
      if((i == 0) || (j == 0)) {
	A[i][j] = 0;
      } else {
	A[i][j] = A[i-1][j-1];
	if(seq1[i] == seq2[j]) {
	  A[i][j] += 1;
	}
      }
      printf("\t%d", A[i][j]);
    }
  }
  printf("\n\n");
  for(i = 1; i <= 6 - k; i++){
    for(j = 1; j <= 6 - k; j++){
      printf("\tmc(%c%c%c, %c%c%c) = %d\n", seq1[i], seq1[i+1], seq1[i+2], seq2[j], seq2[j+1], seq1[j+2], (A[i+2][j+2] - A[(i+2)-k][(j+2)-k]));
    }
  }
  printf("\n");
  return(EXIT_SUCCESS);
}
  
  
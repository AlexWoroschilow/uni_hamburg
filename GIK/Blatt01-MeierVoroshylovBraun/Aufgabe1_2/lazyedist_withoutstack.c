// 
// GIK Uebungen Blatt 1
// 
// Aufgabe 1.2:
// Edit Distance Algorithm
// -lazy-
// 
//  Gruppe: Voroshylov, Meier, Braun
// 
//  Kommentar: Ich habe stundenlang an einer Loesung mit Stack ge-
//  feilt und es schliesslich aufgegeben um diese rekursive Loesung
//  zu implementieren, die meiner Meinung nach effizienter ist.
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int error(int mode, char *option) {
    
    if(mode == 1) {
        
        fprintf(stderr, "\n\tPlease note syntax: %s ", option);
        fprintf(stderr, "<p> <q>\n\n");
        return(0);

    } else if(mode == 2) {

        fprintf(stderr, "\n\tUnknown Error. Aborting...\n\n");
        abort();        

    } 

    return(0);
}


int calc_entry(char* p, char* q, int i, int j, int** edist) {

  if(i == 0 || j == 0) {

    if(i != 0) {

      edist[i][j] = i;

    } else if (j != 0) {

      edist[i][j] = j;

    } else {

      edist[i][j] = 0;
    }
  
  } else {

    edist[i][j] = calc_entry(p, q, i-1, j-1, edist);

    if(p[i-1] == q[j-1]) {

      edist[i][j] = edist[i-1][j-1];

    } else if(calc_entry(p, q, i-1, j, edist) < edist[i-1][j-1]) {

      edist[i][j] = edist[i-1][j] + 1;
    
    } else {

      calc_entry(p, q, i, j-1, edist);

      edist[i][j] = (edist[i-1][j-1] < edist[i][j-1] ? 
        edist[i-1][j-1] + 1 : edist[i][j-1] + 1);
    }
  }

  return edist[i][j];
}


void print_matrix(int x, int y, int** matrix) {

  int i, j;

  for(i=0; i<x; i++) {
    for(j=0; j<y; j++) {

      printf(" %d", matrix[i][j]);
    }

    printf("\n");
  }
}


int main(int argc, char* argv[]) {

  if(argc != 3) {
        
    error(1, argv[0]);
    exit(EXIT_FAILURE);
  }

  int i;

  char* p = malloc(strlen(argv[1]) * sizeof(char));
  char* q = malloc(strlen(argv[2]) * sizeof(char));

  strcpy(p, argv[1]);
  strcpy(q, argv[2]);

  int m = strlen(p);
  int n = strlen(q);

  int** edist = (int**) malloc((m+1) * sizeof(int*));

  for (i = 0; i < (m+1); i++) {
      
    edist[i] = (int*) malloc((n+1) * sizeof(int));
  }

  int distance = calc_entry(p, q, m, n, edist);

  print_matrix(m+1, n+1, edist);

  printf("%d\n", distance);

  return 0;
}
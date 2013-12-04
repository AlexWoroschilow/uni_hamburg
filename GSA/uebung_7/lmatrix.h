#ifndef LMATRIX
#define LMATRIX

typedef struct DPentry {
  long score;
  bool max_replacement,
       max_deletion,
       max_insertion;
} DPentry;


int max(int a,int b,int c, int d);

char *stringupper(char *s);

int fillDPtableL(DPentry **L, int **scorematrix, int m, int n, char u[], char v[], int x);





#endif

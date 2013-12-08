/* header fuer Aufgabe 8.3 by Felix Braun */


#ifndef EDTABCOLUMN
#define EDTABCOLUMN

typedef struct ELEMENT ELEMENT;

int getmin(int a, int b, int c);


void firstEDtabcolumn(int *col, int length);


int* nextEDtabcolumn(int *col, int length, char b, char *u);


ELEMENT* firstEDtabRcolumn(ELEMENT *rcol, int lengthu, int j0, char *u, char *v);


int nextEDtabRcolumn(ELEMENT *rcol, int j0, int lengthu, char b, char *u);


void evaluateallcolumns(int lengthu, int lengthv, char *u, char *v);


#endif
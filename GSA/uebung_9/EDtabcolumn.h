/* header fuer Aufgabe 9.1 by Felix Braun */


#ifndef EDTABCOLUMN
#define EDTABCOLUMN


typedef struct Element Element;


typedef struct Crosspoint Crosspoint;


int getminA(int a, int b, int c);


char getminB(int a, int b, int c);


void firstEDtabcolumn(int *col, int length);


void nextEDtabcolumn(int *col, int length, char b, char *u);


void firstEDtabRcolumn(Element *rcol, int lengthu, int j0, char *u, char *v);


int nextEDtabRcolumn(Element *rcol, int j0, int lengthu, char b, char *u);


void evaluateallcolumns(int lengthu, int lengthv, char *u, char *v);


int evaluatecrosspoints(Crosspoint *crosspoints, int j0, 
						int lengthu, int lengthv, char *u, char *v);


#endif
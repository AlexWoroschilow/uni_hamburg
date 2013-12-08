#ifndef MATRIX
#define MATRIX

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "alignment.h"

typedef struct DPentry {
  long score;
  bool replace;
  bool remove;
  bool insert;
} DPentry;

int min(int a,int b,int c);


int cost (char * char1, char * char2 );

void matrix_fill_score (DPentry ** matrix, int i, int j, char char1, char char2);

DPentry ** matrix_fill (char * seq1, char * seq2);

int cost_gap (DPentry entry1, DPentry entry2, int gap_start, int gap_extend);

void traceback (Alignment * alignment, DPentry ** matrix, int n, int m, int gap_start, int gap_extend);

#endif

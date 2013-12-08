#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "alignment.h"
#include "matrix.h"



int min(int a,int b,int c)
{
    return a > b ? (b > c ? c : b) : (a > c ? c : a);
}

int cost (char * char1, char * char2 ) {
    if (char1 != NULL && char2 != NULL) {
        if(*char1 == *char2) {
            return 0;
        }
    }
    return 1;
}


DPentry ** matrix_init (int len1, int len2)
{
    int i;

    DPentry ** matrix = malloc(len1 * sizeof( int* ));
    for(i=0; i< len1; i++) {
        matrix[i] = malloc(len2 * sizeof( DPentry ));
    }

    return matrix;
}


void matrix_fill_score (DPentry ** matrix, int i, int j, char char1, char char2) {


    int a, b, c;
    int minimum;

    if(i == 0 && j == 0) {
      matrix[i][j].score = 0;
      return;
    }

    if(i == 0) {
        matrix[i][j].score = j;
        matrix[i][j].insert = true;
        return;
    }

    if (j == 0) {
        matrix[i][j].score = i;
        matrix[i][j].remove = true;
        return;
    }

    a = matrix[i-1][j].score + cost(NULL, &char2);
    b = matrix[i][j-1].score + cost(&char1, NULL);
    c = matrix[i-1][i-1].score + cost(&char1, &char2);
    minimum = min(a, b, c);

    if(minimum == a) {
      matrix[i][j].remove = true;
    }
    if (minimum == b) {
      matrix[i][j].insert = true;
    }
    if (minimum == c) {
      matrix[i][j].replace = true;
    }
    matrix[i][j].score = minimum;
    return ;
}

DPentry ** matrix_fill (char * seq1, char * seq2)
{
    int i, j;
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);

    DPentry ** matrix = matrix_init(len1, len2);

    for(i=0; i< len1; i++) {
      for(j=0; j< len2; j++) {
          matrix_fill_score (matrix, i, j, seq1[i], seq2[j]);

      }
      fprintf(stdout, "\n");
    }

    return matrix;
}

int cost_gap (DPentry entry1, DPentry entry2, int gap_start, int gap_extend)
{
    if(entry1.remove) {
        if(entry2.remove) {
            return entry2.score + gap_extend; // gap extend
        } else if(entry2.insert) {
            return entry2.score + gap_start; // gap start
        }
    } else if (entry1.insert) {
        if(entry2.insert) {
            return entry2.score + gap_extend; // gap extend
        } else if(entry2.remove) {
            return entry2.score + gap_start; // gap start
        }
    } else if (entry1.replace) {
        if(entry2.insert || entry2.remove) {
            return entry2.score + gap_start; // gap start
        }
    }
    return entry2.score; // replacement
}



void traceback (Alignment * alignment, DPentry ** matrix, int n, int m, int gap_start, int gap_extend)
{
    int a, b, c;
    int minimum;

    if(!n || !m) {
        return;
    }

    int k, l;

    k = !n ? 0 : n-1;
    l = !m ? 0 : m-1;

    a = cost_gap(matrix[k][m], matrix[n][m], gap_start, gap_extend); // remove
    b = cost_gap(matrix[n][l], matrix[n][m], gap_start, gap_extend); // insert
    c = cost_gap(matrix[k][l], matrix[n][m], gap_start, gap_extend); // replace

    minimum = min(a, b, c);

    if(minimum == a) {
      alignment_fill(alignment, 1, 'D');
      return traceback(alignment, matrix, k, m, gap_start, gap_extend);
    }
    if (minimum == b) {
      alignment_fill(alignment, 1, 'I');
      return traceback(alignment, matrix, n, l, gap_start, gap_extend);
    }
    if (minimum == c) {
      alignment_fill(alignment, 1, 'R');
      return traceback(alignment, matrix, k, l, gap_start, gap_extend);
    }
}

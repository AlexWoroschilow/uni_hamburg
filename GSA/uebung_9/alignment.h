#ifndef ALIGNMENT
#define ALIGNMENT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>


typedef struct Multiedit {

    int count;
    char type;

} Multiedit;


typedef struct Alignment {

    int alglen;
    int seq1len;
    int seq2len;

    Multiedit ** editop;

    char * seq1;
    char * seq2;

} Alignment;

Alignment * alignment_new (char * seq1, char * seq2);

void alignment_fill(Alignment * alignment, int count, char type);


int alignment_show(Alignment *alg);

#endif

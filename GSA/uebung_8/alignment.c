#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "alignment.h"


Alignment * alignment_new (char * seq1, char * seq2) {
    Alignment * alignment = malloc(sizeof(* alignment));
    alignment->seq1 = seq1;
    alignment->seq2 = seq2;
    alignment->seq1len = strlen(seq1);
    alignment->seq2len = strlen(seq2);
    alignment->alglen = 0;
    return alignment;
}

void alignment_fill(Alignment * alignment, int count, char type) {
    assert((type == 'I' || type == 'D' || type == 'R'));
    alignment->alglen++;
    alignment->editop = realloc(alignment->editop, alignment->alglen * sizeof(Multiedit *));
    Multiedit * multiedit = malloc(sizeof(* multiedit));
    multiedit->count = count;
    multiedit->type = type;
    alignment->editop[alignment->alglen - 1] = multiedit;
}


int alignment_show(Alignment *alg) {

    int i, j;
    int u = 0;
    int v = 0;
    int x = 0;
    char *equal = (malloc(alg->alglen * sizeof(char)));

    printf("\n\t");

    for(i = 0; i < alg->alglen; i++) {              /* Wiedergabe erste Zeile */

        if(alg->editop[i]->type == 'R') {
            for(j = 0; j < alg->editop[i]->count; j++) {
                printf("%c", alg->seq1[u]);
                if(alg->seq1[u] == alg->seq2[v]) {
                    equal[x] = '|';
                } else {
                    equal[x] = ' ';
                }
                u++; v++; x++;
            }

        } else if(alg->editop[i]->type == 'I') {
            for(j = 0; j < alg->editop[i]->count; j++) {
                printf("-");
                equal[x] = ' ';
                v++; x++;
            }

        } else if(alg->editop[i]->type == 'D') {
            for(j = 0; j < alg->editop[i]->count; j++) {
                printf("%c", alg->seq1[u]);
                equal[x] = ' ';
                u++; x++;
            }
        }

        if(i == alg->alglen - 1) {
            printf("\n");
            u = 0;
            v = 0;
        }
    }

    printf("\t%s\n", equal);                       /* Wiedergabe zweite Zeile */

    printf("\t");

    for(i = 0; i < alg->alglen; i++) {              /* Wiedergabe dritte Zeile */

        if(alg->editop[i]->type == 'R') {
            for(j = 0; j < alg->editop[i]->count; j++) {
                printf("%c", alg->seq2[v]);
                u++; v++;
            }

        } else if(alg->editop[i]->type == 'D') {
            for(j = 0; j < alg->editop[i]->count; j++) {
                printf("-");
                u++;
            }

        } else if(alg->editop[i]->type == 'I') {
            for(j = 0; j < alg->editop[i]->count; j++) {
                printf("%c", alg->seq2[v]);
                v++;
            }
        }

        if(i == alg->alglen - 1) {
            printf("\n\n");
        }
    }

    return(EXIT_SUCCESS);
}

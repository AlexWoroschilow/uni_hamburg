/* alignments.c */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "alignments.h"



//typedef enum {
//  R = 'R', I = 'I', D = 'D'
//} edit;
//  
//typedef enum {
//  a = 'a', c = 'c', g = 'g', t = 't'
//} base;

typedef struct multiedit {

    int count;
    /*edit*/char type;

} multiedit;

typedef struct alignment {

    int alglen;
    int seq1len;
    int seq2len;

    multiedit *editop;

    /*base*/char *seq1;
    /*base*/char *seq2;

} alignment;


alignment alignment_new(char seq1[], char seq2[], char align[]) {

    int i;
    int j = 0;
    int k = 0;
    char zwabl[10] = "";
    
    alignment *newalg = malloc(sizeof(*newalg));
     
    (*newalg).alglen = 0;

    for(i = 0; align[i] != '\0'; i++) {
        if(isdigit(align[i])) {
            continue;    
        } else {
            newalg->alglen++;
        }
    }

    newalg->seq1len = strlen(seq1);
    newalg->seq2len = strlen(seq2);

    newalg->seq1 = malloc(newalg->seq1len * sizeof(char));
    strcpy(newalg->seq1, seq1);

    newalg->seq2 = malloc(newalg->seq2len * sizeof(char));
    strcpy(newalg->seq2, seq2);

    newalg->editop = malloc(newalg->alglen * sizeof(multiedit));

    for(i = 0; align[i] != '\0'; i++) {
        if(i == 0) {
            newalg->editop[j].type = align[i];
        } else if(isdigit(align[i])) {
            zwabl[k] = align[i];
            k++;
            zwabl[k] = '\n';
            sscanf(zwabl,"%d", &newalg->editop[j].count);
        } else {
            k = 0;
            j++;
            newalg->editop[j].type = align[i];
        }
    }

    return(newalg);
}


int alignment_add_operation(alignment *alg, int count, char type) {

    if(alg->editop[alg->alglen].type == type) {

        alg->alglen += count;

    } else {
        
        struct multiedit e;

        e.type = type;
        e.count = count;

        alg->editop[(*alg).alglen] = e;
        alg->alglen++;
    
    }
    

    return(0);
}


int alignment_show(alignment alg) {
    
    int i, j;
    int u = 0;
    int v = 0;
    int x = 0;
    char *equal = (malloc(alg.alglen * sizeof(char)));

    printf("\n\t");

    for(i = 0; i < alg.alglen; i++) {              /* Wiedergabe erste Zeile */
        
        if(alg.editop[i].type == 'R') {
            for(j = 0; j < alg.editop[i].count; j++) {
                printf("%c", alg.seq1[u]);
                if(alg.seq1[u] == alg.seq2[v]) {
                    equal[x] = '|';
                } else {
                    equal[x] = ' ';
                }
                u++; v++; x++;
            }

        } else if(alg.editop[i].type == 'I') {
            for(j = 0; j < alg.editop[i].count; j++) {
                printf("-");
                equal[x] = ' ';
                v++; x++;
   	        }

        } else if(alg.editop[i].type == 'D') {
            for(j = 0; j < alg.editop[i].count; j++) {
                printf("%c", alg.seq1[u]);
                equal[x] = ' ';
                u++; x++;
            }
        }

        if(i == alg.alglen - 1) {
            printf("\n");
            u = 0;
            v = 0;
        }
    }    
        
    printf("\t%s\n", equal);                       /* Wiedergabe zweite Zeile */

    printf("\t");

    for(i = 0; i < alg.alglen; i++) {              /* Wiedergabe dritte Zeile */
        
        if(alg.editop[i].type == 'R') {
            for(j = 0; j < alg.editop[i].count; j++) {
                printf("%c", alg.seq2[v]);
                u++; v++;
            }

        } else if(alg.editop[i].type == 'D') {
            for(j = 0; j < alg.editop[i].count; j++) {
                printf("-");
                u++;
            }

        } else if(alg.editop[i].type == 'I') {
            for(j = 0; j < alg.editop[i].count; j++) {
                printf("%c", alg.seq2[v]);
                v++;
            }
        }

        if(i == alg.alglen - 1) {
            printf("\n\n");
        }
    }

    return(EXIT_SUCCESS); 
}


int alignment_evalcost(alignment alg) {

    int i, j;
    int u, v;
    int counter = 0;

    for(i = 0; i < alg.alglen; i++) {
        
        if(alg.editop[i].type == 'R') {
            for(j = 0; j < alg.editop[i].count; j++) {
                if(alg.seq1[u] == alg.seq2[v]) {
                    u++; v++;
                } else {
                    counter++;
                    u++; v++;
                }
            }
            
        } else if(alg.editop[i].type == 'I') {
            counter += alg.editop[i].count;
            v += alg.editop[i].count;

        } else if(alg.editop[i].type == 'D') {
            counter += alg.editop[i].count;
            u += alg.editop[i].count;
        }

    }

    return(counter);
}


void alignment_delete(alignment *alg) {

    if(alg != NULL) {
    
    free(alg->editop);

    free(alg->seq1);
    free(alg->seq2);
    
    free(alg);
    
    }
    
}

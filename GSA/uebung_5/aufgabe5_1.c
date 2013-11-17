/* Aufgabe 5.1 GSA Uebungen - Erstellen einer Struktur zum speichern und bearbeiten von Alignments */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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

    multiedit editop[1000]/* = (multiedit *) malloc(alglen * (sizeof(int) + sizeof(edit)))*/;

    /*base*/char seq1[1000] /*= (base *) malloc(seq1len * sizeof(base))*/;
    /*base*/char seq2[1000] /*= (base *) malloc(seq2len * sizeof(base))*/;

} alignment;


alignment alignment_new(char seq1[], char seq2[], char align[]) {

    int i;
    int j = 0;
    char test1[] = "";

    alignment newalg;
    
    newalg.alglen = strlen(align) / 2;
    newalg.seq1len = strlen(seq1);
    newalg.seq2len = strlen(seq2);
    
    *newalg.seq1 = *seq1;
    *newalg.seq2 = *seq2;

    for(i = 0; i < newalg.alglen; i += 2) {
        newalg.editop[j].type = align[i];
        j++;
    }

    j = 0;

    for(i = 1; i < newalg.alglen; i += 2) {
        test1[0] = align[i];
        sscanf(test1,"%d", &newalg.editop[j].count);
        j++;
    }

    return(newalg);
}


/*int alignment_add_replacement(struct alignment *alg, int count) {

    multiedit* cache;
    multiedit element;

    element.type = "R";
    element.count = count;

    cache = (base *) malloc(sizeof(*alg->editop))
        cache = *alg->editop;

    free(*alg->editop);

    *alg->editop = (base *) malloc(sizeof(*alg->editop) + sizeof(element))
    *alg->editop[sizeof(*alg->editop)/sizeof(*alg->editop[0])] = element;

    return 1;
}


int alignment_add_insertion(struct alignment *alg, int count) {

    multiedit* cache;
    multiedit element;

    element.type = "I";
    element.count = count;

    cache = (char *) malloc(sizeof(*alg->editop))
        cache = *alg->editop;

    free(*alg->editop);

    *alg->editop = (base *) malloc(sizeof(*alg->editop) + sizeof(element))
    *alg->editop[sizeof(*alg->editop)/sizeof(*alg->editop[0])] = element;

    return 1;
}


int alignment_add_deletion(struct alignment *alg, int count) {

    multiedit* cache;
    multiedit element;

    element.type = "D";
    element.count = count;

    cache = (char *) malloc(sizeof(*alg->editop))
        cache = *alg->editop;

    free(*alg->editop);

    *alg->editop = (char *) malloc(sizeof(*alg->editop) + sizeof(element))
    *alg->editop[sizeof(*alg->editop)/sizeof(*alg->editop[0])] = element;

    return 1;
}
*/

int alignment_show(alignment alg) {
    
    int i, j;
    int u = 0;
    int v = 0;
    char equal[alg.alglen + 1];

       
    for(i = 0; i < alg.alglen; i++) {              /* Wiedergabe erste Zeile */
        
        if(alg.editop[i].type == 'R') {
            for(j = 0; j < alg.editop[i].count; j++) {
                printf("%c", alg.seq1[u]);
                if(alg.seq1[u] == alg.seq2[v]) {
                    equal[i] = '|';
                } else {
                    equal[i] = ' ';
                }
                u++; v++;
            }

        } else if(alg.editop[i].type == 'I') {
            for(j = 0; j < alg.editop[i].count; j++) {
                printf("-");
                equal[i] = ' ';
                v++;
   	        }

        } else if(alg.editop[i].type == 'D') {
            for(j = 0; j < alg.editop[i].count; j++) {
                printf("%c", alg.seq1[u]);
                equal[i] = ' ';
                u++;
            }
        }

        if(i == alg.alglen - 1) {
            printf("\n");
            u = 0;
            v = 0;
        }
    }    
        
    printf("%s\n", equal);                         /* Wiedergabe zweite Zeile */


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
            printf("\n");
        }
    }

    return(0); 
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


/*int alignment_delete(alignment alg) {

    alg.seq1len = 0;
    alg.seq2len = 0;
    alg.alglen = 0;

    free(alg.editop);

    free(alg.seq1);
    free(alg.seq2);
  
    return(0);
}
*/

int main() {

    int i;
    int j = 0;
    char test1[] = "";

    char *align = "R7I2R2D1R3I1R3";

    char *seq1 = "acgtagatatatagat";
    char *seq2 = "agaaagaggtaagaggga";
    
    alignment alg;
    
    alg.alglen = strlen(align) / 2;
    alg.seq1len = strlen(seq1);
    alg.seq2len = strlen(seq2);

    *alg.seq1 = *seq1;
    *alg.seq2 = *seq2;

    for(i = 0; i < alg.alglen; i += 2) {
        alg.editop[j].type = align[i];
        j++;
    }

    j = 0;

    for(i = 1; i < alg.alglen; i += 2) {
        test1[0] = align[i];
        sscanf(test1,"%d", &alg.editop[j].count);
        j++;
    }
    
    return(EXIT_SUCCESS);
}

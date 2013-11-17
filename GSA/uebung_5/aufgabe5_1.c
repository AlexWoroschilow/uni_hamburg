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
    char zwabl[] = "";

    alignment newalg;
    
    newalg.alglen = strlen(align) / 2;
    newalg.seq1len = strlen(seq1);
    newalg.seq2len = strlen(seq2);

    for(i = 0; i < newalg.seq1len; i++) {
        newalg.seq1[i] = seq1[i];
    }


    for(i = 0; i < newalg.seq2len; i++) {
        newalg.seq2[i] = seq2[i];
    }
    

    for(i = 0; i < (newalg.alglen * 2); i += 2) {
        newalg.editop[j].type = align[i];
        j++;
    }

    printf("\n");

    j = 0;

    for(i = 1; i < (newalg.alglen * 2); i += 2) {
        zwabl[0] = align[i];
        sscanf(zwabl,"%d", &newalg.editop[j].count);
        j++;
    }
    
    return(newalg);
}


int alignment_add_replacement(struct alignment *alg, int count) {

    struct multiedit e;

    e.type = 'R';
        e.count = count;

        (*alg).editop[(*alg).alglen] = e;
        (*alg).alglen++;

    return 1;
}


int alignment_add_insertion(struct alignment *alg, int count) {

    struct multiedit e;

    e.type = 'I';
        e.count = count;

        (*alg).editop[(*alg).alglen] = e;
        (*alg).alglen++;

    return 1;
}


int alignment_add_deletion(struct alignment *alg, int count) {

    struct multiedit e;

    e.type = 'D';
        e.count = count;

        (*alg).editop[(*alg).alglen] = e;
        (*alg).alglen++;

    return 1;
}


int alignment_show(alignment alg) {
    
    int i, j;
    int u = 0;
    int v = 0;
    int x = 0;
    char equal[alg.alglen + 1];

    printf("\t");

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

    int evalcost; 

    char *align = "R7I2R2D1R3I1R3";

    char *seq1 = "acgtagatatatagat";
    char *seq2 = "agaaagaggtaagaggga";
    
    alignment alg = alignment_new(seq1, seq2, align);

    alignment_show(alg);

    evalcost = alignment_evalcost(alg);

    printf("\tCosts: %d\n\n", evalcost);

    printf("\tadding one deletion...\n");
    alignment_add_deletion(&alg, 1);
    alignment_show(alg);

    printf("\tadding one insertion...\n");
    alignment_add_insertion(&alg, 1);
    alignment_show(alg);

    printf("\tadding one replacement...\n");
    alignment_add_replacement(&alg, 1);
    alignment_show(alg);

    return(EXIT_SUCCESS);
}

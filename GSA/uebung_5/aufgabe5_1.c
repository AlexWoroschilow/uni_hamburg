/* Aufgabe 5.1 GSA Uebungen - Erstellen einer Struktur zum speichern und bearbeiten von Alignments */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
  R = 'R', I = 'I', D = 'D'
} edit;
  
typedef enum {
  a = 'a', c = 'c', g = 'g', t = 't'
} base;

typedef struct multiedit {

    int count;
    edit type;

} multiedit;

typedef struct alignment {

    int alglen;
    int seq1len;
    int seq2len;

    multiedit* editop;

    base* seq1;
    base* seq2;

} alignment;


/**
 * Create new Alignment
 *
 */
alignment alignment_new(base *seq1, base *seq2) {

	alignment structure;
	
	structure.seq1 = (base *) malloc(sizeof(seq1) * sizeof(char));
	structure.seq2 = (base *) malloc(sizeof(seq2) * sizeof(char));
	structure.seq1len = sizeof(seq1);
	structure.seq1len = sizeof(seq2);

	return structure;
}


int alignment_add_replacement(int count) {
	multiedit edit;

}
//
//
//int alignment_add_insertion() {
//
//}
//
//
//int alignment_add_deletion() {
//
//}
//
//
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




int alignment_delete(alignment alg) {

    alg.seq1len = 0;
    alg.seq2len = 0;
    alg.alglen = 0;

    free(alg.editop)

    free(alg.seq1);
    free(alg.seq2);
  
    return(0);
}


int main() {

    alignment alg;
//
//    alg.seq1len = ;
//    alg.seq2len = ;
//    alg.alglen = ;
    
//    alg.editop = {}

    alg.seq1 = {a, c, g, t, a, g, a, t, a, t, a, t, a, g, a, t};
    alg.seq2 = {a, g, a, a, a, g, a, g, g, t, a, a, g, a, g, g, g, a};

    return(EXIT_SUCCESS);
}

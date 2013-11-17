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

typedef struct alignment {

	int alglen;
	int seq1len;
	int seq2len;

	int* index;
	edit* operations;

	base* seq1;
	base* seq2;

} alignment;

/**
 * Create new Alignment
 *
 */
alignment alignment_new(base *seq1, base *seq2, char *alg) {

	alignment structure;

	structure.seq1len = strlen(seq1);
	structure.seq1len = strlen(seq2);
	structure.alglen = strlen(alg);

	structure.seq1 = seq1;
	structure.seq2 = seq2;

	return structure;
}
//
//
//int alignment_add_replacement() {
//
//}
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
//int alignment_show(alignment alg) {
//
//    int i, j;
//    int u = 0;
//    int v = 0;
//    char equal[alg.alglen + 1];
//
//    for(i = 0; i < alg.alglen; i++) {              /* Wiedergabe erste Zeile */
//
//        if(alg.operations[i] == 'R') {
//            for(j = 0; j < alg.index[i]; j++) {
//                printf("%c", alg.seq1[u]);
//                if(alg.seq1[u] == alg.seq2[v]) {
//                    equal[i] = '|';
//                } else {
//                    equal[i] = ' ';
//                }
//                u++; v++;
//            }
//
//        } else if(alg.operations[i] == 'I') {
//            for(j = 0; j < alg.index[i]; j++) {
//                printf("-");
//                equal[i] = ' ';
//                v++;
//   	        }
//
//        } else if(alg.operations[i] == 'D') {
//            for(j = 0; j < alg.index[i]; j++) {
//                printf("%c", alg.seq1[u]);
//                equal[i] = ' ';
//                u++;
//            }
//        }
//
//        if(i == alg.alglen - 1) {
//            printf("\n");
//            u = 0;
//            v = 0;
//        }
//    }
//
//    printf("%s\n", equal);                         /* Wiedergabe zweite Zeile */
//
//
//    for(i = 0; i < alg.alglen; i++) {              /* Wiedergabe dritte Zeile */
//
//        if(alg.operations[i] == 'R') {
//            for(j = 0; j < alg.index[i]; j++) {
//                printf("%c", alg.seq2[v]);
//                u++; v++;
//            }
//
//        } else if(alg.operations[i] == 'D') {
//            for(j = 0; j < alg.index[i]; j++) {
//                printf("-");
//                u++;
//            }
//
//        } else if(alg.operations[i] == 'I') {
//            for(j = 0; j < alg.index[i]; j++) {
//                printf("%c", alg.seq2[v]);
//                v++;
//            }
//        }
//
//        if(i == alg.alglen - 1) {
//            printf("\n");
//        }
//    }
//
//    return(0);
//}
//
//
//int alignment_evalcost(alignment alg) {
//
//    int i, j;
//    int u, v;
//    int counter = 0;
//
//    for(i = 0; i < alg.alglen; i++) {
//
//        if(alg.operations[i] == 'R') {
//            for(j = 0; j < alg.index[i], j++) {
//                if(alg.seq1[u] == alg.seq[v]) {
//                    u++; v++;
//                } else {
//                    counter++;
//                    u++; v++;
//                }
//            }
//
//        } else if(alg.operations[i] == 'I') {
//            counter += alg.index[i];
//            v += alg.index[i];
//
//        } else if(alg.operations[i] == 'D') {
//            counter += alg.index[i];
//            u += alg.index[i];
//        }
//
//    }
//
//    return(counter);
//}

//int alignment_delete(alignment alg) {
//
//    free(alg.seqlen);
//    free(alg.alglen);
//
//    free(alg.operations);
//    free(alg.index);
//
//    free(alg.seq1);
//    free(alg.seq2);
//
//    return(0);
//}
//

int main(int argc, char *argv[]) {

	base *seq1 = "acgtagatatatagat";
	base *seq2 = "agaaagaggtaagaggga";
	char *alg = "R7I2R2D1R3I1R3";

	alignment_new(seq1, seq2, alg);

	fprintf(stdout, "%s\n", alg);

	return EXIT_SUCCESS;
}

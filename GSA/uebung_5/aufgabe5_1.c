/* Aufgabe 5.1 GSA Uebungen - Erstellen einer Struktur zum speichern und bearbeiten von Alignments */


#include <stdio.h>
#include <stdlib.h>



typedef enum {
  R = 'R', I = 'I', D = 'D'
} edit;
  
typedef enum {
  a = 'a', c = 'c', g = 'g', t = 't'
} base;


typedef struct alignment {

  int seqlen;
  int alglen;

  edit operations[];
  int index[];

  base seq1[seqlen];
  base seq2[seqlen];

} alignment;


int alignment_new(base seq1[], base seq2[]) {
  
}


int alignment_add_replacement() {
 
}


int alignment_add_insertion() {
 
}


int alignment_add_deletion() {
  
}

int alignment_show() {

}

int alignment_evalcost() {
  
}


int alignment_delete() {
  
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alignment.h"

typedef struct Crosspoint {
  
  int i; // i - position in matrix
  int c; // cost value
  char t; // type operation type (R,I,D)

} Crosspoint;

typedef struct CrosspointCollection {

    int count; // count of elements in array
    Crosspoint * collection; // array with crosspoints

} CrosspointCollection;


/**
 * Test funktion to create cross-point array
 * @ return struct CrosspointCollection
 */
CrosspointCollection * test_create_crosspoint_array (char * v, char * u) {
  int len_v = ((int) strlen(v));
  int len_u = ((int) strlen(u));
  
  CrosspointCollection * crosspointcollection = malloc(sizeof(CrosspointCollection *));
  
  // die Länge der längsten Zeichenkette ist immer die Länge des Arrays
  crosspointcollection->count = (len_v > len_u ? len_v : len_u);
  crosspointcollection->collection = malloc(crosspointcollection->count * sizeof(Crosspoint *));
  
  return crosspointcollection;
}

/**
 * Test funktion to fill crosspoint struct
 * @return void
 */
void test_fill_crosspoint_array (CrosspointCollection * array, int j, int i, int c, char t) {  
  Crosspoint * temp = malloc(sizeof(Crosspoint *));
  temp->i = i; // set i - position in matrix
  temp->c = c; // set cost value
  temp->t = t; // set operation type
  array->collection[j] = *temp; // store Crosspoint elemen in j-position
}


/**
 * Aufgabe 9.2 reconstruct alignment using crosspoint array
 * @return Alignment pointer
 */ 
Alignment * reconstructalignment (CrosspointCollection * crosspoints, char * v, char * u) {
  
  int j;
   
  Alignment * alignment = alignment_new (v, u); // initialize new algnment object
  
  for (j = 0; j < crosspoints->count; j++) { 
    // fill Edit operation to alignment, crosspoint array have to be sorted
    alignment_fill(alignment, 1, crosspoints->collection[j].t);
  }  
  
  return alignment;
}



int main(int argc, char *argv[]) {
  
  char * v = "aggaggtag";
  char * u = "agaagtag";
  
  CrosspointCollection * crosspoints = test_create_crosspoint_array(v, u);
  
  test_fill_crosspoint_array(crosspoints, 0, 0, 0, 'R');
  test_fill_crosspoint_array(crosspoints, 1, 1, 0, 'D');
  test_fill_crosspoint_array(crosspoints, 2, 2, 0, 'R');
  test_fill_crosspoint_array(crosspoints, 3, 3, 0, 'R');  
  test_fill_crosspoint_array(crosspoints, 4, 4, 0, 'I');
  test_fill_crosspoint_array(crosspoints, 5, 5, 0, 'R');
  test_fill_crosspoint_array(crosspoints, 6, 6, 0, 'D');
  test_fill_crosspoint_array(crosspoints, 7, 7, 0, 'R');
  test_fill_crosspoint_array(crosspoints, 8, 8, 0, 'R');
  test_fill_crosspoint_array(crosspoints, 9, 9, 0, 'R');
  
  Alignment * alignment = reconstructalignment(crosspoints, v, u);
    
  alignment_show(alignment);
  
  
  return EXIT_SUCCESS;
}
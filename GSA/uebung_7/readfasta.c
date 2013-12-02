#include <assert.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 

typedef struct { 
  char *header, 
       *sequence; 
} FASTAentry; 

FASTAentry* read_fasta(const char *filename, unsigned long *num_of_entries) 
{ 
  unsigned long num_of_sequences = 0; 
  char currentchar = '\0'; 
  FILE *infile; 
  
  bool firstseq = true, 
       firstline = true;
  
  char buffer[BUFSIZ]; 
  unsigned long lastpos = 0; 
  
  FASTAentry *entries, 
             *currententry; 
             
  assert(filename && num_of_entries); 
  
  /* determine number of sequences */ 
  infile = fopen(filename, "r"); 
  while (EOF != (currentchar = fgetc(infile))) { 
    if (currentchar == '>') 
      num_of_sequences++; 
  } 
  *num_of_entries = num_of_sequences; 
  if (num_of_sequences == 0) 
    return NULL; 
  entries = currententry = calloc(num_of_sequences, sizeof (FASTAentry)); 

  /* read input file line by line */ 
  rewind(infile); 
  while (fgets(buffer, BUFSIZ, infile) != NULL) { 
    char itembuf[BUFSIZ]; 
    if (sscanf(buffer, ">%s", itembuf) == 1) { 
      /* we have read a header */ 
     if (!firstseq) { 
       /* this header starts a new sequence, advance entry pointer */ 
       currententry++; 
       firstline = true; 
     } else firstseq = false; 
        /* allocate and store strings */ 
        currententry->header = calloc(strlen(itembuf)+1, sizeof (char)); 
        strncpy(currententry->header, itembuf, strlen(itembuf)); 
     } else if (sscanf(buffer, "%s", itembuf) == 1) { 
        /* we have read a sequence */ 
       if (firstline) {  
        /* if this is the first line, just allocate and store */  
         currententry->sequence = calloc(strlen(itembuf) + 1, sizeof (char));    
         strncpy(currententry->sequence, itembuf, strlen(itembuf)); 
         lastpos = strlen(currententry->sequence); 
         firstline = false; 
     } else { 
       /* otherwise */ 
       currententry->sequence = realloc(currententry->sequence, 
       (lastpos + strlen(itembuf)+1) * 
       sizeof (char)); 
       strncpy(currententry->sequence + lastpos, itembuf, strlen(itembuf)); 
       lastpos += strlen(itembuf); 
     } 
    } 
  } 
  fclose(infile); 
  return entries; 
} 


void delete_fasta(FASTAentry *entries, unsigned long num_of_entries) 
{
  unsigned long i; 
  assert(entries); 
  
  for (i = 0; i < num_of_entries; i++) { 
    free(entries[i].header); 
    free(entries[i].sequence); 
  } 
  free(entries); 
} 



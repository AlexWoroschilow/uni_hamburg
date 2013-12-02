#ifndef ALIGNMENTS
#define ALIGNMENTS

typedef struct { 
  char *header, 
       *sequence; 
} FASTAentry; 


FASTAentry* read_fasta(const char *filename, unsigned long *num_of_entries)

void delete_fasta(FASTAentry *entries, unsigned long num_of_entries)


#endif

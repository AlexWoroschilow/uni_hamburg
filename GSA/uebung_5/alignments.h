/* alignments.h */


#ifndef ALIGNMENTS
#define ALIGNMENTS

//typedef enum edit;
//  
//typedef enum base;

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


alignment alignment_new(char seq1[], char seq2[], char align[]);


int alignment_add_operation(alignment *alg, int count, char type);


int alignment_show(alignment alg);


int alignment_evalcost(alignment alg);


void alignment_delete(alignment *alg);

#endif

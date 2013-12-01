/* GSA Uebungen 7, Aufgabe 3, Felix Braun */


#include <stdio.h>         /* use standard output routines */
#include <stdlib.h>        /* use standard library functions */
#include <string.h>        /* include string library */


typedef struct ELEMENT {                /* Struktur der Matrixwert */

    unsigned int value;                 /* Tatsaechlicher Distanzwert */        
    unsigned int origin;                /* Ursprung des partiellen Alignments */

} ELEMENT;


char getmin(int a, int b, int c) {      /* Gibt wieder welche Operation durchgefuehrt wird */
    
        if(a <= b && a <= c) {

                return('R');            /* Replacement */

        } else if(b <= a && b <= c) {

                return('I');            /* Insertion */

        } else {

                return('D');            /* Deletion */

        }
}


int fehler(int mode, char *option) {
    
    if(mode == 1) {
        
        fprintf(stderr, "\n\tPlease note syntax: %s ", option);
        fprintf(stderr, "<number of errors> <search pattern> <sequence/input file>\n\n");
        return(0);

    } else if(mode == 2) {

        fprintf(stderr, "\n\tUnknown Error. Aborting...\n\n");
        abort();        

    } else if(mode == 3) {

        fprintf(stderr, "\n\tPlease chose a number of errors smaller than ");
        fprintf(stderr, "the length of your search pattern.\n\n");        

    }
    
    return(0);
}

void output(int o, int e, char *p, char *t) {

    int i;

    printf("\tmatch ends at %d with alignment length %d on t, i.e. ", e + 1, e - o + 1);

    for(i = o; i <= e; i++) {

        printf("%c", t[i]);

    }

    printf(" matches %s\n", p);

}


void calcMatrix(char *p, char *t, int k) {

    ELEMENT *col1 = malloc((strlen(p) + 1) * sizeof(ELEMENT));
    ELEMENT *col2 = malloc((strlen(p) + 1) * sizeof(ELEMENT));

    int i, j;

    printf("\n");

    for(i = 0; i <= strlen(t); i++) {
        
        free(col1);
        col1 = col2;
        col2 = malloc((strlen(p) + 1) * sizeof(ELEMENT));


        for(j = 0; j <= strlen(p); j++) {


            if(j == 0) {
                
                col2[j].value = 0;
                col2[j].origin = 0 - 1;

            } else if(i == 0 && j != 0) {

                col2[j].value = col2[j-1].value + 1;
                col2[j].origin = 0 - 1;

            } else {

                switch(getmin(col1[j-1].value + (p[j-1] == t[i-1] ? 0 : 1),
                col1[j].value + 1, col2[j-1].value + 1)) {

                    case 'R': 
                    col2[j].value = col1[j-1].value + (p[j-1] == t[i-1] ? 0 : 1);
                    col2[j].origin = col1[j-1].origin;
                    // printf("%d, ", col2[j].origin);
                    break;

                    case 'I': 
                    col2[j].value = col1[j].value + 1;
                    col2[j].origin = col1[j].origin;
                    // printf("%d, ", col2[j].origin);
                    break;

                    case 'D': 
                    col2[j].value = col2[j-1].value + 1;
                    col2[j].origin = col2[j-1].origin;
                    // printf("%d, ", col2[j].origin);
                    break;

                    default: fehler(2, " ");

                }

            }

            if(j == 1 && i > 0) {

                col2[j].origin = i - 1;
                // printf("%d, ", col2[j].origin);
                    
            }

            if(j == strlen(p) && col2[j].value <= k) {

                output(col2[j].origin, i - 1, p, t);

            }

        }

    }

    printf("\n");

}



int main(int argc, char *argv[]) {
    
    if(argc != 4) {
        
        fehler(1, argv[0]);
        exit(EXIT_FAILURE);
    }
 
    FILE* f;
    int k;
    char *p = malloc(strlen(argv[2]) * sizeof(char));
    char *t;
    
 
    if(!(sscanf(argv[1], "%d", &k))) {

        fehler(1, argv[0]);
        exit(EXIT_FAILURE);
    }
    
    strcpy(p, argv[2]);

    if(k >= strlen(p)) {

        fehler(3, " ");
        exit(EXIT_FAILURE);

    }
    
    
    f = fopen(argv[3], "r");
    
    if(f == NULL) {
        
        t = malloc(strlen(argv[3]) * sizeof(char) + 1);
        strcpy(t, argv[3]);
          
    } else {
        
        fseek(f, 0, SEEK_END);
        t = malloc(ftell(f) * sizeof(char) + 1);
        fseek(f, 0, SEEK_SET);

        fscanf (f, "%s", t);
        
        fclose(f);
        
    }

    calcMatrix(p, t, k);
    
    return(EXIT_SUCCESS);
}
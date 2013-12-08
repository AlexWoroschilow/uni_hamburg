/* GSA Uebungsblatt 8, Aufgabe 2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>


typedef struct Counter { 
    unsigned int a, 
                 c,
                 t,
                 g;
} Counter;


typedef struct Multimenge { 
    unsigned int a, 
                 c,
                 t,
                 g;
} Multimenge;


void output(int startpos, char *p, int k) {

    int i;

    for(i = startpos; i <= startpos+k-1; i++) {
        printf("%c", p[i]);
    }

    printf(" an Position %d\n",startpos);
}



int window(char *p, int k, Multimenge S) 
{

    char first,
         second,
         third,
         fourth;
    Counter count;
    int i;
    int startpos;
    
    //printf("S(a) = %d \n",S.a);
    //printf("S(c) = %d \n",S.c);
    //printf("S(t) = %d \n",S.t);
    //printf("S(g) = %d \n",S.g);
    //printf("\n");
    
    /* Initialize counters */
    count.a = 0;
    count.c = 0;
    count.g = 0;
    count.t = 0;

    /* Initialize window */
    first = 'x';
    second = 'x';
    third = 'x';
    fourth = 'x';

    
    for (i=0; i <= strlen(p)-1; i++) {
    
        first = second;
        second = third;
        third = fourth;
        fourth = p[i];
        
        
        //printf("first = %c \n",first);
        //printf("second = %c \n",second);
        //printf("third = %c \n",third);
        //printf("fourth = %c \n",fourth);

        
        
        
        if (fourth == 'a') {
            count.a ++;
        } else if (p[i] == 'c') {
            count.c ++;
        } else if (p[i] == 't') {
            count.t ++;
        } else if (p[i] == 'g') {
            count.g ++;
        } else {
            printf("DNA Sequenz: bitte nur mit a, c, t, g\n");
            
        }
    
        //printf("count.a = %d \n",count.a);
        //printf("count.c = %d \n",count.c);
        //printf("count.t = %d \n",count.t);
        //printf("count.g = %d \n",count.g);
        //printf("i=%d \n",i);
        
    

            
        if (count.a == S.a && 
                   count.c == S.c && 
                   count.g == S.g && 
                   count.t == S.t) {
            
            /* and reset counter because continuing with for-loop */
            startpos = i-(k-1);      
            output(startpos, p, k);
            //printf("startpos = %d\n",startpos);

        }
            
            /* Reset counter corresponding to the string element that will no longer be
            in the window once first = second, etc. */
            
            if (p[i-(k-1)] == 'a') {
                count.a --;
            } else if (p[i-(k-1)] == 'c') {
                count.c --;
            } else if (p[i-(k-1)] == 't') {
                count.t --;
            } else if (p[i-(k-1)] == 'g') {
                count.g --;
            }
    
    }

    return 0;
}



int main(int argc, char *argv[]) {
    
    if(argc != 2) {
        
        printf("Bitte DNA Sequenz als Parameter eingeben\n");
        exit(EXIT_FAILURE);
    }
 
    char *p = malloc(strlen(argv[1]) * sizeof(char));
    
    /* As defined in the instructions, k = |S| */
    int k = 4;
    Multimenge S;
    /* Define S as in example given in the Uebungsblatt */
    S.a = 2;
    S.c = 1;
    S.g = 0;
    S.t = 1;
    
    // may be necessary to convert sequence to all lowercase letters first

    strcpy(p, argv[1]);
    assert(p);


    window(p, k, S);
        
    return(EXIT_SUCCESS);
}

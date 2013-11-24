#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef enum 
{
    A = 0, R, N, D, C, Q, E, G, H, I, L, K, M, F, P, S, T, W, Y, V, B, Z, X
} AS;

typedef struct SCORE 
{
    signed int matrix[23][23];
} SCORE;


char read(char text[], char *file)
{
    FILE *datei;
    datei = fopen(file, "r");
    
    char *teststring = "   A  R  N  D  C  Q  E  G  H  I  L  K  M  F  P  S  T  W  Y  V  B  Z  X";
    int i;

    if(!(fscanf (datei, "%2109c", text))) 
    {
        fprintf(stderr, "\tIncorrect input.\n");
        abort();
    }

    text[2109] = '\0';

    fclose(datei);
    
    for(i = 3; i < 70; i += 3)
    {
        if(teststring[i] != text[i])
        {
            fprintf(stderr, "\tIncorrect input.\n");
            abort();            
        }
    }

    // printf("%s\n", text);

    return *text;
}


SCORE convert(char text[])
{
    SCORE score;
    int i;
    int x = 0; int y = 0;
    char zwAbl[4];
    zwAbl[3] = '\0';

    for(i = 74; i < strlen(text); i += 3) 
    {    
        zwAbl[0] = text[i-2];
        zwAbl[1] = text[i-1];
        zwAbl[2] = text[i];

        if(!(sscanf(zwAbl, "%d", &score.matrix[x][y])) || !(isdigit(text[i])))
        {
            fprintf(stderr, "\tIncorrect input.\n");
            abort();
        }
        
        x++;

        if(x % 23 == 0) 
        {
            y++;
            x = 0; 
            i += 2;
        }
    }    

    return score;
}


int get_element(SCORE score, AS i, AS j)
{
    return score.matrix[i][j];
}


int main(int argc, char *argv[])
{
    char *text = malloc(2110 * sizeof(char));
    char *file;
    SCORE score;
    
    if (argc != 2 ) {
        fprintf(stderr, "\tPlease note syntax: %s <path to file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    file = argv[1];

    *text = read(text,file);

    score = convert(text);

    free(text);

    printf("\n\tData converted.\n\n");
    printf("\tExample scores:\n");
    printf("\tI -> G = %d\n",get_element(score, I, G));
    printf("\tL -> W = %d\n",get_element(score, L, W));
    printf("\tD -> D = %d\n",get_element(score, D, D));
    printf("\tF -> X = %d\n",get_element(score, F, X));
    printf("\n");
    
    return(EXIT_SUCCESS);
}




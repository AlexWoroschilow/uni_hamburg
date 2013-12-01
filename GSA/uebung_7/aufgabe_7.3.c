#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * get weight for char
 * @return int
 */
int g (char zeichen)
{
    switch (zeichen) {
        case 'a': // as is in the exercise, for "a" always 1
            return 1;
        case 'g': // as is in the exercise, for "g" always 3
            return 3;
    }
    return 2; // as is in the exercise, for "c" and "t" always 2
}

/*
 *Get all substrings with required char weight
 * @return void
 */
void sol (char *sequenz, int max)
{
    int i;
    int length = 0;
    int position = 0;
    int gewicht = 0;

    for(i = 0; length++, (i < ((int) strlen(sequenz))); i++) {

        gewicht += g(sequenz[i]);

        if(gewicht >= max) {

            if(gewicht == max) {
                printf("\t(%d, %d)\n", (position+1), length);
            }

            i = position++;
            length = 0;
            gewicht = 0;
        }
    }
}



int main (int argc, char *argv[])
{
    char *string1 = "acgtagctc";

    sol(string1, 9);


    return EXIT_SUCCESS;
}

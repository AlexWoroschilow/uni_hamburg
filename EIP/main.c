#include <stdio.h>


int main(void)
{
    char variable[254];

    while ( 1 ) {

        printf(">> Enter integer value: ");
        // add a space to skip whitespace (!)
        if (scanf(" %s", &variable)) {
            printf(">> Value ist integer: %s\n", variable);
            continue;
        }
    }
    return 0;
}


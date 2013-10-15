#include <stdio.h>
#include <string.h>

int main() {
    char variable;

    while ( 1 ) {
        printf(">> Enter integer value:");
        // add a space to skip whitespace (!)
        if (scanf(" %c", &variable)) {
            printf(">> Value ist integer: %c\n", variable);
            continue;
        }
    }

    return (0);
}

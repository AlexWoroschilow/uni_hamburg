#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMOFBITS 32 /* number of bits in bitvector */

/*
 * revert sring
 * return void
 */
void srtrev(char *str)
{
    int i, length, last_pos;

    length = strlen(str);
    last_pos = length-1;

    for(i = 0; i < length / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[last_pos - i];
        str[last_pos - i] = tmp;
    }
}

/*
 * Convert int to bit vector
 * @return void
 */
void decimal2bitvector(char *bitvector, unsigned long int n) {

    int k = n, l;

    while (k > 0) {

        l = k % 2;
        k = k - l;
        k = k / 2;

        strcat(bitvector, (l ? "1" : "0"));
    }
    srtrev(bitvector);
}

/**
 * Convert bit vector to int
 * @return int
 */
unsigned int bitvector2decimal(const char *bitvector) {
    int x;
    int y = NUMOFBITS;

    for (x = 0; x < NUMOFBITS; x++) {

        printf("%d\t%d\n", x, y--);
    }


    return 12;
}

/*
 * Programm enterpoint
 * @return end success
 */
int main(int argc, char *argv[]) {

    unsigned long int n;
    char *bitvector = (char *) malloc(NUMOFBITS * 8 + 8);


	if (argc == 2) {
        if (sscanf(argv[1], "%ld", (unsigned long int*) (&n))) {
            decimal2bitvector(bitvector, n);
            printf("%ld\t%s\n", n, bitvector);
			return EXIT_SUCCESS;
		}

        if (sscanf(argv[1], "%s", bitvector)) {
			printf("%s\n", bitvector);
            n = bitvector2decimal(bitvector);
            printf("%ld\t%s\n", n, bitvector);
			return EXIT_SUCCESS;
		}
	}

	return EXIT_FAILURE;
}

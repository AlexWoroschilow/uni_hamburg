#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int quersumme = 0;
	long int eingabe = 0, temp = 0;

	if(argc == 2) {
		if(sscanf(argv[1], "%ld", &eingabe)) {
			temp = eingabe;
			while (temp != 0) {
				quersumme = quersumme + ( temp % 10 );
				temp = temp / 10;
			}
		}
	}

	printf("Quersumme von %ld ist %d \n", eingabe, quersumme); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

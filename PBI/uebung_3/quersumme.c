#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char *argv[])
{
	int temp = 0;
	int eingabe = 0;
	int quersumme = 0;

	if(argc == 2) {
		if(sscanf(argv[1], "%d", &eingabe)) {
			temp = eingabe;
			while (temp != 0) {
				quersumme = quersumme + ( temp % 10 );
				temp = temp / 10;
			}
		}
	}

	printf("Quersumme von %d ist %d \n", eingabe, quersumme); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

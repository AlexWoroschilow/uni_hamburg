#include <stdio.h>
#include <stdlib.h>

long int ggt(long int n, long int m) {
	long int g;

	if (m > n) {
		g = n;
		n = m;
		m = g;
	}

	g = m;

	while (g) {
		if (!(n % g)) {
			if (!(m % g)) {
				return g;
			}
		}
		g--;
	}
	return 1;
}


int main(int argc, char *argv[]) {

	long int n, m;

	if (argc == 3) {
		if (sscanf(argv[1], "%ld", &n)) {
			if (sscanf(argv[2], "%ld", &m)) {
				fprintf(stdout, "ggt von %ld and %ld ist %ld \n", n, m, ggt(n, m));
				return EXIT_SUCCESS;
			}
		}
	}
	fprintf(stderr, "Geben sie bitte zwei Zahlen ein...\n");
	return EXIT_FAILURE;
}

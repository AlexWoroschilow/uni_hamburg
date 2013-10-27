#include <stdio.h>
#include <malloc.h>

long int alignsR (int var1, int var2, int *counter)
{
	*counter = *counter +1;
	if(var1 == 0 || var2 == 0) {
		return 1;
	}
	return alignsR(var1-1, var2, counter) + alignsR(var1, var2-1, counter) + alignsR(var1-1, var2-1, counter);
}

long int alignsI (int var1, int var2, int *counter)
{
	int i, j;
	int n, m;
	int x;

	n = var1 + 1;
	m = var2 + 1;

	int matrix[16][16];

	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if( i == 0 || j == 0) {
				matrix[i][j] = 1;
			} else {
				*counter = *counter + 3;
				matrix[i][j] = matrix[i-1][j] + matrix[i][j-1] + matrix[i-1][j-1];
			}
		}
	}

	return matrix[var1][var2];
}


int main (int argc, char *argv[])
{
	int counterR = 0, counterI = 0;

	int var1, var2, result;

	if(argc != 3) {
		printf("Falshe Eingabe!");
		return(0);
	}

	var1 = atoi(argv[1]);
	var2 = atoi(argv[2]);

	if(var1 > 15 || var2 > 15) {
		printf("Falshe Eingabe! x <= 15 !");
		return(0);
	}

	printf("n: %d, m: %d Result: %d ", var1, var2, alignsI(var1, var2, &counterI));
	printf("(%d accesses)\n", counterI);

	printf("n: %d, m: %d Result: %d ", var1, var2, alignsR(var1, var2, &counterR));
	printf("(%d calls)\n", counterR);

	return(0);
}

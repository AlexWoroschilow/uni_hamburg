#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void output(int zahl) {
	if (zahl <= UCHAR_MAX) {
		if (zahl >= 7 && zahl <= 13) {
			switch (zahl) {
			case 7:
				printf("%3d\t\\a", zahl);
				return;
			case 8:
				printf("%3d\t\\b", zahl);
				return;
			case 9:
				printf("%3d\t\\t", zahl);
				return;
			case 10:
				printf("%3d\t\\n", zahl);
				return;
			case 11:
				printf("%3d\t\\v", zahl);
				return;
			case 12:
				printf("%3d\t\\f", zahl);
				return;
			case 13:
				printf("%3d\t\\r", zahl);
				return;
			}
		} else if (zahl >= 33 && zahl <= 126) {
			printf("%3d\t%-4c", zahl, zahl);
			return;
		}
		printf("%3d\t\\%-4d", zahl, zahl);
	}
	return;
}

int main(int argc, char *argv[]) {
	int x = 0;
	for (x = 0; x < UCHAR_MAX / 4; x++) {
		output(x);
		printf("\t");
		output(UCHAR_MAX / 4 + x);
		printf("\t");
		output(UCHAR_MAX / 4 * 2 + x);
		printf("\t");
		output(UCHAR_MAX / 4 * 3 + x);
		printf("\t");
		output(UCHAR_MAX / 4 * 4 + x);
		printf("\t");
		printf("\n");
	}

	return 0;
}

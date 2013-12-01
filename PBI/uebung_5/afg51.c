#include <stdio.h>
#include <stdlib.h>

typedef enum {
	YANUAR = 1,
	FEBRUAR = 2,
	MAERZ = 3,
	APRIL = 4,
	MAI = 5,
	JUNI = 6,
	JULI = 7,
	AUGUST = 8,
	SEPTEMBER = 9,
	OKTOBER = 10,
	NOVEMBER = 11,
	DECEMBER = 12
} Month;

/**
 * get day count for  each monat
 * @return int
 */
int month_n_days_array(Month month) {

	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month <= sizeof(days) / sizeof(days[0])) {
		if (&days[month] != NULL ) {
			return days[month];
		}
	}
	return 0;
}

/**
 * get day count for  each monat
 * @return int
 */
int month_n_days(Month month) {

	switch (month) {
	case YANUAR:
		return 31;
	case FEBRUAR:
		return 28;
	case MAERZ:
		return 31;
	case APRIL:
		return 30;
	case MAI:
		return 31;
	case JUNI:
		return 30;
	case JULI:
		return 31;
	case AUGUST:
		return 31;
	case SEPTEMBER:
		return 30;
	case OKTOBER:
		return 31;
	case NOVEMBER:
		return 30;
	case DECEMBER:
		return 31;
	default:
		return 0;
	}
}

int main(int argc, char *argv[]) {

	int days;
	Month month;

	if (argc == 2) {
		if (sscanf(argv[1], "%d", (unsigned int*) (&month))) {
			if ((days = month_n_days(month))) {
				printf(">> Count of days without array: %d\n", days);
				return EXIT_SUCCESS;
			}
		}
	}
	printf(">> Falshe eingabe, bitter enter eine zahl von 1 bis 12...\n");
	return EXIT_FAILURE;
}

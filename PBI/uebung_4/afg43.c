#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Get "." position from end of string
 * @return int
 */
int dot_rabstand(const char *haystack, const char *needle) {
   char *position = strstr(haystack, needle);
   if (position) {
      return strlen(haystack) - (position - haystack);
   }
   return -1;
}

/**
 * Compare two strings
 * @return int
 */
int compare(const void * a, const void * b) {

    int pos1;
    int pos2;

    const char **ia = (const char **)a;
    const char **ib = (const char **)b;

    pos1 = dot_rabstand(*ia, ".");
    pos2 = dot_rabstand(*ib, ".");

    if(pos1 > pos2) {
    	return -1;
    } else if (pos1 < pos2) {
    	return 1;
    }

	return 0;
}


int main(int argc, char *argv[]) {
	int i;
	char temp[20];

	char* *keys = malloc(argc * sizeof(char*));
	for(i=1; i < argc; i++) {
		char *string = malloc((int)strlen(argv[i]) * sizeof(char));
		if (sscanf(argv[i], "%s", string)) {
			keys[i-1] = string;
		}
	}

	qsort(keys, argc-1, sizeof(char *), compare);

	int test = 4;
	for(i=0; i < argc-1; i++) {
		sprintf(temp, "%%.%dlf\n", test);
		fprintf(stdout, temp, keys[i]);
	}

	return EXIT_SUCCESS;
}

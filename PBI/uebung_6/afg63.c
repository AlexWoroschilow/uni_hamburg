#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*
 * TODO: return als string, in human-readable format
 * bis freitag
 */
unsigned long int get_system_memory_total ()
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}




int main (int argc, char *argv[])
{
    printf("sizeof(char)=%ld bytes\n", sizeof(char));
    printf("sizeof(short)=%ld bytes\n", sizeof(short));
    printf("sizeof(int)=%ld bytes\n", sizeof(int));
    printf("sizeof(long)=%ld bytes\n", sizeof(long));
    printf("sizeof(char *)=%ld bytes\n", sizeof(char *));
    printf("sizeof(short *)=%ld bytes\n", sizeof(short *));
    printf("sizeof(int *)=%ld bytes\n", sizeof(int *));
    printf("sizeof(long *)=%ld bytes\n", sizeof(long *));
    printf("sizeof(void *)=%ld bytes\n", sizeof(void *));
    printf("sizeof(float *)=%ld bytes\n", sizeof(float *));
    printf("sizeof(double *)=%ld bytes\n", sizeof(double *));
    printf("sizeof(long long *)=%ld bytes\n", sizeof(long long *));
    printf("sizeof(long double *)=%ld bytes\n", sizeof(long double *));

    printf("%ld\n", get_system_memory_total ());


    return EXIT_SUCCESS;
}

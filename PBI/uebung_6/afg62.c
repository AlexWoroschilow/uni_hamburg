#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


/*
 *
 *
 */
void int_sort2 (int *numptr1, int *numptr2)
{
    int temp;
    if(*numptr1 > *numptr2) {
        temp = *numptr1;
        *numptr1 = *numptr2;
        *numptr2 = temp;
    }
}

/*
 *
 *
 */
void int_sort3 (int *numptr1, int *numptr2, int *numptr3)
{
    int_sort2(numptr1, numptr2);
    int_sort2(numptr1, numptr3);
    int_sort2(numptr2, numptr3);
}


/*
 *
 * erste Möglichkeit
 * falls notwendig ist, alle zahlen als parameters übergeben
 * aber niemand macht so was
 */
void int_sort_x ( int num, ... )
{
    int x;
    va_list arguments;

    /* Initializing arguments to store all values after num */
    va_start ( arguments, num );

    // in dieser Schleife nehmen wir jedes argument und
    // machen weiter was nötig ist
    for ( x = 0; x < num; x++ ) {
        va_arg ( arguments, int );
    }

    // Cleans up the list
    va_end ( arguments );
}

/*
 * normale weise sortiert man ein Array
 * deshalb wurde zweite möglichkeit mit dem Array implementiert
 */
void int_sort_y ( int *num)
{

}



int main (int argc, char *argv[])
{

    int num1;
    int num2;
    int num3;


    num1 = 3;
    num2 = 2;
    num3 = 1;

    printf("num1=%d\tnum2=%d\n", num1, num2);
    int_sort2(&num1, &num2);
    printf("num1=%d\tnum2=%d\tnum3=%d\n", num1, num2, num3);

    int_sort3(&num1, &num2, &num3);


    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

/*
 * Funktion to compare two integers
 * return int
 */
int max_2_int (int int1, int int2)
{
    return int1 >= int2 ? int1 : int2;

}

/*
 * Compare fier integers
 * return int
 */
int max_4_int (int int1, int int2, int int3, int int4)
{
    return max_2_int(max_2_int(int1, int2), max_2_int(int3, int4));
}


/*
 * Programm enterpoint
 * return end success
 */
int main(int argc, char *argv[]) {


    max_2_int (5, 3);
    max_2_int (5, 12);
    max_2_int (1, 324);

    max_4_int(2,3,4,5);
    max_4_int(5,6,3,2);
    max_4_int(6,6,4,8);
    max_4_int(8,9,12,1);
    max_4_int(2,677,123123,335);

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "linkedlist.h"


int main (int argc, char *argv[])
{

    List * testlist;

    testlist = list_new();
    list_append(testlist, 2);
    list_append(testlist, 3);
    list_append(testlist, 3);
    list_append(testlist, 6);
    list_append(testlist, 12);

    list_show(testlist);

    list_delete_el(testlist, list_first(testlist));

    list_ordered_insert(testlist, 4);
    list_ordered_insert(testlist, 3);
    list_ordered_insert(testlist, 3);
    list_ordered_insert(testlist, 10);
    list_ordered_insert(testlist, 2);
    list_ordered_insert(testlist, 16);

    fprintf(stdout, "found 4?: %d\n", list_search(testlist, 4));
    fprintf(stdout, "found 20?: %d\n", list_search(testlist, 20));

    list_show(testlist);

    list_delete(testlist);

    return EXIT_SUCCESS;
}

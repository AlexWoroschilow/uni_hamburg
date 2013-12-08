#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define bool int
#define true 1
#define false 0


typedef struct List_el {
    void * prev;
    void * next;
    unsigned long value;
} List_el;

typedef struct List {
    void * last;
    void * first;
} List;

/*
 * Create new list
 * set alle attributes als NULL
 */
List * list_new (void);

/*
 * Get current element value
 * return unsigned long
 */
unsigned long list_el_get_value (const List_el * element);

/*
 * Return ein Zeiger auf das erste Element
 * im list oder NULL
 */
List_el * list_first (const List * list);

/*
 * Return ein Zeiger auf das letzte Element
 * im list oder NULL
 */
List_el * list_last (const List * list);

/*
 * Return einen Zeiger
 * auf den Nachfolger des Elements
 */
List_el * list_el_next (const List_el * element);

/*
 * Return einen Zeiger
 * auf den Vorgänger des Elements
 */
List_el * list_el_prev (const List_el * element);

/*
 * Append element into list
 */
void list_append (List * list, unsigned long value);

/*
 * Show element content
 */
void list_el_show (const List_el * element);

/*
 * Show list content
 */
void list_show (const List * list);

/*
 * Delete current element from list
 */
void list_delete_el (List * list, List_el * element);

/*
 * Remove list content
 * complete
 */
void list_delete (List * list);

/*
 * Insert value by oder
 */
void list_ordered_insert (List * list, unsigned long value);

/*
 * Search value in list
 */
bool list_search (const List * list, unsigned long value);


#endif

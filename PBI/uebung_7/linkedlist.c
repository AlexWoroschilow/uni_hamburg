#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "linkedlist.h"


/*
 * Create new list
 * set alle attributes als NULL
 */
List * list_new (void) {
    List * list = malloc(sizeof(* list));
    list->last = NULL;
    list->first = NULL;
    return list;
}

/*
 * Get current element value
 * return unsigned long
 */
unsigned long list_el_get_value (const List_el * element) {
    return element->value;
}

/*
 * Return ein Zeiger auf das erste Element
 * im list oder NULL
 */
List_el * list_first (const List * list) {
    return (List_el *) list->first;
}

/*
 * Return ein Zeiger auf das letzte Element
 * im list oder NULL
 */
List_el * list_last (const List * list) {
    return (List_el *) list->last;
}

/*
 * Return einen Zeiger
 * auf den Nachfolger des Elements
 */
List_el * list_el_next (const List_el * element) {
    return (List_el *) element->next;
}

/*
 * Return einen Zeiger
 * auf den Vorgänger des Elements
 */
List_el * list_el_prev (const List_el * element) {
    return (List_el *) element->prev;
}

/*
 * Append element into list
 */
void list_append (List * list, unsigned long value) {

    assert((list != NULL));

    List_el * element = malloc(sizeof(* element));
    element->value = value;
    element->next = NULL;
    element->prev = NULL;

    if(list->first == NULL) {
        list->first = (void *) element;
    }

    if(list->last != NULL) {
        ((List_el *)list->last)->next = (void * ) element;
        element->prev = list->last;
    }

    list->last = (void * ) element;
}

/*
 * Show element content
 */
void list_el_show (const List_el * element) {
    assert((element != NULL));
    fprintf(stdout, "%ld", list_el_get_value(element));
}

/*
 * Show list content
 */
void list_show (const List * list) {
    assert((list != NULL));

    List_el * element = list_first(list);
    list_el_show(element);
    while ( (element =  list_el_next(element)) ) {
        fprintf(stdout, ",");
        list_el_show(element);
    }
    fprintf(stdout, "\n");
}

/*
 * Delete current element from list
 */
void list_delete_el (List * list, List_el * element) {
    assert((list != NULL));
    assert((element != NULL));

    List_el * prev = list_el_prev(element);
    List_el * next = list_el_next(element);

    if(prev != NULL) {
        prev->next = next;
    }

    if(next != NULL) {
        next->prev = prev;
    }

    if(list->first == element) {
        list->first = prev;
        if(list->first == NULL) {
            list->first = next;
        }
    }

    if(list->last == element) {
        list->last = next;
        if(list->last == NULL){
            list->last = prev;
        }
    }

    free(element);
}


/*
 * Remove list content
 * complete
 */
void list_delete (List * list) {
    assert((list != NULL));
    List_el * element;
    while ( (element = list_first(list)) ) {
        list_delete_el(list, element);
    }
    free(list);
}

/*
 * Insert value by oder
 */
void list_ordered_insert (List * list, unsigned long value) {
    assert((list != NULL));

    List_el * current = list_first(list);
    if ( list_el_get_value(current) < value) {
        while ( (current = list_el_next(current)) ) {
            if ( list_el_get_value(current) > value) {
                break;
            }
        }
    }

    if(current == NULL) {
        list_append(list, value);
        return ;
    }

    List_el * element = malloc(sizeof(* element));
    element->value = value;
    element->next = NULL;
    element->prev = NULL;

    List_el * prev = list_el_prev(current);
    List_el * next = list_el_next(current);

    if(prev == NULL && next == NULL) {
        list->last = element;
        list->first = element;
    } else if (prev == NULL && next != NULL) {
        list->first = element;
        current->prev = element;
        element->next = current;
    } else if (prev != NULL && next == NULL) {
        prev->next = element;
        current->prev = element;
        element->prev = prev;
        element->next = current;
    } else if (prev != NULL && next != NULL) {
        prev->next = element;
        current->prev = element;
        element->prev = prev;
        element->next = current;
    }
}

/*
 * Search value in list
 */
bool list_search (const List * list, unsigned long value) {
    List_el * current = list_first(list);
    if ( list_el_get_value(current) != value) {
        while ( (current = list_el_next(current)) ) {
            if ( list_el_get_value(current) == value) {
                return 1;
            }
        }
    } else {
        return 1;
    }
    return 0;
}

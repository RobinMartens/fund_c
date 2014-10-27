#ifndef FUND_LIST_H
#define FUND_LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef error_t const char*;

typedef struct Link {
	void *val;
	struct Link *next;
}

typedef struct List {
	struct Link *first;	
	struct Link *last;
}

// allocate new emtpy list
List *list_new(error_t *err);

// free all nodes and free list
// does NOT free pointers stored in list
void *list_delete(List *list, error_t *err);

// appends element to the end of the list
List *list_append(List *list, void *val, error_t *err);

// returns last element from list (without removing it)
void *list_peek(error_t *err);

// returns last element from list and removes it
void *list_poll(List *list, error_t *err);

// inserts element at indicated location of list
List *list_insert(List *list, void *val, int idx, error_t *err);



// setters
List *list_append_array(List *list, void **arr, int len, error_t *err);

List *list_splice_list(List *base, List *insert, int idx);


List *list_from_array(void **val, int len, error_t *err);
void **list_to_arry(List *list, error_t, *err);

// getters
void *list_get(List *list, int idx, error_t *err);

void *list_clear(List *list);
void *list_remove(List *list);

// misc
int *list_length(error_t *err);

// map function over list and discard results
void *list_map_void(void(*f)(*void));

// map function over list and store result in new list
void *list_map_copy(void(*f)(*void));

// map function over list and store results inplacd
void *list_map_mod(void(*f)(*void));

void *list_find(int(*f)(*void));

void list_print(List *list);

#endif // FUND_LIST_H

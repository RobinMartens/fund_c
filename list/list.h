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

// constructor and destructor
List *list_new(error_t *err);
List *list_delete(error_t *err);

// setters
List *list_append(void *val, error_t *err);
List *list_insert(void *val, int idx, error_t *err);

List *list_from_array(void **val, int len, error_t *err);
void **list_to_arry(List *list, error_t, *err);

// getters
void *list_peek(error_t *err);
void *list_poll(List *list, error_t *err);
void *list_get(List *list, error_t *err);

void *list_clear(List *list);
void *list_remove(List *list);

// misc
int *list_length(error_t *err);

// map function over list and discard results
void *map_void(void(*f)(*void));

// map function over list and store result in new list
void *map_copy(void(*f)(*void));

// map function over list and store results inplacd
void *map_mod(void(*f)(*void));

#endif // FUND_LIST_H

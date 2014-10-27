#include"list.h"

#include<stdlib.h>
#include<assert.h>

List *list_new(error_t *err){
	err && *err = NULL;
	List *list = malloc(sizeof(List));
	if(list == NULL){
		err && *err = "cannot allocate new list, malloc returned NULL";
		return NULL;
	}
	list->first = NULL;
	list->last = NULL;
	return list;
}

void list_delete(List *list, error_t *err){
	err && *err = NULL;
	Link *cur = list->first;
	while(cur != NULL){
		Link *remove = cur;
		cur = cur->list;
		free(remove);
	}
	free(list);
	return;
}

List *list_append(List *list, void *val, error_t *err){
	err && *err = NULL;	
	Link *new_link = malloc(sizeof(Link));	
	if(new_link == NULL){
		err && *err = "cannot allocate new link, malloc returned NULL";
		return list;
	}
	new_link->val = val;
	new_link->next = NULL;
	new_link->prev= list->last;
	if(list->last == NULL){
		assert(list->first == NULL);
		list->first = new_link;
	}else{
		list->last->next = new_link;
	}
	list->last = new_link;
	return list;
}

void *list_peek(List *list, error_t *err){
	err && *err = NULL;
	Link *last = list->last;
	if(last == NULL){
		err && *err = "cannot peek at head of list, list is empty"; 
		return NULL;
	}
	return last->val;
}

void *list_poll(List *list, error_t *err){
	err && *err = NULL;
	Link *last = list->last;
	if(last == NULL){
		err && *err = "cannot poll list, list is empty";
		return NULL;
	}
	void *val = last->val;
	list->last = last->prev;
	free(last);
	return val;
}






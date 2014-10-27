#include"list.h"
#include<stdio.h>
#include<stdlib.h>

void print_int(void *val) {
	printf("%d ", *val);
}

List *get_simple_list(error_t *err) {
	List *list = list_new(err);
	if(err != NULL){
		printf("failed to allocate new list\n");
		return NULL;
	}
	int input[3] = {2, 3, 5};
	int *out;
	int i;
	for(i=0; i<3; i++){
		list_append(list, input[i], err);
		if(err != NULL){
			printf("failed to append element %d to list ", i); list_map(list, &print_int);
			return NULL;
		}
	}
	return list;
}


error_t test_append_then_peek_returns_correct_value() {
	error_t err;
	List *list = list_new(&err);
	if(err != NULL){
		printf("failed to make new list\n");
		return err;
	}

	int input[3] = {2, 3, 5};
	int *out;
	int i;
	for(i=0; i<3; i++){
		list_append(list, input[i], &err);
		if(err != NULL){
			printf("failed to append element %d to list ", i); list_map(list, &print_int);
			return err;
		}

		out = list_peek(&err);
		if(err != NULL){
			printf("failed peek element from list "); list_map(list, &print_int);
			return err;
		}

		if(*out != input[i]){
			printf("peeked and got value %d, expected %d", *out, input[i]);
			return "wrong return value on peek";
		}
	}

	return NULL;
}

//error_t test_append_

error_t test_poll_removes_elements() {
	error_t err;
	List *list = make_simple_list(&err);
	if(err != NULL){
		printf("failed to make simple list\n");
		return err;
	}

	for(i=0; i<3; i++){
		out = list_poll(&err);
		if(*out != input[i]){
			printf("polled and got value %d, expected %d", *out, input[i]);
			return err;
		}
	}
	return NULL;
}

error_t test_get() {
	error_t err;
	List *list = make_simple_list(&err);
	if(err != NULL){
		printf("failed to make simple list\n");
		return err;
	}

	int what[3] = {2, 3, 5};
	// [2,3,5]
	int *out;
	for(i=0; i<3; i++){
		list_get(list, i, err);
		if(err != NULL){
			printf("got at index %d and got value %d, expected %d", i, *out, what[i]);
		}
	}
	return NULL;	
}

error_t test_insert() {
	error_t err;
	List *list = make_simple_list(&err);
	if(err != NULL){
		printf("failed to make simple list\n");
		return err;
	}
	int more[3] = {7, 11, 13};
	// [2,3,5]
	// [7,2,3,5]
	// [7,2,11,3,5]
	// [7,2,11,3,13,5]
	int target[6] = {7,2,11,3,13,5};
	int i;
	for(i=0; i<3; i++){
		list_insert(list, more[i], 2*i, err);
		if(err != NULL){
			printf("failed to insert value %d at position %d into list ", more[i], i); list_print(list);
		}
	}

	int *out;
	for(i=0; i<6; i++){
		out = list_get(list, i, err);
		if(err != NULL){
			printf("failed to get element at position %d from list ", i); list_print(list);
		}

		if(*out != target[i]){
			printf("got at index %d and got value %d, expected %d\n", i, *out, target[i]);
		}
	}
	
	return NULL;
}

error_t test_length_after_append() {

}

error_t test_length_after_insert() {

}

error_t test_length_after_poll() {

}

error_t test_length_on_from_array() {

}

error_t test_from_array_on_valid_input {

}

error_t test_from_array_on_invalid_input() {

}

error_t test_to_array() {

}

error_t test_map_copy_copies_list() {

}

error_t test_map_mod_modifies_list() {

}

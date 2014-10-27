#include"list.h"
#include<stdio.h>
#include<stdlib.h>

error_t test_append_then_peek_returns_correct_value() {
	error_t err;
	List *list = list_new(err);
	if(err != NULL){
		fprintf("failed to make new list\n", stderr);
		return err;
	}

	int intput[3] = {2, 3, 5};
	int i;
	for(i=0; i<3; i++){
		list_append(list, err)	
		if(err != NULL){
			fprintf("failed to append element %d to list ");
		}
	}

}

error_t test_poll_removes_elements() {

}

error_t test_get_and_insert() {

}

error_t test_from_array() {

}

error_t test_to_array() {

}

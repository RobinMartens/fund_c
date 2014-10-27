#include<stdio.h>
#include"list_test.h"

int main(int argc, char **argv){
	printf("Running unit tests for list\n");
	error_t err = test_list();
	if(err == NULL){
		printf("Unit tests for list passed!\n");
	}else{
		printf("Unit tests for list failed: %s\n", err);
	}
	return 0;
}

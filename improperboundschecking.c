/*
 * improperboundschecking.c
 *
 *  Created on: Aug 2, 2014
 *      Author: ixidor
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 8

void initialize_array(int * array, int size);

int improperboundscheck(){

	int* str_output;
	int size,i;

	printf("eNTER NUMBER OF CHARACTERS TO OUTPUT:");
	scanf("%d",&size);

	str_output = malloc(size*sizeof(int));

	initialize_array(str_output,size);

	printf("Array of size %d initialized. \n",size);

	free(str_output);

	return 0;



}

/*  //Supuestamente asi es como debe ser
	str_output = malloc(size+BUFFER);

	for( i = 0 ; i < BUFFER ; i++){
		str_output[i] = i + 1 == BUFFER ? ' ' : '>';
	}

	for(; i < size+BUFFER ; i++){
		str_output[i] = 'a' + (i-BUFFER)%26;
	}

	printf("String: %s\n",str_output);
	free(str_output);

	return 0;
	//end main function

 */


void initialize_array(int * array, int size){
	int i;

	//IMPROPER BOUNDS CHECK
//	if(size + BUFFER < size){
//		printf("Buffer overflow detected!'\n");
//		printf("Size requested: %d\n, size");
//		printf("Size + Buffer is: %d\n", size + BUFFER);
//		printf("Terminating program \n");
//		exit(1);
//	}

	//This if statemen will be optimized away by the compiler
	if(array + size < array){
		printf("Buffer Overflow error detected!");
		exit(1);
	}

	for(i=0;i<size;i++){
		array[i] = 0;
	}

	return;

}








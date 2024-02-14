#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int main(){

	reg_t registers = {0, 0, 0, 0};
	const char* file = "./code.asm";

	// Define a "size" variable base on the number of lines in the input file
	int size = getSize(file);

	// Get the array of structures from the file
	func_t *funcs = getStructs(getFile(file), size);

	// Print the array of structures
	for (int i = 0; i < size; i++){
		printStruct(&funcs[i]);
	}


	int input = 0;
	while (input < size){
		input = redirectToFunction(&funcs[input], &registers, input);
		printf("ra: %d\n", registers.ra);
		printf("rb: %d\n", registers.rb);
		printf("rc: %d\n", registers.rc);
		printf("rd: %d\n", registers.rd);
	}

	return 0;
}

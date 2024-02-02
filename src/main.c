#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.c"


int main(){

	const char* file = "./code.asm";

	// Define a "size" variable base on the number of lines in the input file
	int size = getSize(file);

	// Get the array of structures from the file
	func_t *funcs = getStructs(getFile(file), size);

	// Print the array of structures
	for (int i = 0; i < size; i++){
		printStruct(&funcs[i]);
	}

	return 0;
}

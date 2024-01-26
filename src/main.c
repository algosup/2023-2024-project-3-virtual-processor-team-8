#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scraper.c"


int main(){
	// Define a "size" variable base on the number of lines in the input file
	int size = getSize();

	// Get the array of structures from the file
	func_t *funcs = getStructs(getFile(), size);

	// Print the array of structures
	for (int i = 0; i < size; i++){
		printStruct(&funcs[i]);
	}

	return 0;
}

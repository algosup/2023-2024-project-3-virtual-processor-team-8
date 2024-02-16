#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int main(){

	// Define the registers
	reg_t registers = {0, 0, 0, 0};

	// Define the file path
	const char* file = "./code.asm";

	// Go through the array of structures and execute the corresponding function
	goThrough(file, registers);

	return 0;
}

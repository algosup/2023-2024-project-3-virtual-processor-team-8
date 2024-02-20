#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int main(){

	// Define the registers
	reg_t registers = {0, 0, 0, 0};


	// Define the file path
	char* line = getLine(getFile("./path.txt"), 1);
	line[strlen(line)-1] = '\0';
	const char* file = line;

	// Go through the array of structures and execute the corresponding function
	goThrough(file, registers);

	return 0;
}

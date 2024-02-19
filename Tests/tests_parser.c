#include "tests_parser.h"


int getFileTEST(const char *file) {

	// Get the file data
	char *li = getFile(file);

	// Check that the file is not empty
	assert(li != NULL);

	return 1;
}


int getLineTEST(const char *file){

	// Open the file
	FILE *f = fopen(file, "r");

	// Get the first character
	char ch = getc(f);

	// Get line 2 of the file
	char *li = getLine(getFile(file), 1);

	// Check that the line is not empty
	assert(li != NULL);

	// Check that the line is correct
	assert(li[0] == ch);

	return 2;
}

int getSizeTEST(const char *file) {

	// Open the file
	FILE *f = fopen(file, "r");

	// Get the first character
	char ch = getc(f);

	// Get the number of lines in the file
	int size_of_file = 1;

	// Loop through the file
	while (ch != EOF) {

		// If the character is a new line, increment the size
		if (ch == '\n') {

			// Increment the size
			++size_of_file;
		}

		// Get the next character
		ch = getc(f);
	}

	// Get the size of the file
	int size = getSize(file);

	// Check that the size is correct
	assert(size == size_of_file);

	return 1;
}

int getStructsTEST(const char *file) {

	// Get the functions from the file
	func_t *f = getStructs(getFile(file), getSize(file));

	// Check that the functions are not empty
	assert(f != NULL);
	assert(f[0].line == 1);

	return 2;
}


int switchStrTEST(){
	assert(switchStr("add") == 1);
	assert(switchStr("ra") == 2);
	assert(switchStr("0") == 3);
	assert(switchStr("prf") == 1);
	assert(switchStr("12") == 3);

	return 5;
}

int setStructTEST(){
	func_t *f = malloc(sizeof(func_t));
	setStruct(f, "add", "", "ra", "12", 3);
	assert(strcmp(f->instruction, "add") == 0);
	assert(strcmp(f->parameter1, "ra") == 0);
	assert(strcmp(f->parameter2, "12") == 0);
	assert(f->line == 3);

	setStruct(f, "", "res", "", "", 12);

	assert(strcmp(f->name, "res") == 0);

	return 6;
}
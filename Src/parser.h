#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Struct for the function containing the instruction, name, parameters, and line number
typedef struct function {
	char instruction[5];
	char name[10];
	char parameter1[10];
	char parameter2[10];
	int line;
}func_t;


// Print the lines of the array of strings given in the parameter based on the size
void printLines(char **lines, int size);


// Get the line of the array of strings given in the parameter based on the line number
char* getLine(char **lines, int line);


// Get the file and return an array of strings containing each line of the file
void *getFile(const char *path);


// Get the size of the file and return an int based on the number of lines in the file
int getSize(const char *path);


// Get an array of functions from the array of strings given in the parameter based on the size
void *getStructs(char **lines, int size);


// Returns an int based on what the string is
// e.g. "add" returns 1 because it is an instruction and "ra" returns 2 because it is a register
int switchStr(char *str);


// Allows the program to modify a struct function
void setStruct(struct function *f, char *instruction, char *name, char *parameter1, char *parameter2, int line);


// Prints the struct function
void printStruct(struct function *f);
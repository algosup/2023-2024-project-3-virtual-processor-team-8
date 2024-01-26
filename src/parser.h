#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLines(char **lines, int size);

void *getLines();

void *getStructs(char **lines, int size);

int switchStr(char *str);


struct function {
	char *instruction;
	char *name;
	char *parameter1;
	char *parameter2;
	int line;
};
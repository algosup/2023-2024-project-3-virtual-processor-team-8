#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct function {
	char instruction[5];
	char name[10];
	char parameter1[10];
	char parameter2[10];
	int line;
}func_t;

void printLines(char **lines, int size);

void *getFile();

void *getStructs(char **lines, int size);

int switchStr(char *str);

void setStruct(struct function *f, char *instruction, char *name, char *parameter1, char *parameter2, int line);

void printStruct(struct function *f);
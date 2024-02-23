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
	unsigned int line;
}func_t;


typedef struct used{

	// 1 if the register ra is used
	int a;

	// 1 if the register rb is used
	int b;

	// 1 if the register rc is used
	int c;

	// 1 if the register rd is used
	int d;

	// 1 if the register re is used
	int e;

	// 1 if the register rf is used
	int f;

	// 1 if the register rg is used
	int g;

	// 1 if the register rh is used
	int h;

	// 1 if the register ri is used
	int i;

	// 1 if the register rj is used
	int j;

	// 1 if the register rk is used
	int k;

	// 1 if the register rl is used
	int l;

	// 1 if the register rm is used
	int m;

	// 1 if the register rn is used
	int n;

	// 1 if the register ro is used
	int o;

	// 1 if the register rp is used
	int p;

	// 1 if the register rq is used
	int q;

	// 1 if the register rr is used
	int r;

	// 1 if the register rs is used
	int s;

	// 1 if the register rt is used
	int t;

	// 1 if the register ru is used
	int u;

	// 1 if the register rv is used
	int v;

	// 1 if the register rw is used
	int w;

	// 1 if the register rx is used
	int x;

	// 1 if the register ry is used
	int y;

	// 1 if the register rz is used
	int z;
}used_t;



// Print the lines of the array of strings given in the parameter based on the size
void printLines(char **lines, unsigned int size);


// Get the line of the array of strings given in the parameter based on the line number
char* getLine(char **lines, unsigned int line);


// Get the file and return an array of strings containing each line of the file
void *getFile(const char *path);


// Get the size of the file and return an int based on the number of lines in the file
unsigned int getSize(const char *path);


// Get an array of functions from the array of strings given in the parameter based on the size
void *getStructs(char **lines, unsigned int size);


// Returns an int based on what the string is
// e.g. "add" returns 1 because it is an instruction and "ra" returns 2 because it is a register
unsigned int switchStr(char *str);


// Allows the program to modify a struct function
void setStruct(struct function *f, char *instruction, char *name, char *parameter1, char *parameter2, unsigned int line);


// Prints the struct function
void printStruct(struct function *f);


// Get the position of the function in the array of structures
int getPosition(func_t *func, char *object, unsigned int size);


// Check if a syntax error is present in the array of structures
void checkSyntax(func_t *functions, unsigned int size, used_t *registers_used);


// Check if the parameter is a register
int isRegister(char *parameter, used_t *registers_used);


// Check if the parameter is a number
int isANumber(char *str);


// Update the status of the registers
void updateUsedregister(used_t *regs, char* reg);
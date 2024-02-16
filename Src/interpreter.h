#include <stdbool.h>

// Define a structure to hold the registers and their values
typedef struct reg{

	// register ra
	int ra;

	// register rb
	int rb;

	// register rc
	int rc;

	// register rd
	int rd;

}reg_t;


// Define a structure to hold the state of comparison
typedef struct state{

	// 1 if the two parameters are equal
	int equal;

	// 1 if the first parameter is greater than the second
	int greater;

	// 1 if the first parameter is lesser than the second
	int lesser;

}state_t;


// Define a structure to hold the called status and the line where the function was called
typedef struct called{

	// 1 if the function was called
	int called;

	// The line where the function was called
	int line;

}call_t;


// Go through the array of structures and execute the corresponding function
void goThrough(const char *file, reg_t registers);


// Get the position of the function in the array of structures
int getPosition(func_t *func, char *object, int size);


// Check the instruction and execute the corresponding function
int redirectToFunction(func_t *func, reg_t *regs, int i, state_t *state, call_t *call, const char *file);


// Check if the parameter is a register
int isRegister(char *parameter);


// Change the value of the register
void *changeRegister(int value, reg_t *regs, char *regist);


// Get the value of the defined register
int getRegisterValue(reg_t *regs, char *regist);


// Make an addition between the two parameters
int executeADD(char *parameter1, char *parameter2, reg_t *registers);


// Make a subtraction between the two parameters
int executeSUB(char *parameter1, char *parameter2, reg_t *registers);


// Make a multiplication between the two parameters
int executeMUL(char *parameter1, char *parameter2, reg_t *registers);


// Make a division between the two parameters
int executeDIV(char *parameter1, char *parameter2, reg_t *registers);


// Move the value to the first parameter, from the second parameter
void *executeMOV(char *parameter1, char *parameter2, reg_t *regs);


// Compare the two parameters
int executeCMP(char *parameter1, char *parameter2, reg_t *regs);


// Set parameter1 value to the value contained at the address contained in parameter2
void executePRT(char *parameter1, char *parameter2, reg_t *registers);


// Set the value of the address at contained by parameter1 to the value of parameter2
void executePRF(char *parameter1, char *parameter2, reg_t *registers);


// Set the parameter 1 to the value of the parameter 1 AND the value of the parameter 2
void executeAND(char *parameter1, char *parameter2, reg_t *registers);


// Set the parameter 1 to the value of the parameter 1 OR the value of the parameter 2
void executeOR(char *parameter1, char *parameter2, reg_t *registers);


// Set the parameter 1 to the value of the parameter 1 XOR the value of the parameter 2
void executeXOR(char *parameter1, char *parameter2, reg_t *registers);


// Set the parameter 1 to the value of NOT parameter 1
unsigned int executeNOT(char *parameter1, reg_t *registers);


// Jump to the line given in the parameter
int executeJMP(char *parameter, const char *file);


// Jump to the line given in the parameter if the two parameters are equal
int executeJE(char *parameter);


// Jump to the line given in the parameter if the two parameters are not equal
int executeJNE(char *parameter);


// Jump to the line given in the parameter if the first parameter is greater than the second
int executeJG(char *parameter);


// Jump to the line given in the parameter if the first parameter is lesser than the second
int executeJL(char *parameter);


// Jump to the line given in the parameter if the first parameter is greater than or equal to the second
int executeJGE(char *parameter);


// Jump to the line given in the parameter if the first parameter is lesser than or equal to the second
int executeJLE(char *parameter);


// Call the function given in the parameter
int executeCALL(char *parameter1, int line, call_t *call, const char* file);


// Return to the line where the function was called
int executeRET(call_t *call);


// End the program
void executeEND(reg_t *regs);


// Print the registers
void printRegisters(reg_t *regs);
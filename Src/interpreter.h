#include <stdbool.h>

// Define a structure to hold the registers and their values
typedef struct reg{
	int ra;
	int rb;
	int rc;
	int rd;
}reg_t;


// Check the instruction and execute the corresponding function
void redirectToFunction(func_t *func);


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
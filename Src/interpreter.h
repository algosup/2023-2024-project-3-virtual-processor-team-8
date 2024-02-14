#include <stdbool.h>

// Define a structure to hold the registers and their values
typedef struct reg{
	int ra;
	int rb;
	int rc;
	int rd;
}reg_t;


// Check the instruction and execute the corresponding function
int redirectToFunction(func_t *func, reg_t *regs, int i);


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







int executeJMP(char *parameter);

int executeJE(char *parameter);

int executeJNE(char *parameter);

int executeJZ(char *parameter);

int executeJNZ(char *parameter);

int executeJG(char *parameter);

int executeJL(char *parameter);

int executeJGE(char *parameter);

int executeJLE(char *parameter);

int executeCALL(char *parameter1, int line);

int executeRET();

void endProgram();
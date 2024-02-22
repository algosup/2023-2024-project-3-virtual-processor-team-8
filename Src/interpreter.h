#include <stdbool.h>

#define MAX_VMEMORY 256

// Contact data structure
typedef struct
{
    int vaddress;
} VMemory;

// Define a structure to hold the registers and their values
typedef struct reg{

	// register ra
	unsigned int ra;

	// register rb
	unsigned int rb;

	// register rc
	unsigned int rc;

	// register rd
	unsigned int rd;

	// register re
	unsigned int re;

	// register rf
	unsigned int rf;

	// register rg
	unsigned int rg;

	// register rh
	unsigned int rh;

	// register ri
	unsigned int ri;

	// register rj
	unsigned int rj;

	// register rk
	unsigned int rk;

	// register rl
	unsigned int rl;

	// register rm
	unsigned int rm;

	// register rn
	unsigned int rn;

	// register ro
	unsigned int ro;

	// register rp
	unsigned int rp;

	// register rq
	unsigned int rq;

	// register rr
	unsigned int rr;

	// register rs
	unsigned int rs;

	// register rt
	unsigned int rt;

	// register ru
	unsigned int ru;

	// register rv
	unsigned int rv;

	// register rw
	unsigned int rw;

	// register rx
	unsigned int rx;

	// register ry
	unsigned int ry;

	// register rz
	unsigned int rz;

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


// Check the instruction and execute the corresponding function
unsigned int redirectToFunction(func_t *func, reg_t *regs, int i, state_t *state, call_t *call, const char *file, used_t *registers_used, VMemory Vmemory[]);


// Change the value of the register
void *changeRegister(unsigned int value, reg_t *regs, char *regist);


// Get the value of the defined register
unsigned int getRegisterValue(reg_t *regs, char *regist);


// Make an addition between the two parameters
unsigned int executeADD(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used);


// Make a subtraction between the two parameters
unsigned int executeSUB(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used);


// Make a multiplication between the two parameters
unsigned int executeMUL(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used);


// Make a division between the two parameters
unsigned int executeDIV(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used);


// Move the value to the first parameter, from the second parameter
void *executeMOV(char *parameter1, char *parameter2, reg_t *regs, used_t *registers_used);


// Compare the two parameters
unsigned int executeCMP(char *parameter1, char *parameter2, reg_t *regs, used_t *registers_used);


// Set parameter1 value to the value contained at the address contained in parameter2
void executePRT(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used, VMemory Vmemory[]);


// Set the value of the address at contained by parameter1 to the value of parameter2
void executePRF(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used, VMemory Vmemory[]);


// Set the parameter 1 to the value of the parameter 1 AND the value of the parameter 2
void executeAND(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used);


// Set the parameter 1 to the value of the parameter 1 OR the value of the parameter 2
void executeOR(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used);


// Set the parameter 1 to the value of the parameter 1 XOR the value of the parameter 2
void executeXOR(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used);


// Set the parameter 1 to the value of NOT parameter 1
unsigned int executeNOT(char *parameter1, reg_t *registers, used_t *registers_used);


// Jump to the line given in the parameter
unsigned int executeJMP(char *parameter, const char *file);


// Jump to the line given in the parameter if the two parameters are equal
unsigned int executeJE(char *parameter);


// Jump to the line given in the parameter if the two parameters are not equal
unsigned int executeJNE(char *parameter);


// Jump to the line given in the parameter if the first parameter is greater than the second
unsigned int executeJG(char *parameter);


// Jump to the line given in the parameter if the first parameter is lesser than the second
unsigned int executeJL(char *parameter);


// Jump to the line given in the parameter if the first parameter is greater than or equal to the second
unsigned int executeJGE(char *parameter);


// Jump to the line given in the parameter if the first parameter is lesser than or equal to the second
unsigned int executeJLE(char *parameter);


// Call the function given in the parameter
unsigned int executeCALL(char *parameter1, int line, call_t *call, const char* file);


// Return to the line where the function was called
unsigned int executeRET(call_t *call, int line);


// End the program
void executeEND(reg_t *regs, used_t *registers_used);


// Print the registers
void printRegisters(reg_t *regs, used_t *used);
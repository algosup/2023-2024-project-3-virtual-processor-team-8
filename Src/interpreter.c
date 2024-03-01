#include "interpreter.h"


void goThrough(const char* file, reg_t registers){

	// Define a "size" variable base on the number of lines in the input file
	int size = getSize(file);

	// Define the state of the comparison
	used_t registers_used = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// Get the array of structures from the file
	func_t *funcs = getStructs(getFile(file), size);

	// Define the state of comparison
	state_t state = {-1, -1, -1};

	// Define the state of the call
	call_t call = {0, 0};
	

	// Define the virtual memory
	VMemory Vmemory[MAX_VMEMORY];

	// Define the current line
	int input = 0;


	// Check if the syntax of the array of structures is correct
	checkSyntax(funcs, size, &registers_used);


	printf("============================================================\n");

	// Go through the array of structures and execute the corresponding function until the end
	while (input <= size){

		// Get the next line to execute depending on the result of the function

		input = redirectToFunction(&funcs[input], &registers, input, &state, &call, file, &registers_used, Vmemory);
	}

}




unsigned int redirectToFunction(func_t *func, reg_t *regs, int i, state_t *state, call_t *call, const char* file, used_t *registers_used, VMemory Vmemory[]){


	// Print the struct function
	// printStruct(func);

	// Check if the instruction is "add"
	if (strcmp(func->instruction, "add") == 0){

		// Print the function add
		printf("Adding %s to %s\n", func->parameter2, func->parameter1);

		// Execute the function add
		executeADD(func->parameter1, func->parameter2, regs, registers_used, i);

		updateUsedregister(registers_used, func-> parameter1);
		updateUsedregister(registers_used, func-> parameter2);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "sub"
	else if (strcmp(func->instruction, "sub") == 0){

		// Print the function sub
		printf("Subtracting %s from %s\n", func->parameter2, func->parameter1);

		// Execute the function sub
		executeSUB(func->parameter1, func->parameter2, regs, registers_used, i);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "mul"
	else if (strcmp(func->instruction, "mul") == 0){

		// Print the function mul
		printf("Multiplying %s by %s\n", func->parameter1, func->parameter2);

		// Execute the function mul
		executeMUL(func->parameter1, func->parameter2, regs, registers_used, i);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "div"
	else if (strcmp(func->instruction, "div") == 0){

		// Print the function div
		printf("Dividing %s by %s\n", func->parameter1, func->parameter2);

		// Execute the function div
		executeDIV(func->parameter1, func->parameter2, regs, registers_used, i);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "div"
	else if (strcmp(func->instruction, "mod") == 0){

		// Print the function div
		printf("Getting the Modulo of \"%s / %s\"\n", func->parameter1, func->parameter2);

		// Execute the function div
		executeMOD(func->parameter1, func->parameter2, regs, registers_used, i);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "div"
	else if (strcmp(func->instruction, "sqr") == 0){

		// Print the function div
		printf("Setting %s to the square root of %s\n", func->parameter1, func->parameter2);

		// Execute the function div
		executeSQR(func->parameter1, func->parameter2, regs, registers_used);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "mov"
	else if (strcmp(func->instruction, "mov") == 0){

		// Print the function mov
		printf("Setting %s to %s\n", func->parameter1, func->parameter2);

		// Execute the function mov
		executeMOV(func->parameter1, func->parameter2, regs, registers_used);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "jmp"
	else if (strcmp(func->instruction, "jmp") == 0){

		// Print the function jmp
		printf("Jumping to %s\n", func->parameter1);
		printf("============================================================\n");

		// Execute the function jmp and return the line to jump to
		return executeJMP(func->parameter1, file);
	}

	// Check if the instruction is "je"
	else if (strcmp(func->instruction, "je") == 0){

		// If the previous comparison was equal
		if (state->equal == 1){

			// Print the function je
			printf("Jumping to %s\n", func->parameter1);
			printf("============================================================\n");

			// Execute the function jmp and return the line to jump to
			return executeJMP(func->parameter1, file);
		}

		// If the previous comparison was not equal
		else {

			// Return the next line
			return i + 1;
		}
	}

	// Check if the instruction is "jne"
	else if (strcmp(func->instruction, "jne") == 0){

		// If the previous comparison was not equal
		if (state->equal == 0){

			// Print the function jne
			printf("Jumping to %s\n", func->parameter1);
			printf("============================================================\n");

			// Execute the function jmp and return the line to jump to
			return executeJMP(func->parameter1, file);
		}

		// If the previous comparison was equal
		else {

			// Return the next line
			return i + 1;
		}
	}

	// Check if the instruction is "jg"
	else if (strcmp(func->instruction, "jg") == 0){

		// If the previous comparison was greater
		if (state->greater == 1){

			// Print the function jg
			printf("Jumping to %s\n", func->parameter1);
			printf("============================================================\n");

			// Execute the function jmp and return the line to jump to
			return executeJMP(func->parameter1, file);
		}

		// If the previous comparison was not greater
		else {

			// Return the next line
			return i + 1;
		}
	}

	// Check if the instruction is "jge"
	else if (strcmp(func->instruction, "jge") == 0){

		// If the previous comparison was greater or equal
		if (state->greater == 1 || state->equal == 1){

			// Print the function jge
			printf("Jumping to %s\n", func->parameter1);
			printf("============================================================\n");

			// Execute the function jmp and return the line to jump to
			return executeJMP(func->parameter1, file);
		}

		// If the previous comparison was not greater or equal
		else {

			// Return the next line
			return i + 1;
		}
	}

	// Check if the instruction is "jl"
	else if (strcmp(func->instruction, "jl") == 0){

		// If the previous comparison was lesser
		if (state->lesser == 1){

			// Print the function jl
			printf("Jumping to %s\n", func->parameter1);
			printf("============================================================\n");

			// Execute the function jmp and return the line to jump to
			return executeJMP(func->parameter1, file);
		}

		// If the previous comparison was not lesser²
		else {

			// Return the next line
			return i + 1;
		}
	}

	// Check if the instruction is "jle"
	else if (strcmp(func->instruction, "jle") == 0){

		// If the previous comparison was lesser or equal
		if (state->lesser == 1 || state->equal == 1){

			// Print the function jle
			printf("Jumping to %s\n", func->parameter1);
			printf("============================================================\n");

			// Execute the function jmp and return the line to jump to
			return executeJMP(func->parameter1, file);
		}

		// If the previous comparison was not lesser or equal
		else {

			// Return the next line
			return i + 1;
		}
	}

	// Check if the instruction is "call"
	else if (strcmp(func->instruction, "call") == 0){

		// Print the function call
		printf("Calling %s\n", func->parameter1);
		printf("============================================================\n");

		// Execute the function call and return the line to jump to
		return executeCALL(func->parameter1, i, call, file);
	}

	// Check if the instruction is "cmp"
	else if (strcmp(func->instruction, "cmp") == 0){

		// Print the function cmp
		printf("Comparing %s to %s\n", func->parameter1, func->parameter2);

		// Execute the function cmp and get the state of the comparison
		int cmp_value = executeCMP(func->parameter1, func->parameter2, regs, registers_used);

		// If the parameter1 is equal to the parameter2
		if (cmp_value == 1){
			state->equal = 1;
			state->greater = 0;
			state->lesser = 0;
		}

		// If the parameter1 is greater than the parameter2
		else if (cmp_value == 2){
			state->equal = 0;
			state->greater = 1;
			state->lesser = 0;
		}

		// If the parameter1 is lesser than the parameter2
		else if (cmp_value == 3){
			state->equal = 0;
			state->greater = 0;
			state->lesser = 1;
		}
		else {

			// If the parameters are not equal, greater, or lesser
			state->equal = 0;
			state->greater = 0;
			state->lesser = 0;
		}

		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "prf"
	else if (strcmp(func->instruction, "prf") == 0){

		// Execute the function prf
		printf("Setting the value of %s to the value at address of %s\n", func->parameter1, func->parameter2);

		// Execute the function prf
		executePRF(func->parameter1, func->parameter2, regs, registers_used, Vmemory, func->line);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "prt"
	else if (strcmp(func->instruction, "prt") == 0){

		// Print the function prt
		printf("Setting the value of %s to the value at the address of %s\n", func->parameter2, func->parameter1);

		// Execute the function prt
		executePRT(func->parameter1, func->parameter2, regs, registers_used, Vmemory, func->line);

		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "and"
	else if (strcmp(func->instruction, "and") == 0){

		// Execute the function and
		printf("Setting %s to %s and %s\n", func->parameter1, func->parameter1, func->parameter2);

		// Execute the function and
		executeAND(func->parameter1, func->parameter2, regs, registers_used);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "or"
	else if (strcmp(func->instruction, "or") == 0){

		// Print the function or
		printf("Setting %s to %s or %s\n", func->parameter1, func->parameter1, func->parameter2);

		// Execute the function or
		executeOR(func->parameter1, func->parameter2, regs, registers_used);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "xor"
	else if (strcmp(func->instruction, "xor") == 0){

		// Print the function xor
		printf("Setting %s to %s xor %s\n", func->parameter1, func->parameter1, func->parameter2);

		// Execute the function xor
		executeXOR(func->parameter1, func->parameter2, regs, registers_used);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "not"
	else if (strcmp(func->instruction, "not") == 0){

		// Print the function not
		printf("Setting %s to not %s\n", func->parameter1, func->parameter1);

		// Execute the function not
		executeNOT(func->parameter1, regs, registers_used);

		// Print the value of the register
		printf("%s is now equal to %d\n", func->parameter1, getRegisterValue(regs, func->parameter1));
		printf("============================================================\n");

		// Return the next line
		return i + 1;
	}

	// Check if the instruction is "end"
	else if (strcmp(func->instruction, "end") == 0){

		// Print the function end
		printf("Ending the program\n");

		// Execute the function end
		executeEND(regs, registers_used);

		// Return the next line
		return i + 1;
	}
	
	// Check if the instruction is "ret"
	else if (strcmp(func->instruction, "ret") == 0){

		// Print the function ret
		printf("Returning to the line after the call\n");
		printf("============================================================\n");

		// Execute the function ret
		return executeRET(call, i);
	}

	// Check if the instruction is "function"
	else if (func->name != NULL){

		// Set the state to in a function
		// is_in_a_function = true;

		// Return the next line
		return i + 1;
	}

	// If the instruction is not valid or null
	else {

		// Return the next line
		return i + 1;
	}
}


unsigned int executeJMP(char *parameter, const char* file){

	// Get the list of structures from the file
	func_t *fs = getStructs(getFile(file), getSize(file));

	// Get the position of the function to jump to
	int position = getPosition(fs, parameter, getSize(file));

	if (position == -1){
		printf("\e[1;1H\e[2J");
		printf("Error: The label \"%s\" does not exist\n", parameter);
		exit(1);
	}

	// Set the current line to the line of the function to jump to
	return position;
}


unsigned int executeCALL(char *parameter1, int line, call_t *call, const char* file){

	// Get the list of structures from the file
	func_t *fs = getStructs(getFile(file), getSize(file));

	// Set the call to called
	call->called = 1;

	// Set the line of the call to the current line
	call->line = line;


	// Get the position of the function to jump to
	int position = getPosition(fs, parameter1, getSize(file));

	if (position == -1){
		printf("\e[1;1H\e[2J");
		printf("Error: The label \"%s\" does not exist\n", parameter1);
		exit(1);
	}

	// Set the current line to the line of the function to jump to
	return position;
}

unsigned int executeRET(call_t *call, int line){

	// If the call was called
	if (call->called == 1){

		// Set the call to not called
		call->called = 0;

		// Return the line after the call
		return call->line+1;
	}
	else {

		// Return the next line
		return line + 1;
	}
}

void executeEND(reg_t *regs, used_t *registers_used){

	// Print the registers
	printRegisters(regs, registers_used);

	// Exit the program
	exit(0);
}

























void *changeRegister(unsigned int value, reg_t *regs, char *regist){

	// Check if the register to change is ra
	if (strcmp(regist, "ra") == 0){

		// Change the value of the register ra
		regs->ra = value;
	}

	// Check if the register to change is rb
	else if (strcmp(regist, "rb") == 0){

		// Change the value of the register rb
		regs->rb = value;
	}

	// Check if the register to change is rc
	else if (strcmp(regist, "rc") == 0){

		// Change the value of the register rc
		regs->rc = value;
	}

	// Check if the register to change is rd
	else if (strcmp(regist, "rd") == 0){

		// Change the value of the register rd
		regs->rd = value;
	}

	// Check if the register to change is re
	else if (strcmp(regist, "re") == 0){

		// Change the value of the register re
		regs->re = value;
	}

	// Check if the register to change is rf
	else if (strcmp(regist, "rf") == 0){

		// Change the value of the register rf
		regs->rf = value;
	}

	// Check if the register to change is rg
	else if (strcmp(regist, "rg") == 0){

		// Change the value of the register rg
		regs->rg = value;
	}

	// Check if the register to change is rh
	else if (strcmp(regist, "rh") == 0){

		// Change the value of the register rh
		regs->rh = value;
	}

	// Check if the register to change is ri
	else if (strcmp(regist, "ri") == 0){

		// Change the value of the register ri
		regs->ri = value;
	}

	// Check if the register to change is rj
	else if (strcmp(regist, "rj") == 0){

		// Change the value of the register rj
		regs->rj = value;
	}

	// Check if the register to change is rk
	else if (strcmp(regist, "rk") == 0){

		// Change the value of the register rk
		regs->rk = value;
	}

	// Check if the register to change is rl
	else if (strcmp(regist, "rl") == 0){

		// Change the value of the register rl
		regs->rl = value;
	}

	// Check if the register to change is rm
	else if (strcmp(regist, "rm") == 0){

		// Change the value of the register rm
		regs->rm = value;
	}

	// Check if the register to change is rn
	else if (strcmp(regist, "rn") == 0){

		// Change the value of the register rn
		regs->rn = value;
	}

	// Check if the register to change is ro
	else if (strcmp(regist, "ro") == 0){

		// Change the value of the register ro
		regs->ro = value;
	}

	// Check if the register to change is rp
	else if (strcmp(regist, "rp") == 0){

		// Change the value of the register rp
		regs->rp = value;
	}

	// Check if the register to change is rq
	else if (strcmp(regist, "rq") == 0){

		// Change the value of the register rq
		regs->rq = value;
	}

	// Check if the register to change is rr
	else if (strcmp(regist, "rr") == 0){

		// Change the value of the register rr
		regs->rr = value;
	}

	// Check if the register to change is rs
	else if (strcmp(regist, "rs") == 0){

		// Change the value of the register rs
		regs->rs = value;
	}

	// Check if the register to change is rt
	else if (strcmp(regist, "rt") == 0){

		// Change the value of the register rt
		regs->rt = value;
	}

	// Check if the register to change is ru
	else if (strcmp(regist, "ru") == 0){

		// Change the value of the register ru
		regs->ru = value;
	}

	// Check if the register to change is rv
	else if (strcmp(regist, "rv") == 0){

		// Change the value of the register rv
		regs->rv = value;
	}

	// Check if the register to change is rw
	else if (strcmp(regist, "rw") == 0){

		// Change the value of the register rw
		regs->rw = value;
	}

	// Check if the register to change is rx
	else if (strcmp(regist, "rx") == 0){

		// Change the value of the register rx
		regs->rx = value;
	}

	// Check if the register to change is ry
	else if (strcmp(regist, "ry") == 0){

		// Change the value of the register ry
		regs->ry = value;
	}

	// Check if the register to change is rz
	else if (strcmp(regist, "rz") == 0){

		// Change the value of the register rz
		regs->rz = value;
	}

	// Return the registers
	return regs;
}

unsigned int getRegisterValue(reg_t *regs, char *regist){

	// Check if the register to get the value from is ra
	if (strcmp(regist, "ra") == 0){

		// Return the value of the register ra
		return regs->ra;
	}

	// Check if the register to get the value from is rb
	else if (strcmp(regist, "rb") == 0){

		// Return the value of the register rb
		return regs->rb;
	}

	// Check if the register to get the value from is rc
	else if (strcmp(regist, "rc") == 0){

		// Return the value of the register rc
		return regs->rc;
	}

	// Check if the register to get the value from is rd
	else if (strcmp(regist, "rd") == 0){

		// Return the value of the register rd
		return regs->rd;
	}

	// Check if the register to get the value from is re
	else if (strcmp(regist, "re") == 0){

		// Return the value of the register re
		return regs->re;
	}

	// Check if the register to get the value from is rf
	else if (strcmp(regist, "rf") == 0){

		// Return the value of the register rf
		return regs->rf;
	}

	// Check if the register to get the value from is rg
	else if (strcmp(regist, "rg") == 0){

		// Return the value of the register rg
		return regs->rg;
	}

	// Check if the register to get the value from is rh
	else if (strcmp(regist, "rh") == 0){

		// Return the value of the register rh
		return regs->rh;
	}

	// Check if the register to get the value from is ri
	else if (strcmp(regist, "ri") == 0){

		// Return the value of the register ri
		return regs->ri;
	}

	// Check if the register to get the value from is rj
	else if (strcmp(regist, "rj") == 0){

		// Return the value of the register rj
		return regs->rj;
	}

	// Check if the register to get the value from is rk
	else if (strcmp(regist, "rk") == 0){

		// Return the value of the register rk
		return regs->rk;
	}

	// Check if the register to get the value from is rl
	else if (strcmp(regist, "rl") == 0){

		// Return the value of the register rl
		return regs->rl;
	}

	// Check if the register to get the value from is rm
	else if (strcmp(regist, "rm") == 0){

		// Return the value of the register rm
		return regs->rm;
	}

	// Check if the register to get the value from is rn
	else if (strcmp(regist, "rn") == 0){

		// Return the value of the register rn
		return regs->rn;
	}

	// Check if the register to get the value from is ro
	else if (strcmp(regist, "ro") == 0){

		// Return the value of the register ro
		return regs->ro;
	}

	// Check if the register to get the value from is rp
	else if (strcmp(regist, "rp") == 0){

		// Return the value of the register rp
		return regs->rp;
	}

	// Check if the register to get the value from is rq
	else if (strcmp(regist, "rq") == 0){

		// Return the value of the register rq
		return regs->rq;
	}

	// Check if the register to get the value from is rr
	else if (strcmp(regist, "rr") == 0){

		// Return the value of the register rr
		return regs->rr;
	}

	// Check if the register to get the value from is rs
	else if (strcmp(regist, "rs") == 0){

		// Return the value of the register rs
		return regs->rs;
	}

	// Check if the register to get the value from is rt
	else if (strcmp(regist, "rt") == 0){

		// Return the value of the register rt
		return regs->rt;
	}

	// Check if the register to get the value from is ru
	else if (strcmp(regist, "ru") == 0){

		// Return the value of the register ru
		return regs->ru;
	}

	// Check if the register to get the value from is rv
	else if (strcmp(regist, "rv") == 0){

		// Return the value of the register rv
		return regs->rv;
	}

	// Check if the register to get the value from is rw
	else if (strcmp(regist, "rw") == 0){

		// Return the value of the register rw
		return regs->rw;
	}

	// Check if the register to get the value from is rx
	else if (strcmp(regist, "rx") == 0){

		// Return the value of the register rx
		return regs->rx;
	}

	// Check if the register to get the value from is ry
	else if (strcmp(regist, "ry") == 0){

		// Return the value of the register ry
		return regs->ry;
	}

	// Check if the register to get the value from is rz
	else if (strcmp(regist, "rz") == 0){

		// Return the value of the register rz
		return regs->rz;
	}

	else {
		return (unsigned int)atoi(regist);
	}
}

unsigned int executeADD(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used, int line){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2, registers_used);

	// Get the result of the operation
	int result = getRegisterValue(registers, parameter1) + getRegisterValue(registers, parameter2);

	// Check if the result is negative
	if (result < 0){

		// Print an error message
		printf("\e[1;1H\e[2J");
		printf("Error at line %d: The result of an operation can't be a negative number\n", line);
		exit(1);
	}


	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Add the value of the second parameter to the value of the first parameter
		unsigned int value = getRegisterValue(registers, parameter1) + atoi(parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}

	// If the second parameter is a register
	else{

		// Add the value of the second parameter to the value of the first parameter
		unsigned int value = getRegisterValue(registers, parameter1) + getRegisterValue(registers, parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}
}

unsigned int executeSUB(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used, int line){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2, registers_used);

	// Get the result of the operation
	int result = getRegisterValue(registers, parameter1) - getRegisterValue(registers, parameter2);

	// Check if the result is negative
	if (result < 0){

		// Print an error message
		printf("\e[1;1H\e[2J");
		printf("Error at line %d: The result of an operation can't be a negative number\n", line);
		exit(1);
	}

	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Subtract the value of the second parameter from the value of the first parameter
		unsigned int value = getRegisterValue(registers, parameter1) - atoi(parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}

	// If the second parameter is a register
	else{

		// Subtract the value of the second parameter from the value of the first parameter
		unsigned int value = getRegisterValue(registers, parameter1) - getRegisterValue(registers, parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}
}

unsigned int executeMUL(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used, int line){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2, registers_used);

	
	// Get the result of the operation
	int result = getRegisterValue(registers, parameter1) * getRegisterValue(registers, parameter2);

	// Check if the result is negative
	if (result < 0){

		// Print an error message
		printf("\e[1;1H\e[2J");
		printf("Error at line %d: The result of an operation can't be a negative number\n", line);
		exit(1);
	}


	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Multiply the value of the first parameter by the value of the second parameter
		unsigned int value = getRegisterValue(registers, parameter1) * atoi(parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}

	// If the second parameter is a register
	else{

		// Multiply the value of the first parameter by the value of the second parameter
		unsigned int value = getRegisterValue(registers, parameter1) * getRegisterValue(registers, parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}
}

unsigned int executeDIV(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used, int line){

	if (getRegisterValue(registers, parameter2) == 0){
		printf("\e[1;1H\e[2J");
		printf("Error at line %d: Division by zero is impossible\n", line);
		exit(1);
	}

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2, registers_used);

	// Get the result of the operation
	int result = getRegisterValue(registers, parameter1) / getRegisterValue(registers, parameter2);

	// Check if the result is negative
	if (result < 0){

		// Print an error message
		printf("\e[1;1H\e[2J");
		printf("Error at line %d: The result of an operation can't be a negative number\n", line);
		exit(1);
	}

	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Divide the value of the first parameter by the value of the second parameter
		unsigned int value = getRegisterValue(registers, parameter1) / atoi(parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}

	// If the second parameter is a register
	else{

		// Divide the value of the first parameter by the value of the second parameter
		unsigned int value = getRegisterValue(registers, parameter1) / getRegisterValue(registers, parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}
}

unsigned int executeMOD(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used, int line){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2, registers_used);

	// Get the result of the operation
	int result = getRegisterValue(registers, parameter1) % getRegisterValue(registers, parameter2);

	// Check if the result is negative
	if (result < 0){

		// Print an error message
		printf("\e[1;1H\e[2J");
		printf("Error at line %d: The result of an operation can't be a negative number\n", line);
		exit(1);
	}

	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Divide the value of the first parameter by the value of the second parameter
		unsigned int value = getRegisterValue(registers, parameter1) % atoi(parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}

	// If the second parameter is a register
	else{

		// Divide the value of the first parameter by the value of the second parameter
		unsigned int value = getRegisterValue(registers, parameter1) % getRegisterValue(registers, parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}
}

unsigned int executeSQR(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2, registers_used);

	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Divide the value of the first parameter by the value of the second parameter
		unsigned int value = (unsigned int)sqrt(atoi(parameter2));

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}

	// If the second parameter is a register
	else{

		// Divide the value of the first parameter by the value of the second parameter
		unsigned int value = (unsigned int)sqrt(getRegisterValue(registers, parameter2));

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}
}


void *executeMOV(char *parameter1, char *parameter2, reg_t *regs, used_t *registers_used){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2, registers_used);

	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Change the value of the first parameter to the value of the second parameter
		changeRegister((unsigned int)atoi(parameter2), regs, parameter1);
	}

	// If the second parameter is a register
	else{

		// Change the value of the first parameter to the value of the second parameter
		changeRegister(getRegisterValue(regs, parameter2), regs, parameter1);
	}
}


unsigned int executeCMP(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used){

	// Check if the parameters are registers
	int isRegister1 = isRegister(parameter1, registers_used);
	int isRegister2 = isRegister(parameter2, registers_used);


	// If the parameters are not registers
	if (isRegister1 == 0 && isRegister2 == 0){

		// Compare the two parameters
		if (atoi(parameter1) == atoi(parameter2)){

			// Return 1 if the first parameter is equal to the second
			return 1;
		}
		else if (atoi(parameter1) > atoi(parameter2)){

			// Return 2 if the first parameter is greater than the second
			return 2;
		}
		else if (atoi(parameter1) < atoi(parameter2)){

			// Return 3 if the first parameter is lesser than the second
			return 3;
		}
		else{

			// Return 0 if the parameters are not equal, greater, or lesser
			return 0;
		}
	}

	// If the first parameter is not a register and the second parameter is a register
	else if (isRegister1 == 0 && isRegister2 != 0){

		// Compare the two parameters
		if (atoi(parameter1) == getRegisterValue(registers, parameter2)){

			// Return 1 if the first parameter is equal to the second
			return 1;
		}
		else if (atoi(parameter1) > getRegisterValue(registers, parameter2)){

			// Return 2 if the first parameter is greater than the second
			return 2;
		}
		else if (atoi(parameter1) < getRegisterValue(registers, parameter2)){

			// Return 3 if the first parameter is lesser than the second
			return 3;
		}
		else{

			// Return 0 if the parameters are not equal, greater, or lesser
			return 0;
		}
	}

	// If the first parameter is a register and the second parameter is not a register
	else if (isRegister1 != 0 && isRegister2 == 0){

		// Compare the two parameters
		if (getRegisterValue(registers, parameter1) == atoi(parameter2)){

			// Return 1 if the first parameter is equal to the second
			return 1;
		}
		else if (getRegisterValue(registers, parameter1) > atoi(parameter2)){

			// Return 2 if the first parameter is greater than the second
			return 2;
		}
		else if (getRegisterValue(registers, parameter1) < atoi(parameter2)){

			// Return 3 if the first parameter is lesser than the second
			return 3;
		}
		else{

			// Return 0 if the parameters are not equal, greater, or lesser
			return 0;
		}
	}

	// If the first parameter and the second parameter are registers
	else if (isRegister1 != 0 && isRegister2 != 0){

		// Compare the two parameters
		if (getRegisterValue(registers, parameter1) == getRegisterValue(registers, parameter2)){

			// Return 1 if the first parameter is equal to the second
			return 1;
		}
		else if (getRegisterValue(registers, parameter1) > getRegisterValue(registers, parameter2)){

			// Return 2 if the first parameter is greater than the second
			return 2;
		}
		else if (getRegisterValue(registers, parameter1) < getRegisterValue(registers, parameter2)){

			// Return 3 if the first parameter is lesser than the second
			return 3;
		}
		else{

			// Return 0 if the parameters are not equal, greater, or lesser
			return 0;
		}
	}
	else{

		// Return 0 if the parameters are not equal, greater, or lesser
		return 0;
	}

}

void executePRT(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used, VMemory Vmemory[], int line){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Prepare the address given by the value of the parameter 1
	int address = getRegisterValue(registers, parameter1);

	if (getRegisterValue(registers, parameter1) < 0 || getRegisterValue(registers, parameter1) > MAX_VMEMORY){
		printf("\e[1;1H\e[2J");
		printf("Error: Address out of range at line %d\n", line);
		printf("The address shouldn't be over %d\n", MAX_VMEMORY);
		exit(1);
	}

	// Change the value, given by the parameter 2, of the memory at the address given by the parameter 1
	Vmemory[address].vaddress = getRegisterValue(registers, parameter2);

}

void executePRF(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used, VMemory Vmemory[], int line){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Prepare the address given by the value of the parameter 2
	int address = getRegisterValue(registers, parameter2);

	if (address < 0 || address > MAX_VMEMORY){
		printf("\e[1;1H\e[2J");
		printf("Error: Address out of range at line %d\n", line);
		printf("The address shouldn't be over %d\n", MAX_VMEMORY);
		exit(1);
	}

	// Get the value of the second parameter
	unsigned int value_2 = Vmemory[address].vaddress;

	// Change the value of the first parameter to the value of the memory at the address given by the parameter 2
	changeRegister(value_2, registers, parameter1);

}

void executeAND(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Get the value of the first parameter
	unsigned int value_1 = getRegisterValue(registers, parameter1);

	// Get the value of the second parameter
	unsigned int value_2 = getRegisterValue(registers, parameter2);

	// Change the value of the first parameter to the value of the first parameter and the value of the second parameter
	changeRegister(value_1 & value_2, registers, parameter1);
}

void executeOR(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Get the value of the first parameter
	unsigned int value_1 = getRegisterValue(registers, parameter1);

	// Get the value of the second parameter
	unsigned int value_2 = getRegisterValue(registers, parameter2);

	// Change the value of the first parameter to the value of the first parameter or the value of the second parameter
	changeRegister(value_1 | value_2, registers, parameter1);
}

void executeXOR(char *parameter1, char *parameter2, reg_t *registers, used_t *registers_used){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Get the value of the first parameter
	unsigned int value_1 = getRegisterValue(registers, parameter1);

	// Get the value of the second parameter
	unsigned int value_2 = getRegisterValue(registers, parameter2);

	// Change the value of the first parameter to the value of the first parameter xor the value of the second parameter
	changeRegister(value_1 ^ value_2, registers, parameter1);
}

unsigned int executeNOT(char *parameter1, reg_t *registers, used_t *registers_used){

	// Check if the first parameter is a register
	int isRegister1 = isRegister(parameter1, registers_used);

	// Get the value of the first parameter
	unsigned int value_1 = getRegisterValue(registers, parameter1);

	// Change the value of the first parameter to the value of the first parameter not
	changeRegister(~value_1, registers, parameter1);
}


void printRegisters(reg_t *regs, used_t *used){

	printf("============================================================\n");

	if (used->a == 1){
		// Print the value of the register ra
		printf("ra: %d\n", regs->ra);
	}

	if (used->b == 1){
		// Print the value of the register rb
		printf("rb: %d\n", regs->rb);
	}

	if (used->c == 1){
		// Print the value of the register rc
		printf("rc: %d\n", regs->rc);
	}

	if (used->d == 1){
		// Print the value of the register rd
		printf("rd: %d\n", regs->rd);
	}

	if (used->e == 1){
		// Print the value of the register re
		printf("re: %d\n", regs->re);
	}

	if (used->f == 1){
		// Print the value of the register rf
		printf("rf: %d\n", regs->rf);
	}

	if (used->g == 1){
		// Print the value of the register rg
		printf("rg: %d\n", regs->rg);
	}

	if (used->h == 1){
		// Print the value of the register rh
		printf("rh: %d\n", regs->rh);
	}

	if (used->i == 1){
		// Print the value of the register ri
		printf("ri: %d\n", regs->ri);
	}

	if (used->j == 1){
		// Print the value of the register rj
		printf("rj: %d\n", regs->rj);
	}

	if (used->k == 1){
		// Print the value of the register rk
		printf("rk: %d\n", regs->rk);
	}

	if (used->l == 1){
		// Print the value of the register rl
		printf("rl: %d\n", regs->rl);
	}

	if (used->m == 1){
		// Print the value of the register rm
		printf("rm: %d\n", regs->rm);
	}

	if (used->n == 1){
		// Print the value of the register rn
		printf("rn: %d\n", regs->rn);
	}

	if (used->o == 1){
		// Print the value of the register ro
		printf("ro: %d\n", regs->ro);
	}

	if (used->p == 1){
		// Print the value of the register rp
		printf("rp: %d\n", regs->rp);
	}

	if (used->q == 1){
		// Print the value of the register rq
		printf("rq: %d\n", regs->rq);
	}

	if (used->r == 1){
		// Print the value of the register rr
		printf("rr: %d\n", regs->rr);
	}

	if (used->s == 1){
		// Print the value of the register rs
		printf("rs: %d\n", regs->rs);
	}

	if (used->t == 1){
		// Print the value of the register rt
		printf("rt: %d\n", regs->rt);
	}

	if (used->u == 1){
		// Print the value of the register ru
		printf("ru: %d\n", regs->ru);
	}

	if (used->v == 1){
		// Print the value of the register rv
		printf("rv: %d\n", regs->rv);
	}

	if (used->w == 1){
		// Print the value of the register rw
		printf("rw: %d\n", regs->rw);
	}

	if (used->x == 1){
		// Print the value of the register rx
		printf("rx: %d\n", regs->rx);
	}

	if (used->y == 1){
		// Print the value of the register ry
		printf("ry: %d\n", regs->ry);
	}

	if (used->z == 1){
		// Print the value of the register rz
		printf("rz: %d\n", regs->rz);
	}
}
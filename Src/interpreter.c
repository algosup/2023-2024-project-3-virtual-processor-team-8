#include "interpreter.h"




// void redirectToFunction(func_t *func, reg_t *regs){
// 	if (strcmp(func->instruction, "add") == 0){
// 		executeADD(func->parameter1, func->parameter2, regs);
// 	}
// 	else if (strcmp(func->instruction, "sub") == 0){
// 		executeSUB(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "mul") == 0){
// 		executeMUL(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "div") == 0){
// 		executeDIV(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "mov") == 0){
// 		executeMOV(func->parameter1, func->parameter2, regs);
// 	}
// 	else if (strcmp(func->instruction, "jmp") == 0){
// 		executeJMP(func->parameter1);
// 	}
// 	else if (strcmp(func->instruction, "je") == 0){
// 		executeJE(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jne") == 0){
// 		executeJNE(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jz") == 0){
// 		executeJZ(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jnz") == 0){
// 		executeJNZ(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jg") == 0){
// 		executeJG(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jge") == 0){
// 		executeJGE(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jl") == 0){
// 		executeJL(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jle") == 0){
// 		executeJLE(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "call") == 0){
// 		executeCALL(func->parameter1);
// 	}
// 	else if (strcmp(func->instruction, "ret") == 0){
// 		executeRET();
// 	}
// 	else if (strcmp(func->instruction, "cmp") == 0){
// 		executeCMP(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "prf") == 0){
// 		executePRF(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "prt") == 0){
// 		executePRT(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "and") == 0){
// 		executeAND(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "or") == 0){
// 		executeOR(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "xor") == 0){
// 		executeXOR(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "not") == 0){
// 		executeNOT(func->parameter1);
// 	}
// }



int isRegister(char *parameter){

	// Check if the parameter is a register
	if (strcmp(parameter, "ra") == 0){
		return 1;
	}
	else if (strcmp(parameter, "rb") == 0){
		return 1;
	}
	else if (strcmp(parameter, "rc") == 0){
		return 1;
	}
	else if (strcmp(parameter, "rd") == 0){
		return 1;
	}
	else if (parameter[0] == '['){
		return 2;
	}
	else{
		return 0;
	}
}

void *changeRegister(int value, reg_t *regs, char *regist){

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

	// Return the registers
	return regs;
}

int getRegisterValue(reg_t *regs, char *regist){

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
	// Check if the register to get the value from is ra
	else if (strcmp(regist, "[ra]") == 0){

		// Return the value of the register ra
		return regs->ra;
	}

	// Check if the register to get the value from is rb
	else if (strcmp(regist, "[rb]") == 0){

		// Return the value of the register rb
		return regs->rb;
	}

	// Check if the register to get the value from is rc
	else if (strcmp(regist, "[rc]") == 0){

		// Return the value of the register rc
		return regs->rc;
	}

	// Check if the register to get the value from is rd
	else if (strcmp(regist, "[rd]") == 0){

		// Return the value of the register rd
		return regs->rd;
	}
}

int executeADD(char *parameter1, char *parameter2, reg_t *registers){

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2);


	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Add the value of the second parameter to the value of the first parameter
		int value = getRegisterValue(registers, parameter1) + atoi(parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}

	// If the second parameter is a register
	else{

		// Add the value of the second parameter to the value of the first parameter
		int value = getRegisterValue(registers, parameter1) + getRegisterValue(registers, parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}
}

int executeSUB(char *parameter1, char *parameter2, reg_t *registers){

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2);

	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Subtract the value of the second parameter from the value of the first parameter
		int value = getRegisterValue(registers, parameter1) - atoi(parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}

	// If the second parameter is a register
	else{

		// Subtract the value of the second parameter from the value of the first parameter
		int value = getRegisterValue(registers, parameter1) - getRegisterValue(registers, parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}
}

int executeMUL(char *parameter1, char *parameter2, reg_t *registers){

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2);


	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Multiply the value of the first parameter by the value of the second parameter
		int value = getRegisterValue(registers, parameter1) * atoi(parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}

	// If the second parameter is a register
	else{

		// Multiply the value of the first parameter by the value of the second parameter
		int value = getRegisterValue(registers, parameter1) * getRegisterValue(registers, parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}
}

int executeDIV(char *parameter1, char *parameter2, reg_t *registers){

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2);

	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Divide the value of the first parameter by the value of the second parameter
		int value = getRegisterValue(registers, parameter1) / atoi(parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}

	// If the second parameter is a register
	else{

		// Divide the value of the first parameter by the value of the second parameter
		int value = getRegisterValue(registers, parameter1) / getRegisterValue(registers, parameter2);

		// Change the value of the first parameter to the new value
		changeRegister(value, registers, parameter1);

		// Return the value
		return value;
	}
}


void *executeMOV(char *parameter1, char *parameter2, reg_t *regs){

	// Check if the second parameter is a register
	int isRegister2 = isRegister(parameter2);

	// If the second parameter is not a register
	if (isRegister2 == 0){

		// Change the value of the first parameter to the value of the second parameter
		changeRegister(atoi(parameter2), regs, parameter1);
	}

	// If the second parameter is a register
	else{

		// Change the value of the first parameter to the value of the second parameter
		changeRegister(getRegisterValue(regs, parameter2), regs, parameter1);
	}
}


int executeCMP(char *parameter1, char *parameter2, reg_t *registers){

	// Check if the parameters are registers
	int isRegister1 = isRegister(parameter1);
	int isRegister2 = isRegister(parameter2);


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

void executePRT(char *parameter1, char *parameter2, reg_t *registers){

	// Get the value of the first parameter
	int value_1 = getRegisterValue(registers, parameter1);

	// Get the value of the second parameter that is an address
	int address_2 = getRegisterValue(registers, parameter2);

	// Get the value of the register at the address
	int value_2 = *(int *)address_2;

	// Change the value of the register at the address to the value of the first parameter
	changeRegister(value_2, registers, parameter1);

}

void executePRF(char *parameter1, char *parameter2, reg_t *registers){

	// Get the value of the first parameter that is an address
	int address_1 = getRegisterValue(registers, parameter1);

	// Get the value of the second parameter
	int value_2 = getRegisterValue(registers, parameter2);

	// Get the value of the register at the address
	int *value_1 = (int *)address_1;

	// Change the value of the first parameter to the value of the second parameter
	*value_1 = value_2;

}
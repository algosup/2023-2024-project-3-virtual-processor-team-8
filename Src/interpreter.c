#include "interpreter.h"




// void redirectToFunction(func_t *func, reg_t *regs){
// 	if (strcmp(func->instruction, "add") == 0){
// 		executeADD(func->parameter1, func->parameter2, regs);
// 	}
// 	else if (strcmp(func->instruction, "sub") == 0){
// 		subtract(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "mul") == 0){
// 		multiply(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "div") == 0){
// 		divide(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "mov") == 0){
// 		executeMOV(func->parameter1, func->parameter2, regs);
// 	}
// 	else if (strcmp(func->instruction, "jmp") == 0){
// 		jump(func->parameter1);
// 	}
// 	else if (strcmp(func->instruction, "je") == 0){
// 		je(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jne") == 0){
// 		jne(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jz") == 0){
// 		jz(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jnz") == 0){
// 		jnz(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jg") == 0){
// 		jg(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jge") == 0){
// 		jge(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jl") == 0){
// 		jl(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "jle") == 0){
// 		jle(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "call") == 0){
// 		call(func->parameter1);
// 	}
// 	else if (strcmp(func->instruction, "ret") == 0){
// 		returns();
// 	}
// 	else if (strcmp(func->instruction, "cmp") == 0){
// 		compare(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "prf") == 0){
// 		pointerFrom(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "prt") == 0){
// 		PointerTo(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "and") == 0){
// 		AND(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "or") == 0){
// 		OR(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "xor") == 0){
// 		XOR(func->parameter1, func->parameter2);
// 	}
// 	else if (strcmp(func->instruction, "not") == 0){
// 		NOT(func->parameter1);
// 	}
// }


int isRegister(char *parameter){
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
	else{
		return 0;
	}
}

void *changeRegister(int value, reg_t *regs, char *regist){
	if (strcmp(regist, "ra") == 0){
		regs->ra = value;

	}
	else if (strcmp(regist, "rb") == 0){
		regs->rb = value;
	}
	else if (strcmp(regist, "rc") == 0){
		regs->rc = value;
	}
	else if (strcmp(regist, "rd") == 0){
		regs->rd = value;
	}
	return regs;
}

int getRegisterValue(reg_t *regs, char *regist){
	if (strcmp(regist, "ra") == 0){
		return regs->ra;
	}
	else if (strcmp(regist, "rb") == 0){
		return regs->rb;
	}
	else if (strcmp(regist, "rc") == 0){
		return regs->rc;
	}
	else if (strcmp(regist, "rd") == 0){
		return regs->rd;
	}
}

int executeADD(char *parameter1, char *parameter2, reg_t *registers){

	int isRegister2 = isRegister(parameter2);

	if (isRegister2 == 0){
		int value = getRegisterValue(registers, parameter1) + atoi(parameter2);
		changeRegister(value, registers, parameter1);
		return value;
	}
	else{
		int value = getRegisterValue(registers, parameter1) + getRegisterValue(registers, parameter2);
		changeRegister(value, registers, parameter1);
		return value;
	}
}

int executeADD(char *parameter1, char *parameter2, reg_t *registers){

	int isRegister2 = isRegister(parameter2);

	if (isRegister2 == 0){
		int value = getRegisterValue(registers, parameter1) + atoi(parameter2);
		changeRegister(value, registers, parameter1);
		return value;
	}
	else{
		int value = getRegisterValue(registers, parameter1) + getRegisterValue(registers, parameter2);
		changeRegister(value, registers, parameter1);
		return value;
	}
}

int executeSUB(char *parameter1, char *parameter2, reg_t *registers){

}

int executeMUL(char *parameter1, char *parameter2, reg_t *registers){

}

int executeDIV(char *parameter1, char *parameter2, reg_t *registers){

}


void *executeMOV(char *parameter1, char *parameter2, reg_t *regs){

	int isRegister2 = isRegister(parameter2);

	if (isRegister2 == 0){
		changeRegister(atoi(parameter2), regs, parameter1);
	}
	else{
		changeRegister(getRegisterValue(regs, parameter2), regs, parameter1);
	}
}
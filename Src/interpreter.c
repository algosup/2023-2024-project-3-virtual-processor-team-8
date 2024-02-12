#include "interpreter.h"

typedef struct reg{
	int ra;
	int rb;
	int rc;
	int rd;
}reg_t;

reg_t regs = {0, 0, 0, 0};


void redirectToFunction(func_t *func){
	if (strcmp(func->instruction, "add") == 0){
		add(func->parameter1, func->parameter2, &regs);
	}
	else if (strcmp(func->instruction, "sub") == 0){
		subtract(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "mul") == 0){
		multiply(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "div") == 0){
		divide(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "mov") == 0){
		move(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "jmp") == 0){
		jump(func->parameter1);
	}
	else if (strcmp(func->instruction, "je") == 0){
		je(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "jne") == 0){
		jne(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "jz") == 0){
		jz(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "jnz") == 0){
		jnz(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "jg") == 0){
		jg(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "jge") == 0){
		jge(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "jl") == 0){
		jl(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "jle") == 0){
		jle(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "call") == 0){
		calling(func->parameter1);
	}
	else if (strcmp(func->instruction, "ret") == 0){
		returns();
	}
	else if (strcmp(func->instruction, "cmp") == 0){
		compare(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "prf") == 0){
		pointerFrom(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "prt") == 0){
		PointerTo(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "and") == 0){
		AND(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "or") == 0){
		OR(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "xor") == 0){
		XOR(func->parameter1, func->parameter2);
	}
	else if (strcmp(func->instruction, "not") == 0){
		NOT(func->parameter1);
	}
}


int add(char *parameter1, char *parameter2, reg_t *registers){

	int isRegister1 = isRegister(parameter1);
	int isRegister2 = isRegister(parameter2);


	if (isRegister1 !=0 && isRegister2 == 0){
		int p2 = getRegister(parameter2);
		registers->ra += p2;
	}
	else if (isRegister1 == 0 && isRegister2 != 0){
		int p1 = getRegister(parameter1);
		registers->ra += p1;
	}
	else{
		int p1 = getRegister(parameter1);
		int p2 = getRegister(parameter2);
		registers->ra += registers->rb;
	}
	return 0;
}
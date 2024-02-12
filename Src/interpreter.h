#include <stdbool.h>


typedef struct reg{
	int ra;
	int rb;
	int rc;
	int rd;
}reg_t;


void redirectToFunction(func_t *func);

int isRegister(char *parameter);

void *changeRegister(int value, reg_t *regs, char *regist);

int getRegisterValue(reg_t *regs, char *regist);

int executeADD(char *parameter1, char *parameter2, reg_t *registers);




void *executeMOV(char *parameter1, char *parameter2, reg_t *regs);
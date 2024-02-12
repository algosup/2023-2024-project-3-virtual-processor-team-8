#include "tests_interpreter.h"


int executeADDTEST(){
	reg_t registers = {5, 34, 90, 8};


	assert(executeADD("ra", "6", &registers) == 11);
	assert(executeADD("rb", "12", &registers) == 46);
	assert(executeADD("rc", "23", &registers) == 113);
	assert(executeADD("rd", "1", &registers) == 9);
	
	
	assert(executeADD("rd", "ra", &registers) == 20);


	return 5;
}


int executeSUBTEST(){
	reg_t registers = {35, 334, 390, 38};


	assert(executeSUB("ra", "12", &registers) == 13);
	assert(executeSUB("rb", "34", &registers) == 300);
	assert(executeSUB("rc", "45", &registers) == 345);
	assert(executeSUB("rd", "3", &registers) == 35);
	
	
	assert(executeSUB("rd", "ra", &registers) == 12);


	return 5;
}


int executeMULTEST(){
	reg_t registers = {5, 34, 90, 8};


	assert(executeMUL("ra", "3", &registers) == 15);
	assert(executeMUL("rb", "2", &registers) == 68);
	assert(executeMUL("rc", "5", &registers) == 450);
	assert(executeMUL("rd", "8", &registers) == 64);
	
	
	assert(executeMUL("rd", "ra", &registers) == 960);


	return 5;
}


int executeDIVTEST(){
	reg_t registers = {10, 34, 90, 8};


	assert(executeDIV("ra", "5", &registers) == 2);
	assert(executeDIV("rb", "2", &registers) == 17);
	assert(executeDIV("rc", "9", &registers) == 10);
	assert(executeDIV("rd", "2", &registers) == 4);
	
	
	assert(executeDIV("rd", "ra", &registers) == 2);


	return 5;
}

int executeMOVTEST(){
	reg_t registers = {5, 34, 90, 8};

	executeMOV("ra", "8", &registers);
	executeMOV("rb", "12", &registers);
	executeMOV("rc", "45", &registers);
	executeMOV("rd", "67", &registers);

	assert(registers.ra == 8);
	assert(registers.rb == 12);
	assert(registers.rc == 45);
	assert(registers.rd == 67);

	executeMOV("rc", "rd", &registers);

	assert(registers.rc == 67);

	return 5;
}
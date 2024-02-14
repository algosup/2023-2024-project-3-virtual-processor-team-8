#include "tests_interpreter.h"


int executeADDTEST(){

	// Define registers to test
	reg_t registers = {5, 34, 90, 8};


	// Test the function
	assert(executeADD("ra", "6", &registers) == 11);
	assert(executeADD("rb", "12", &registers) == 46);
	assert(executeADD("rc", "23", &registers) == 113);
	assert(executeADD("rd", "1", &registers) == 9);

	// Test the function with a register as the second parameter
	assert(executeADD("rd", "ra", &registers) == 20);


	return 5;
}


int executeSUBTEST(){

	// Define registers to test
	reg_t registers = {35, 334, 390, 38};


	// Test the function
	assert(executeSUB("ra", "12", &registers) == 23);
	assert(executeSUB("rb", "34", &registers) == 300);
	assert(executeSUB("rc", "45", &registers) == 345);
	assert(executeSUB("rd", "3", &registers) == 35);

	// Test the function with a register as the second parameter
	assert(executeSUB("rd", "ra", &registers) == 12);


	return 5;
}


int executeMULTEST(){

	// Define registers to test
	reg_t registers = {5, 34, 90, 8};


	// Test the function
	assert(executeMUL("ra", "3", &registers) == 15);
	assert(executeMUL("rb", "2", &registers) == 68);
	assert(executeMUL("rc", "5", &registers) == 450);
	assert(executeMUL("rd", "8", &registers) == 64);

	// Test the function with a register as the second parameter
	assert(executeMUL("rd", "ra", &registers) == 960);


	return 5;
}


int executeDIVTEST(){

	// Define registers to test
	reg_t registers = {10, 34, 90, 8};


	// Test the function
	assert(executeDIV("ra", "5", &registers) == 2);
	assert(executeDIV("rb", "2", &registers) == 17);
	assert(executeDIV("rc", "9", &registers) == 10);
	assert(executeDIV("rd", "2", &registers) == 4);

	// Test the function with a register as the second parameter
	assert(executeDIV("rd", "ra", &registers) == 2);


	return 5;
}

int executeMOVTEST(){

	// Define registers to test
	reg_t registers = {5, 34, 90, 8};


	// Execute the function
	executeMOV("ra", "8", &registers);
	executeMOV("rb", "12", &registers);
	executeMOV("rc", "45", &registers);
	executeMOV("rd", "67", &registers);

	// Check the results
	assert(registers.ra == 8);
	assert(registers.rb == 12);
	assert(registers.rc == 45);
	assert(registers.rd == 67);


	// Execute the function with a register as the second parameter
	executeMOV("rc", "rd", &registers);

	// Check the results
	assert(registers.rc == 67);

	return 5;
}


int executeCMPTEST(){

	// 1 if the first parameter is equal to the second.
	// 2 if the first parameter is greater than the second.
	// 3 if the first parameter is lesser than the second.


	// Define registers to test
	reg_t registers = {5, 34, 90, 8};


	// Test the function
	assert(executeCMP("ra", "5", &registers) == 1);
	assert(executeCMP("rb", "12", &registers) == 2);
	assert(executeCMP("rc", "45", &registers) == 2);
	assert(executeCMP("rd", "67", &registers) == 3);

	// Test the function with a register as the second parameter
	assert(executeCMP("ra", "rd", &registers) == 3);
	assert(executeCMP("rb", "ra", &registers) == 2);
	assert(executeCMP("rc", "rb", &registers) == 2);
	assert(executeCMP("rd", "rc", &registers) == 3);

	return 8;
}

int executePRTTEST(){

	// Define registers to test
	reg_t registers = {5, 0, 90, 8};

	// Set the values of the registers
	changeRegister( (int)&registers.ra, &registers, "rb");


	// Test the function
	executePRT("ra", "[rb]", &registers);
	executePRT("rc", "[rb]", &registers);
	executePRT("rd", "[rb]", &registers);

	// Check the results
	assert(registers.ra == 5);
	assert(registers.rc == 5);
	assert(registers.rd == 5);

	return 4;
}

int executePRFTEST(){
	
	// Define registers to test
	reg_t registers = {5, 0, 90, 8};



	// Set the values of the registers
	changeRegister( (int)&registers.rd, &registers, "ra");

	// Test the function
	executePRF("[ra]", "rc", &registers);



	// Set the values of the registers
	changeRegister( (int)&registers.rc, &registers, "ra");

	// Test the function
	executePRF("[ra]", "rb", &registers);


	// Check the results
	assert(registers.rb == 0);
	assert(registers.rc == 0);
	assert(registers.rd == 90);

	return 3;
}

int executeANDTEST(){

	// Define registers to test
	reg_t registers = {15, 34, 90, 8};

	// Test the function
	executeAND("ra", "15", &registers);

	assert(registers.ra == 15);

	// Test the function
	executeAND("ra", "rc", &registers);

	// Check the results
	assert(registers.ra == 10);
	assert(registers.rc == 90);

	return 3;
}

int executeORTEST(){

	// Define registers to test
	reg_t registers = {15, 34, 90, 8};

	// Test the function
	executeOR("ra", "15", &registers);

	assert(registers.ra == 15);

	// Test the function
	executeOR("ra", "rc", &registers);

	// Check the results
	assert(registers.ra == 95);
	assert(registers.rc == 90);

	return 3;
}

int executeXORTEST(){

	// Define registers to test
	reg_t registers = {15, 34, 90, 8};

	// Test the function
	executeXOR("ra", "15", &registers);

	assert(registers.ra == 0);

	// Test the function
	executeXOR("ra", "rc", &registers);

	// Check the results
	assert(registers.ra == 90);
	assert(registers.rc == 90);

	return 3;
}

int executeNOTTEST(){

	// Define registers to test
	reg_t registers = {15, 34, 90, 8};

	// Test the function
	executeNOT("ra", &registers);

	printf("%d\n", registers.ra);

	assert(registers.ra == 0);

	// Test the function
	executeNOT("rc", &registers);

	// Check the results
	assert(registers.rc == 37);

	return 2;
}
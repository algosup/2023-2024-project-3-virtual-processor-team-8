#include "tests_interpreter.h"


int addTEST(){
	reg_t registers = {5, 34, 90, 8};


	assert(add("ra", "6", &registers) == 11);
	assert(add("rb", "12", &registers) == 46);
	assert(add("rc", "23", &registers) == 113);
	assert(add("rd", "1", &registers) == 9);
	
	
	assert(add("rd", "ra", &registers) == 20);


	return 5;
}
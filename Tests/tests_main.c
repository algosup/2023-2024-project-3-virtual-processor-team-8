#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tests_main.h"


int main() {

	const char *file = "../Src/code.asm";

	int testsPassed = 0;

	printf("Running tests...\n");


	printf("====================================================\n");


	printf("testing function getFile\n");

	testsPassed += getFileTEST(file);

	printf("... testing getFileTEST ...\n");
	printf("all getFile's tests passed!\n");


	printf("====================================================\n");


	printf("testing function getLine\n");
	printf("... testing getLineTEST ...\n");

	testsPassed += getLineTEST(file);

	printf("all getLine's tests passed!\n");


	printf("====================================================\n");


	printf("testing function getSize\n");
	printf("... testing getSizeTEST ...\n");

	testsPassed += getSizeTEST(file);

	printf("all getSize's tests passed!\n");


	printf("====================================================\n");


	printf("testing function getStructs\n");
	printf("... testing getStructsTEST ...\n");

	testsPassed += getStructsTEST(file);

	printf("all getStructs's tests passed!\n");


	printf("====================================================\n");


	printf("testing function switchStr\n");
	printf("... testing switchStrTEST ...\n");

	testsPassed += switchStrTEST();

	printf("all switchStr's tests passed!\n");


	printf("====================================================\n");


	printf("testing function setStruct\n");
	printf("... testing setStructTEST ...\n");

	testsPassed += setStructTEST();

	printf("all setStruct's tests passed!\n");


	printf("====================================================\n");



	printf("%d tests passed!\n", testsPassed);
	return 0;
}
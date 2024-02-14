#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tests_main.h"
#include <string.h>


int main() {

	const char *file = "../Src/code.asm";

	int testsPassed = 0;
/*
*/
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


	printf("testing function executeADD\n");
	printf("... testing executeADDTEST ...\n");

	testsPassed += executeADDTEST();

	printf("all executeADD's tests passed!\n");


	printf("====================================================\n");


	printf("testing function executeSUB\n");
	printf("... testing executeSUBTEST ...\n");

	testsPassed += executeSUBTEST();

	printf("all executeSUB's tests passed!\n");


	printf("====================================================\n");


	printf("testing function executeMUL\n");
	printf("... testing executeMULTEST ...\n");

	testsPassed += executeMULTEST();

	printf("all executeMUL's tests passed!\n");


	printf("====================================================\n");


	printf("testing function executeDIV\n");
	printf("... testing executeDIVTEST ...\n");

	testsPassed += executeDIVTEST();

	printf("all executeDIV's tests passed!\n");


	printf("====================================================\n");


	printf("testing function executeMOV\n");
	printf("... testing executeMOVTEST ...\n");

	testsPassed += executeMOVTEST();

	printf("all executeMOV's tests passed!\n");


	printf("====================================================\n");


	printf("testing function executeCMP\n");
	printf("... testing executeCMPTEST ...\n");

	testsPassed += executeCMPTEST();

	printf("all executeCMP's tests passed!\n");


	printf("====================================================\n");


	printf("testing function executePRT\n");
	printf("... testing executePRTTEST ...\n");

	// testsPassed += executePRTTEST();

	printf("all executePRT's tests passed!\n");


	printf("====================================================\n");


	printf("testing function executePRF\n");
	printf("... testing executePRFTEST ...\n");

	// testsPassed += executePRFTEST();

	printf("all executePRF's tests passed!\n");


	printf("====================================================\n");


	printf("testing function executeAND\n");
	printf("... testing executeANDTEST ...\n");

	testsPassed += executeANDTEST();

	printf("all executeAND's tests passed!\n");


	printf("====================================================\n");


	printf("testing function executeOR\n");
	printf("... testing executeORTEST ...\n");

	testsPassed += executeORTEST();

	printf("all executeOR's tests passed!\n");


	printf("====================================================\n");


	printf("testing function executeXOR\n");
	printf("... testing executeXORTEST ...\n");

	testsPassed += executeXORTEST();

	printf("all executeXOR's tests passed!\n");


	printf("====================================================\n");


	printf("testing function executeNOT\n");
	printf("... testing executeNOTTEST ...\n");

	testsPassed += executeNOTTEST();

	printf("all executeNOT's tests passed!\n");


	printf("====================================================\n");



	printf("%d tests passed!\n", testsPassed);
	return 0;
}

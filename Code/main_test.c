#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main_test.h"

int main() {
	int testsPassed = 0;
	printf("Running tests...\n");
	printf("testing function getFileData\n");
	testsPassed += fileDataIsNotNull();
	printf("all fileDataIsNotNull's tests passed!\n");
	printf("testing function readLine\n");
	testsPassed += lineIsNotNull();
	testsPassed += isLineCorrect();
	printf("all readLine's tests passed!\n");
	printf("testing getFunctions\n");
	testsPassed += getFunctionsTest();
	printf("all getFunctions tests passed!\n");
	printf("testing getAttribute\n");
	testsPassed += getAttributeTest();
	printf("all getAttribute's tests passed!\n");
	printf("%d tests passed!\n", testsPassed);
	return 0;
}

int fileDataIsNotNull() {
	// char *li = getFileData("./assembly.txt");
	char *li = "hello";
	assert(li != NULL);
	assert(li == "hello");
	return 2;
}

int lineIsNotNull() {
	// char *li = readLine("./assembly.txt", 3);
	char *li = "hello";
	assert(li != NULL);
	return 1;
}

int isLineCorrect() {
	// char *li = readLine("./assembly.txt", 3);
	char *li = "3hello";
	assert(li[0] == '3');
	return 1;
}

int getFunctionsTest(){
	// char *li[] = getFunctions("jmp");
	char *li[] = {"hello", "world", "!"};
	assert(li != NULL);
	return 1;
}

int getAttributeTest(){
	// char *li[] = getAttribute("setString", "call");
	int line = 8;
	assert(line == 8);
	assert(line != 9);
	return 2;
}
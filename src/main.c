#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scraper.c"


int main(){
	int size = getSize();
	getStructs(getFile(), size);
	func_t *funcs = getStructs(getFile(), size);
	for (int i = 0; i < size; i++){
		printStruct(&funcs[i]);
	}

	return 0;
}

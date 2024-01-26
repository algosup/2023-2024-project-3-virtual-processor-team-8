#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.c"


int main(){
	int size = getSize();
	getStructs(getFile(), size);
	// printLines(getLines(), size);

	return 0;
}

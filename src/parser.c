#include "parser.h"


void printLines(char **lines, int size){
	int i = 0;
	while(i < size){
		printf("%s\n", lines[i]);
		i++;
	}
}

void *getLines(){
	char **lines = (char **)malloc(100 * sizeof(char *));
	int linesNum = 0;



	FILE *fp;

	char ch;
	fp = fopen("./assembly.asm", "r");
	if(fp == NULL){
		printf("Error opening file\n");
		exit(1);
	}
	else{
		int line = 1;
		char *lineContent = (char *)malloc(100 * sizeof(char));
		lineContent[0] = '\0';
		while((ch = fgetc(fp)) != EOF){
			if (ch == '\n' || ch == '\r'){
				if (lineContent[0] != '\0'){
					lines[line] = (char *)malloc(100 * sizeof(char));
					strcpy(lines[line-1], lineContent);
				}
				lineContent[0] = '\0';
				line++;
			}
			else{
				if (ch != '\t'){
				strncat(lineContent, &ch, 1);
				}
			}

		}
		if (ch == EOF && lineContent[0] != '\0'){
			lines[line] = (char *)malloc(100 * sizeof(char));
			strcpy(lines[line-1], lineContent);
		}
		linesNum = line;
	}
	return lines;
	fclose(fp);
}

int getSize(){
// count the number of lines in the file called filename                                    
	FILE *fp = fopen("./assembly.asm","r");
	int ch=0;
	int lines=0;
	
	if (fp == NULL){
		return 0;
	}
	
	lines++;
	while ((ch = fgetc(fp)) != EOF){
	if (ch == '\n'){
		lines++;
	}
	}
	fclose(fp);
	return lines;
}

void *getStructs(char **lines, int size){
	int i = 0;
	char *str = (char *)malloc(10 * sizeof(char));
	str[0] = '\0';
	while(i < size){
		char *line = lines[i];
		for (int j = 0; j < strlen(line); j++){
			if (line[j] == ' ' || line[j] == ',' || line[j] == '\n'){
				if (str != NULL){
					switch (switchStr(str)){
						case 1:
							printf("Instruction: %s\n", str);
							break;
						case 2:
							printf("Register: %s\n", str);
							break;
						case 3:
							printf("Value: %s\n", str);
							break;
						default:
							printf("Error: %s\n", str);
							break;
					}
				}
				str[0] = '\0';
			}
			else if (line[j] == ':'){
				str[0] = '\0';
			}
			else {
				strncat(str, &line[j], 1);
			}
		}
		i++;
		str[0] = '\0';
	}
}

int switchStr(char *str){
	if (str == NULL){
		return 0;
	}
	else if (str == "mov" || str == "prf" || str == "prt" || str == "cmp" || str == "jmp" || str == "je"  || str == "jne" || str == "jz" || str == "jnz" || str == "jg" || str == "jl" || str == "jge" || str == "jle"|| str == "call" || str == "ret" || str == "add" || str == "sub" || str == "mul" || str == "div" || str == "and" || str == "or" || str == "xor" || str == "not"){
		return 1;
	}
	else if (str == "ra" || str == "rb" || str == "rc" || str == "rd"){
		return 2;
	}
	else {
		printf("Eror1: %s\n", str);
		return 3;
	}
}
#include "scraper.h"



void printLines(char **lines, int size){
	int i = 0;
	while(i < size){
		printf("%s\n", lines[i]);
		i++;
	}
}

void *getFile(){
	char **lines = (char **)malloc(100 * sizeof(char *));



	FILE *fp;

	char ch;
	fp = fopen("./assembly.asm", "r");
	if(fp == NULL){
		printf("Error opening file\n");
		exit(1);
	}
	else{
		int line = 0;
		char *lineContent = (char *)malloc(100 * sizeof(char));
		lineContent[0] = '\0';
		while((ch = fgetc(fp)) != EOF){
			if (ch == '\n' || ch == '\r'){
				if (lineContent[0] != '\0'){
					lines[line] = (char *)malloc(100 * sizeof(char));
					strncat(lineContent, &ch, 1);
					strcpy(lines[line], lineContent);
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
			char c = '\n';
			strncat(lineContent, &c, 1);
			strcpy(lines[line], lineContent);
		}
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
	func_t *functions = malloc(size * sizeof(func_t));
	int i = 0;
	char *str = (char *)malloc(100 * sizeof(char));
	str[0] = '\0';
	while(i < size){
		struct function *func = malloc(sizeof(struct function));
		setStruct(func, "\0", "", "", "", 0);
		int reg = 0;
		const char *line = lines[i];
		for (int j = 0; j < strlen(line); j++){
			if (line[j] == ' ' || line[j] == ',' || line[j] == '\n'){
				if (str != NULL && strcmp(str, "") != 0 ){
					int strType = switchStr(str);
					if (strType == 1){
						setStruct(func, str, func->name, func->parameter1, func->parameter2, func->line);
					}
					else if (strType == 2){
						if (reg == 0){
							setStruct(func, func->instruction, func->name, str, func->parameter2, func->line);
							reg++;
						}
						else{
							setStruct(func, func->instruction, func->name, func->parameter1, str, func->line);
						}
					}
					else if (strType == 3){
						if (reg == 0){
							setStruct(func, func->instruction, func->name, str, func->parameter2, func->line);
							reg++;
						}
						else{
							setStruct(func, func->instruction, func->name, func->parameter1, str, func->line);
						}
					}
					else {
					}
				}
				str[0] = '\0';
			}
			else if (line[j] == ':'){
				setStruct(func, func->instruction, str, func->parameter1, func->parameter2, func->line);
				str[0] = '\0';
			}
			else {
				strncat(str, &line[j], 1);
			}
		}
		setStruct(func, func->instruction, func->name, func->parameter1, func->parameter2, i+1);
		// printStruct(func);
		functions[i] = *func;
		i++;
		str[0] = '\0';
	}
	return functions;
}

int switchStr(char *str){
	// String is null
	if (str == NULL){
		return 0;
	}
	else if (strcmp(str, "") == 0){
		return 0;
	}
	else if (strcmp(str, "\n") == 0){
		return 0;
	}


	// string is an instruction
	else if (strcmp(str, "mov") == 0){
		return 1;
	}
	else if (strcmp(str, "prf") == 0){
		return 1;
	}
	else if (strcmp(str, "prt") == 0){
		return 1;
	}
	else if (strcmp(str, "cmp") == 0){
		return 1;
	}
	else if (strcmp(str, "jmp") == 0){
		return 1;
	}
	else if (strcmp(str, "je") == 0){
		return 1;
	}
	else if (strcmp(str, "jne") == 0){
		return 1;
	}
	else if (strcmp(str, "jz") == 0){
		return 1;
	}
	else if (strcmp(str, "jnz") == 0){
		return 1;
	}
	else if (strcmp(str, "jg") == 0){
		return 1;
	}
	else if (strcmp(str, "jl") == 0){
		return 1;
	}
	else if (strcmp(str, "jge") == 0){
		return 1;
	}
	else if (strcmp(str, "jle") == 0){
		return 1;
	}
	else if (strcmp(str, "call") == 0){
		return 1;
	}
	else if (strcmp(str, "ret") == 0){
		return 1;
	}
	else if (strcmp(str, "add") == 0){
		return 1;
	}
	else if (strcmp(str, "sub") == 0){
		return 1;
	}
	else if (strcmp(str, "mul") == 0){
		return 1;
	}
	else if (strcmp(str, "div") == 0){
		return 1;
	}
	else if (strcmp(str, "and") == 0){
		return 1;
	}
	else if (strcmp(str, "or") == 0){
		return 1;
	}
	else if (strcmp(str, "xor") == 0){
		return 1;
	}
	else if (strcmp(str, "not") == 0){
		return 1;
	}

	// String is a register
	else if (strcmp(str, "ra") == 0){
		return 2;
	}
	else if (strcmp(str, "rb") == 0){
		return 2;
	}
	else if (strcmp(str, "rc") == 0){
		return 2;
	}
	else if (strcmp(str, "rd") == 0){
		return 2;
	}

	else if (str[0] == '['){
		return 2;
	}

	// String is a number
	else {
		return 3;
	}
}




void setStruct(struct function *f, char *instruct, char *Name, char *param1, char *param2, int line){
	strcpy(f->instruction, instruct);
	strcpy(f->name, Name);
	strcpy(f->parameter1, param1);
	strcpy(f->parameter2, param2);
	f->line = line;
}

void printStruct(struct function *f){
	printf("==========================================================\n");
	printf("Instruction: %s\n", f->instruction);
	printf("Name: %s\n", f->name);
	printf("Parameter 1: %s\n", f->parameter1);
	printf("Parameter 2: %s\n", f->parameter2);
	printf("Line: %d\n", f->line);
}
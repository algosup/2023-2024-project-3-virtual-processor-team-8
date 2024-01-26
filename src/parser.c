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
	return NULL;
}

int switchStr(char *str){
	if (str == NULL){
		return 0;
	}
	else if (strcmp(str, "mov") == 0 || strcmp(str, "prf") == 0 || strcmp(str, "prt") == 0 || strcmp(str, "cmp") == 0 || strcmp(str, "jmp") == 0 || strcmp(str, "je") == 0  || strcmp(str, "jne") == 0 || strcmp(str, "jz") == 0 || strcmp(str, "jnz") == 0 || strcmp(str, "jg") == 0 || strcmp(str, "jl") == 0 || strcmp(str, "jge") == 0 || strcmp(str, "jle") == 0 || strcmp(str, "call") == 0 || strcmp(str, "ret") == 0 || strcmp(str, "add") == 0 || strcmp(str, "sub") == 0 || strcmp(str, "mul") == 0 || strcmp(str, "div") == 0 || strcmp(str, "and") == 0 || strcmp(str, "or") == 0 || strcmp(str, "xor") == 0 || strcmp(str, "not") == 0){
        return 1;
    }
    else if (strcmp(str, "ra") == 0 || strcmp(str, "rb") == 0 || strcmp(str, "rc") == 0 || strcmp(str, "rd") == 0){
        return 2;
	}
	else {
		printf("Error1: %s\n", str);
		return 3;
	}
}
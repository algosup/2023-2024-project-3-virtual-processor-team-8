#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLines(char **lines, int linesNum);



int main(){
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
		linesNum = line;
	}
	printLines(lines, linesNum);
	fclose(fp);
}

void printLines(char **lines, int linesNum){
	int i = 0;
	while(i < linesNum-1){
		printf("%s\n", lines[i]);
		i++;
	}
	// printf("%s\n", lines[0]);
}
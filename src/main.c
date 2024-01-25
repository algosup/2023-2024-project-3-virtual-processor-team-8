#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLines(char **lines, int linesNum);

#define INITIAL_LINES 100
#define LINE_LENGTH 100

int main(){
	char **lines = (char **)malloc(INITIAL_LINES * sizeof(char *));
    int linesCapacity = INITIAL_LINES;
	int linesNum = 0;


	FILE *fp;

	char ch;
	fp = fopen("./assembly.asm", "r");
	if(fp == NULL){
		printf("Error opening file\n");
		exit(1);
	}
	else{
		char *lineContent = (char *)malloc(LINE_LENGTH * sizeof(char));
		lineContent[0] = '\0';
		while((ch = fgetc(fp)) != EOF){
			if (ch == '\n' || ch == '\r'){
				if (lineContent[0] != '\0'){
                    if (linesNum == linesCapacity){
                        linesCapacity *= 2;
					    lines = (char **)realloc(lines, linesCapacity * sizeof(char *));
				    }
				    lines[linesNum] = (char *)malloc(LINE_LENGTH * sizeof(char));
                    strcpy(lines[linesNum], lineContent);
                    linesNum++;
			    }
                lineContent[0] = '\0';
            }
			else{
				if (ch != '\t'){
				strncat(lineContent, &ch, 1);
				}
			}

		}
        fclose(fp);
	}
    printLines(lines, linesNum);

    for (int i = 0; i < linesNum; i++) {
        free(lines[i]);
    }
    free(lines);
    return 0;
}


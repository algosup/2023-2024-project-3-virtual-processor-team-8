#include "parser.h"



void printLines(char **lines, int size){
	int i = 0;

	// Print the array line by line
	while(i < size-1){
		printf("%s", lines[i]);
		i++;
	}
}

char* getLine(char **lines, int line){

	// Return the line of the array of strings based on the line number
	return lines[line-1];

}

void *getFile(const char* path){

	bool comments = false;

	// Allocate memory for the array of lines based on the number of lines in the file
	char **lines = (char **)malloc(getSize(path) * sizeof(char *));


	// Define fp as pointing to a file
	FILE *fp;

	char ch;


	// Open the file with a read-only mode
	fp = fopen(path, "r");

	// If the file does not exist, print an error message and exit the program
	if(fp == NULL){
		printf("Error opening file\n");
		exit(1);
	}

	// If the file exists, read the file line by line
	else{
		int line = 0;

		// Allocate memory for the line content
		char *lineContent = (char *)malloc(100 * sizeof(char));

		// Set the first character of the line content to null to make the line content an empty string
		lineContent[0] = '\0';

		// Read the file character by character until the end of the file
		while((ch = fgetc(fp)) != EOF){

			// Check if the character is a new line character
			if (ch == '\n' || ch == '\r'){
				comments = false;

				// If the line content is not an empty string, add the line content to the array of lines
				if (lineContent[0] != '\0' && lineContent != NULL){

					// Allocate memory for the line
					lines[line] = (char *)malloc(100 * sizeof(char));

					// Add the line content to the array of lines
					strncat(lineContent, &ch, 1);
					sprintf(lines[line], lineContent);

					

					// Set the line content to an empty string and pass to the next line
					lineContent[0] = '\0';
					line++;
				}
				else {
					// Allocate memory for the line
					lines[line] = (char *)malloc(5 * sizeof(char));

					// Add the line content to the array of lines
					strncat(lineContent, &ch, 1);
					sprintf(lines[line], lineContent);
					
					// Set the line content to an empty string and pass to the next line
					lineContent[0] = '\0';
					line++;
				}
			}

			// If the character is not a new line character, add the character to the line content
			else{

				// Add the character to the line content as long as the character is not a tab character
				if (ch != '\t'){
					if (comments == false){
						if (ch == ';'){
							comments = true;
						}
						else{
							strncat(lineContent, &ch, 1);
						}
					}
				}
			}

		}

		// If the end of the file is reached and the line content is not an empty string, add the line content to the array of lines
		if (ch == EOF && lineContent[0] != '\0'){

			// Allocate memory for the line
			lines[line] = (char *)malloc(100 * sizeof(char));

			// Add a new line character to the end of the line content
			char c = '\n';
			strncat(lineContent, &c, 1);

			// Add the line content to the array of lines
			sprintf(lines[line], lineContent);
		}
	}

	return lines;

	// Close the file
	fclose(fp);
}

int getSize(const char* path){
	// Define fp as pointing to a file in read-only mode
	FILE *fp = fopen(path, "r");

	// define ch and lines to 0
	int ch = 0;
	int lines = 1;
	
	// If the file does not exist, return 0
	if (fp == NULL){
		return 0;
	}



	// Read the file character by character until the end of the file
	while ((ch = fgetc(fp)) != EOF){
	

		// If the character is a new line character, increment lines by 1
		if (ch == '\n'){

			// Increment lines by 1
			lines++;
		}
	}

	// Close the file
	fclose(fp);

	// Return the number of lines
	return lines;
}

void *getStructs(char **lines, int size){

	// Allocate memory for the array of structures when declaring it
	func_t *functions = malloc(size * sizeof(func_t));

	int i = 0;


	// Create an array of characters (string) to store the line content
	char *str = (char *)malloc(100 * sizeof(char));

	// Set the first character of the line content to null to make the line content an empty string
	str[0] = '\0';


	// While i is less than the number of lines loop through the array of strings
	while(i < size){


		// Allocate memory for the structure when declaring it
		struct function *func = malloc(sizeof(struct function));

		// Set the structure parameters to default ones
		setStruct(func, "\0", "\0", "\0", "\0", 0);

		// Declare a register count variable
		int reg = 0;

		// Declare a instruction state variable
		int inst = 0;

		// Get one line from the array of lines using the line "i" and store it in the line variable
		const char *line = lines[i];

		// Loop through the line character by character
		for (unsigned int j = 0; j < strlen(line); j++){

			// If the character is a space, comma or new line character, check if the string is an instruction, register or number
			if (line[j] == ' ' || line[j] == ',' || line[j] == '\n'){

				// If the string is not null or empty, check if it is an instruction, register or number
				if (str != NULL && strcmp(str, "") != 0 ){


					// get the type of string using the switchStr function that return 1 for instruction, 2 for register, 3 for number and 4 for syntax error
					int strType = switchStr(str);

					// If the string is an instruction, register or number, set the parameter of the structure based on the instruction state
					if (strType == 1 || strType == 2 || strType == 3 || strType == 4){

						// If the string is an instruction, set the instruction parameter of the structure
						if (inst == 0){

							
							if (strlen(str) > 4){
								printf("Syntax error at line %d: %s is not an instruction\n", i+1, str);
								exit(1);
							}

							// Set the instruction parameter of the structure
							setStruct(func, str, func->name, func->parameter1, func->parameter2, func->line);
							inst++;
						}

						// If the string is a register, set the parameter1 parameter of the structure
						else if (inst == 1){

							// Set the parameter1 parameter of the structure
							setStruct(func, func->instruction, func->name, str, func->parameter2, func->line);
							inst++;
						}

						// If the string is a number, set the parameter2 parameter of the structure
						else if (inst == 2){
							// Set the parameter2 parameter of the structure
							setStruct(func, func->instruction, func->name, func->parameter1, str, func->line);
							inst++;
						}
					}
					else {
						setStruct(func, "", "", "", "", func->line);
					}
				}

				// Set the line parameter of the structure
				str[0] = '\0';
			}

			// If the character is a colon, set the name parameter of the structure
			else if (line[j] == ':'){
				setStruct(func, func->instruction, str, func->parameter1, func->parameter2, func->line);

				// Set the line parameter of the structure
				str[0] = '\0';
			}

			// If the character is not a space, comma, new line character or colon, add the character to the line content
			else {
				strncat(str, &line[j], 1);
			}
		}

		// Set the line of the structure as i + 1 (because i starts at 0)
		setStruct(func, func->instruction, func->name, func->parameter1, func->parameter2, i+1);

		// Add the structure to the array of structures
		functions[i] = *func;

		// Increment i by 1
		i++;

		// Set the line parameter of the structure
		str[0] = '\0';
	}

	// Return the array of structures
	return functions;
}

int switchStr(char *str){

	// Compare the string to all the instructions, registers

	// If string is null, empty or a new line character, return 0
	if (str == NULL){
		return 0;
	}
	else if (strcmp(str, "") == 0){
		return 0;
	}
	else if (strcmp(str, "\n") == 0){
		return 0;
	}


	// If string is an instruction, return 1
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
	else if (strcmp(str, "end") == 0){
		return 1;
	}

	// If string is a register, return 2
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

	// If isnumber returns 1, that means the string is a number, then return 3
	else if (strspn(str, "-0123456789") == strlen(str)){
		return 3;
	}

	// If none of the above, it should be a function call, then return 4
	else {
		return 4;
	}
}

void setStruct(struct function *f, char *instruct, char *Name, char *param1, char *param2, int line){

	// Set the instruction parameter of the structure
	sprintf(f->instruction, instruct);


	// Set the name parameter of the structure
	sprintf(f->name, Name);


	// Set the parameter1 parameter of the structure
	sprintf(f->parameter1, param1);


	// Set the parameter2 parameter of the structure
	sprintf(f->parameter2, param2);


	// Set the line parameter of the structure
	f->line = line;
}

void printStruct(struct function *f){
	// Print the structure parameter by parameter
	printf("==========================================================\n");
	printf("Instruction: %s\n", f->instruction);
	printf("Name: %s\n", f->name);
	printf("Parameter 1: %s\n", f->parameter1);
	printf("Parameter 2: %s\n", f->parameter2);
	printf("Line: %d\n", f->line);
}



int getPosition(func_t *func, char *object, int size){

	// Loop through the array of structures
	for (int i = 1; i < size; i++){

		// Check if the name of the function is equal to the object
		if (strcmp(func[i].name, object) == 0){

			// Return the line where the function is
			return func[i].line;
		}
	}
	return -1;
}




void checkSyntax(func_t *functions, int size){

	// Loop through the array of structures
	for (int i = 0; i < size; i++){
		int str_type_inst = switchStr(functions[i].instruction);
		int str_type_name = switchStr(functions[i].name);
		int str_type_param1 = switchStr(functions[i].parameter1);
		int str_type_param2 = switchStr(functions[i].parameter2);
		
		// If the first parameter is not a register, print an error message
		if (strcmp(functions[i].parameter1, "") != 0 && isRegister(functions[i].parameter1) == 3){
			
			// Print an error message
			printf("Syntax error at line %d: the first parameter should be a register but is the number %s\n", functions[i].line, functions[i].parameter1);

			// Exit the program
			exit(1);
		}

		if (str_type_inst == 0 && str_type_name == 0 && str_type_param1 == 0 && str_type_param2 == 0){
			continue;
		}

		// printf("Instruction: %d - name: %d - param1: %d - param2: %d\n", str_type_inst, str_type_name, str_type_param1, str_type_param2);

		// If the instruction is not an instruction, print an error message
		if (str_type_inst != 1 && str_type_name == 0){
			printf("Syntax error at line %d: %s is not an instruction\n", functions[i].line, functions[i].instruction);
			exit(1);
		}

		// If the name is not a function call, print an error message
		if (str_type_name != 4){
			int pos = getPosition(functions, functions[i].name, size);
			if (pos == -1){
				printf("Syntax error at line %d: %s is not a function call\n", functions[i].line, functions[i].name);
			exit(1);
			}
		}

		// If the parameter1 is not a register or number, print an error message
		if (str_type_param1 != 2 && str_type_param1 != 3 && str_type_param1 != 4 && str_type_param1 != 0){
			printf("Syntax error at line %d: %s is not a register or number at parameter1\n", functions[i].line, functions[i].parameter1);
			exit(1);
		}

		// If the parameter2 is not a register or number, print an error message
		if (str_type_param2 != 2 && str_type_param2 != 3 && str_type_param2 != 0){
			printf("Syntax error at line %d: %s is not a register or number at parameter2\n", functions[i].line, functions[i].parameter2);
			exit(1);
		}

		// If the instruction is a function call, check if the parameters are correct
		if (str_type_param1 == 4){
			int pos = getPosition(functions, functions[i].parameter1, size);
			if (pos == -1){
				printf("Syntax error at line %d: %s is not a function call\n", functions[i].line, functions[i].parameter1);
			exit(1);
			}
		}

		// If the instruction is a function call, check if the parameters are correct
		if (str_type_param2 == 4){
			int pos = getPosition(functions, functions[i].parameter2, size);
			if (pos == -1){
				printf("Syntax error at line %d: %s is not a function call\n", functions[i].line, functions[i].parameter2);
			exit(1);
			}
		}
	}
}



int isRegister(char *parameter){

	// Check if the parameter is a register
	if (strcmp(parameter, "ra") == 0){

		// Return 1 if the parameter is a register
		return 1;
	}
	else if (strcmp(parameter, "rb") == 0){

		// Return 1 if the parameter is a register
		return 1;
	}
	else if (strcmp(parameter, "rc") == 0){

		// Return 1 if the parameter is a register
		return 1;
	}
	else if (strcmp(parameter, "rd") == 0){

		// Return 1 if the parameter is a register
		return 1;
	}
	else if (parameter[0] == '['){

		// Return 2 if the parameter is an address
		return 2;
	}
	else if (isANumber(parameter) == 1){

		// Return 3 if the parameter is a number
		return 3;
	}
	else{

		// Return 0 if the parameter is not a register
		return 0;
	}
}

int isANumber(char *str){
	// If isnumber returns 1, that means the string is a number, then return 3
	if (strspn(str, "-0123456789") == strlen(str) && (str != NULL || strcmp(str, "") != 0)){
		return 1;
	}
	else {
		return 0;
	}
}
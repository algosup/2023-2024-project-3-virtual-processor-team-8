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
	else if (str[0] == 'r' && strspn(str, "abcdefghijklmnopqrstuvwxyz") == 2 && strlen(str) == 2){
		return 2;
	}
	else if (str[0] == '['){
		return 2;
	}

	// If isnumber returns 1, that means the string is a number, then return 3
	else if (strspn(str, "0123456789") == strlen(str)){
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




void checkSyntax(func_t *functions, int size, used_t *registers_used){

	// Loop through the array of structures
	for (int i = 0; i < size; i++){
		int str_type_inst = switchStr(functions[i].instruction);
		int str_type_name = switchStr(functions[i].name);
		int str_type_param1 = switchStr(functions[i].parameter1);
		int str_type_param2 = switchStr(functions[i].parameter2);
		
		// If the first parameter is not a register, print an error message
		if (strcmp(functions[i].parameter1, "") != 0 && isRegister(functions[i].parameter1, registers_used) == 3){
			
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



int isRegister(char *parameter, used_t *registers_used){


	// Check if the parameter is a register
	if (parameter[0] == 'r' && strspn(parameter, "abcdefghijklmnopqrstuvwxyz") == 2 && strlen(parameter) == 2){

		// Update the used registers
		updateUsedregister(registers_used, parameter);

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

void updateUsedregister(used_t *regs, char* reg){

	// If ra is used in the program
	if (strcmp(reg, "ra") == 0){

		// Set the a parameter of the structure to 1
		regs->a = 1;
	}

	// If rb is used in the program
	else if (strcmp(reg, "rb") == 0){

		// Set the b parameter of the structure to 1
		regs->b = 1;
	}

	// If rc is used in the program
	else if (strcmp(reg, "rc") == 0){

		// Set the c parameter of the structure to 1
		regs->c = 1;
	}

	// If rd is used in the program
	else if (strcmp(reg, "rd") == 0){

		// Set the d parameter of the structure to 1
		regs->d = 1;
	}

	// If re is used in the program
	else if (strcmp(reg, "re") == 0){

		// Set the e parameter of the structure to 1
		regs->e = 1;
	}

	// If rf is used in the program
	else if (strcmp(reg, "rf") == 0){

		// Set the f parameter of the structure to 1
		regs->f = 1;
	}

	// If rg is used in the program
	else if (strcmp(reg, "rg") == 0){

		// Set the g parameter of the structure to 1
		regs->g = 1;
	}

	// If rh is used in the program
	else if (strcmp(reg, "rh") == 0){

		// Set the h parameter of the structure to 1
		regs->h = 1;
	}

	// If ri is used in the program
	else if (strcmp(reg, "ri") == 0){

		// Set the i parameter of the structure to 1
		regs->i = 1;
	}

	// If rj is used in the program
	else if (strcmp(reg, "rj") == 0){

		// Set the j parameter of the structure to 1
		regs->j = 1;
	}

	// If rk is used in the program
	else if (strcmp(reg, "rk") == 0){

		// Set the k parameter of the structure to 1
		regs->k = 1;
	}

	// If rl is used in the program
	else if (strcmp(reg, "rl") == 0){

		// Set the l parameter of the structure to 1
		regs->l = 1;
	}

	// If rm is used in the program
	else if (strcmp(reg, "rm") == 0){

		// Set the m parameter of the structure to 1
		regs->m = 1;
	}

	// If rn is used in the program
	else if (strcmp(reg, "rn") == 0){
		// Set the n parameter of the structure to 1
		regs->n = 1;
	}

	// If ro is used in the program
	else if (strcmp(reg, "ro") == 0){
		// Set the o parameter of the structure to 1
		regs->o = 1;
	}

	// If rp is used in the program
	else if (strcmp(reg, "rp") == 0){
		// Set the p parameter of the structure to 1
		regs->p = 1;
	}

	// If rq is used in the program
	else if (strcmp(reg, "rq") == 0){
		// Set the q parameter of the structure to 1
		regs->q = 1;
	}

	// If rr is used in the program
	else if (strcmp(reg, "rr") == 0){
		// Set the r parameter of the structure to 1
		regs->r = 1;
	}

	// If rs is used in the program
	else if (strcmp(reg, "rs") == 0){
		// Set the s parameter of the structure to 1
		regs->s = 1;
	}

	// If rt is used in the program
	else if (strcmp(reg, "rt") == 0){
		// Set the t parameter of the structure to 1
		regs->t = 1;
	}

	// If ru is used in the program
	else if (strcmp(reg, "ru") == 0){
		// Set the u parameter of the structure to 1
		regs->u = 1;
	}

	// If rv is used in the program
	else if (strcmp(reg, "rv") == 0){
		// Set the v parameter of the structure to 1
		regs->v = 1;
	}

	// If rw is used in the program
	else if (strcmp(reg, "rw") == 0){
		// Set the w parameter of the structure to 1
		regs->w = 1;
	}

	// If rx is used in the program
	else if (strcmp(reg, "rx") == 0){
		// Set the x parameter of the structure to 1
		regs->x = 1;
	}

	// If ry is used in the program
	else if (strcmp(reg, "ry") == 0){
		// Set the y parameter of the structure to 1
		regs->y = 1;
	}

	// If rz is used in the program
	else if (strcmp(reg, "rz") == 0){
		// Set the z parameter of the structure to 1
		regs->z = 1;
	}
}
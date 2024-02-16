# Test cases

This document lists all test cases for the project, and their state. 

---

Status :
- To test
- To fix
- Working

Impact :
- Low (not necessary)
- Medium (good to have)
- High (needs to be done)

<br>

## Parser

| ID | Name | Description | Expected result | Actual result | Status | Impact |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1.1 | Read the assembly code | The parser read the file where the assembly code is written | The parser outputs the assembly code that as been read | Same as the expected result | Working | High |
| 1.2 | Separate lines | The parser can differentiate the lines | The parser gives a line number to every lines | Same as expected result | Working | High |
| 1.3 | Separate the words | The parser can differentiate the words in the lines | The parser outputs where a word is detected and separate it from the others | Same as expected result | Working | High |
| 1.4 | Differentiate the instructions | The parser can recognize the instructions and their parameters | The parser outputs which instruction it is and its parameters | Same as expected result | Working | High |
| 1.5 | Recognize instructions or functions | The parser can differentiate the instructions and the functions | The parser outputs "instruction: 'name' " if it is an instruction or "function: 'name' " if it is a function | Same as expected result | Working | High |
| 1.6 | Storing the lines | The parser can store every line independently | The parser store each line in a structure array, then outputs them one by one | Same as expected result | Working | High |
| 1.7 | Detect syntax error | The parser can detect if there is a syntax error | The parser outputs an error if it is found in the assembly code | --- | To test | Medium |
| 1.8 | Detect commentaries | The parser can detect if a commentary is written | The parser works as if no commentaries were written | Same as expected result | Working | Low |

<br>

## Interpreter

| ID | Name | Description | Instruction necessary | Expected result | Actual result | Status | Impact |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 2.1 | Shows registers | The interpreter can show the value in the registers | --- | The interpreter outputs all registers with their value | Same as expected result | Working | High |
| 2.2 | Copy a value | The interpreter can copy a value to a register | mov 'register', 'value' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.3 | Copy a register's value | The interpreter can copy the value of a register (register2) to an other register (register1) | mov 'register1', 'register2' | The interpreter shows two registers with the same value after reading the instruction | Same as expected result | Working | High |
| 2.4 | Copy the value of a register to the memory | The interpreter can copy the value of a register (register2) to the memory at the address given by a register (register1) | prt 'register1', 'register2' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.5 | Copy the value of the memory | The interpreter can copy the value of the memory at the address given by a register (register2) to an other register (register1) | prf 'register1', 'register2' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.6 | Comparing register to a value | The interpreter can compare the value of a register to a value | cmp 'register', 'value' | Return a value depending on the result of the comparison, if it is equal, higher or less | Same as expected result | Working | High |
| 2.7 | Comparing registers | The interpreter can compare the value of a register (register1) to a value of an other register (register2) | cmp 'register1', 'register2' | Return a value depending on the result of the comparison, if it is equal, higher or less | Same as expected result | Working | High |
| 2.8 | Unconditional jump | Jump to the called function | jmp 'function | The interpreter execute correctly the function it is supposed to jump to | Same as expected result | Working | High |
| 2.9 | "If equal" jump | After a compare, jump to the called function if the values of the compare were equal | je 'function' | The interpreter execute correctly the function it is supposed to jump to after doing the correct comparison | Same as expected result | Working | High |
| 2.10 | "If not equal" jump | After a compare, jump to the called function if the values of the compare were not equal | jne 'function' | The interpreter execute correctly the function it is supposed to jump to after doing the correct comparison  | Same as expected result | Working | High |
| 2.11 | "If greater" jump | After a compare, jump to the called function if the first value of the compare is greater than the second value of the compare | jg 'function' | The interpreter execute correctly the function it is supposed to jump to after doing the correct comparison  | Same as expected result | Working | High |
| 2.12 | "If less" jump | After a compare, jump to the called function if the first value of the compare is less than the second value of the compare | jl 'function' | The interpreter execute correctly the function it is supposed to jump to after doing the correct comparison  | Same as expected result | Working | High |
| 2.13 | "If greater or equal" jump | After a compare, jump to the called function if the first value of the compare is greater or equal than the second value of the compare | jge 'function' | The interpreter execute correctly the function it is supposed to jump to after doing the correct comparison  | Same as expected result | Working | High |
| 2.14 | "If less or equal" jump | After a compare, jump to the called function if the first value of the compare is less or equal than the second value of the compare | jle 'function' | The interpreter execute correctly the function it is supposed to jump to after doing the correct comparison  | Same as expected result | Working | High |
| 2.15 | Call a function | The interpreter will do the function that is called | call 'function' | The interpreter execute correctly the function it is supposed to do | Same as expected result | Working | High |
| 2.16 | Return | The interpreter will go back to the function where the function was called | ret | The interpreter returns to the correct function where the function it is has been called | Same as expected result | Working | High |
| 2.17 | Add a value | The interpreter can add a given value to a register | add 'register', 'value' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.18 | Add a register | The interpreter can add the value of a register (register2) to the other register (register1) | add 'register1', 'register2' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.19 | Subtract a value | The interpreter can subtract a given value to a register | sub 'register', 'value' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.20 | Subtract a register | The interpreter can subtract the value of a register (register2) to the other register (register1) | sub 'register1', 'register2' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.21 | Multiply a value | The interpreter can multiply a given value to a register | mul 'register', 'value' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.22 | Multiply a register | The interpreter can multiply the value of a register (register2) to the other register (register1) | mul 'register1', 'register2' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.23 | Divide a value | The interpreter can divide a given value to a register | div 'register', 'value' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.24 | Divide a register | The interpreter can divide the value of a register (register2) to the other register (register1) | div 'register1', 'register2' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.25 | OR operation with a value | The interpreter can do the OR operation with a given value to a register | or 'register', 'value' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.26 | OR operation with a register | The interpreter can do the OR operation with a register (register2) to the other register (register1) | or 'register1', 'register2' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.27 | XOR operation with a value | The interpreter can do the XOR operation with a given value to a register | xor 'register', 'value' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.28 | XOR operation with a register | The interpreter can do the XOR operation with a register (register2) to the other register (register1) | xor 'register1', 'register2' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.29 | AND operation with a value | The interpreter can do the AND operation with a given value to a register | and 'register', 'value' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.30 | AND operation with a register | The interpreter can do the AND operation with a register (register2) to the other register (register1) | and 'register1', 'register2' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.31 | NOT operation | The interpreter can do the NOT operation to a register (register1) | not 'register' | The interpreter shows registers with correct changed values after reading the instruction | Same as expected result | Working | High |
| 2.32 | End of program | The interpreter ends the program when arriving at the instruction end written on the last line | end | The interpreter shows at the end the instruction end with the different value of the registers and stop | Same as expected result | Working | Medium |

<br>

## Parser and interpreter

| ID | Name | Description | Expected result | Actual result | Status | Impact |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 3.1 | Execute | The complete program is capable of executing and compiling an .asm file and output the final result of it by showing the value of each register | Successfully execute an .asm file and outputs the correct value of each register | Same as expected result | Working | High |
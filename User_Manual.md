# User manual

## Installation

1. GitHub
You will find all the files needed to run the virtual processor in our [GitHub repository](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8)

2. Installation pack

## cmd file

![WIP]

## Path to the file .asm

![WIP]

## Syntax description

Our virtual processor uses a custom assembly language, largely inspired by the original one. 

Here is a list of all the instructions and registers available. It is important to note that the syntax is case-sensitive. 

### Instructions

#### Arithmetic

- `ADD` : Add the value of the second operand to the first one
- `SUB` : Subtract the value of the second operand from the first one
- `MUL` : Multiply the value of the first operand by the second one
- `DIV` : Divide the value of the first operand by the second one

#### Logic

- `AND` : Perform a bitwise AND operation on the two operands
- `OR` : Perform a bitwise OR operation on the two operands
- `XOR` : Perform a bitwise XOR operation on the two operands
- `NOT` : Perform a bitwise NOT operation on the first operand
- `CMP` : Compare the two operands and set the zero flag if they are equal

#### Data transfer

- `MOV` : Move the value of the second operand into the first one
- `CALL` : Execute the function call and return the line to jump to

#### Control flow

- `JMP` : Jump to the specified line
- `JE` : Jump to the specified line if the two operands are equal
- `JNE` : Jump to the specified line if the two operands are not equal
- `JG` : Jump to the specified line if the first operand is greater than the second one
- `JGE` : Jump to the specified line if the first operand is greater than or equal to the second one
- `JL` : Jump to the specified line if the first operand is less than the second one
- `JLE` : Jump to the specified line if the first operand is less than or equal to the second one

#### Pointers

- `PRT` : Set the value of the first operand to the address of the second one
- `PRF` : Set the value of the first operand to the value at the address of the second one

### Registers

There are 4 general-purpose registers available, named `ra`, `rb`, `rc` and `rd`.

## Syntax snippet

```assembly
mov ra, [rc]
prf ra, rb
mov rb, 0
cmp rb, 0
jmp rel
ess:
	mov rd, 178
	add rd, 2
	div rd, 2
	ret
nd:
	cmp ra, 0
	je tes
rel:
	add rb, 1
	mul rb, 8
	cmp rb, 2
	je nd
	call ess
tes:
	add rc, 1 ; test
	mul rc, 178
	; here is another test
	prt rd, ra
end
```
    
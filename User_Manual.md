# User manual

## Installation

#### 1. GitHub
You will find all the files needed to run the virtual processor in our [release history](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8/releases).

#### 2. Installation pack
Once you have the release pack, download the latest version of the virtual processor (.zip or .tar.gz) and extract it to your local driver choosing the location of the file.

### Windows users

To run the virtual processor, you will need to install the latest version of [MinGW](https://sourceforge.net/projects/mingw/), and [configure the path to the bin folder in the environment variables](https://techdecodetutorials.com/how-to-install-mingw-c-c-compiler-in-windows-11/).

### MacOs users

To run the virtual processor, you will need to install the latest version of GCC compilor. You can do so by running the following command in your terminal:
```shell
brew install gcc
```
## Launch the virtual processor

### Windows users

To launch the virtual processor, open the folder where you extracted the files and double-click on the `Virtual_Processor.cmd` file.
That will launch a terminal window and the virtual processor will be ready to use.
The terminal window will ask you if you want to enter the path to the file you want to execute. You will need to answer `y` to enter the path of your file at least once and the next time you can refuse to enter the path by answering `n` to the question which will run the previously added path.
In case of a syntax error, the terminal window will display the error message and the line where the error was found (e.g. `Syntax error at line 8: lrf is not an instruction`).
If there is no error, the terminal window will display the result of the program.


### MacOs users

To launch the virtual processor, open the folder where you extracted the files and double-click on the `Virtual_Processor.sh` file.
That will launch a terminal window and the virtual processor will be ready to use.
The terminal window will ask you to enter the path to the file you want to execute.
In case of a syntax error, the terminal window will display the error message and the line where the error was found (e.g. `Syntax error at line 8: lrf is not an instruction`).
If there is no error, the terminal window will display the result of the program.


## Output

The virtual processor will display the result of the program in the terminal window. If the program ends without any error, the terminal window will display the value of the registers used in the program at the end of the terminal.
This assembly program,
```asm
mov ra, 50
mov rb, 2
mul ra, rb
mov rd, ra
call multiply
jmp finish
multiply:
	mov rc, 3
	mul rd, rc
	ret
finish:
end
```
will display the following result:
```shell
============================================================
Setting ra to 50
ra is now equal to 50
============================================================
Setting rb to 2
rb is now equal to 2
============================================================
Multiplying ra by rb
ra is now equal to 100
============================================================
Setting rd to ra
rd is now equal to 100
============================================================
Calling multiply
============================================================
Setting rc to 3
rc is now equal to 3
============================================================
Multiplying rd by rc
rd is now equal to 300
============================================================
Returning to the line after the call
============================================================
Jumping to finish
============================================================
Ending the program
============================================================
ra: 100
rb: 2
rc: 3
rd: 300
```



## Syntax description

Our virtual processor uses a custom assembly language, largely inspired by the original one. 

Here is a list of all the instructions and registers available. It is important to note that the syntax is case-sensitive (all the instructions are in lowercase). 

### Registers and memory

There are 26 general-purpose registers available, named `ra`, `rb`, `rc` ... `ry`, `rz`.

The memory is also accessible through special instructions, `prt` and `prf`, which can be used in the range of a variable named `MAX_VMEMORY` (default value is 256) located in the `Src/interpreter.h` file at line 4.
To change the value of the memory, you will need to change the value of the variable.
```c
#define MAX_VMEMORY 256
```


### Instructions

#### Arithmetic

- `ADD` : Add the value of the second operand to the first one
	```assembly
		; By default, the value of ra is 0
		add ra, 2 ; ra is now equal to 2
		end ; End the program
	```
- `SUB` : Subtract the value of the second operand from the first one
	```assembly
		; By default, the value of ra is 0
		add ra, 27 ; ra is now equal to 27
		sub ra, 2  ; ra is now equal to 25
		end ; End the program
	```
- `MUL` : Multiply the value of the first operand by the second one
	```assembly
		; By default, the value of ra is 0
		add ra, 3 ; ra is now equal to 3
		mul ra, 2 ; ra is now equal to 6
		end ; End the program
	```
- `DIV` : Divide the value of the first operand by the second one
	```assembly
		; By default, the value of ra is 0
		add ra, 10 ; ra is now equal to 10
		div ra, 2 ; ra is now equal to 5
		end ; End the program
	```

#### Logic

- `AND` : Perform a bitwise AND operation on the two operands
	```assembly
		; By default, the value of ra is 0
		add ra, 18 ; ra is now equal to 18
		and ra, 14 ; ra is now equal to 2
		end ; End the program
	```
- `OR` : Perform a bitwise OR operation on the two operands
	```assembly
		; By default, the value of ra is 0
		add ra, 24 ; ra is now equal to 24
		or ra, 96 ; ra is now equal to 120
		end ; End the program
	```
- `XOR` : Perform a bitwise XOR operation on the two operands
	```assembly
		; By default, the value of ra is 0
		add ra, 24 ; ra is now equal to 24
		xor ra, 94 ; ra is now equal to 70
		end ; End the program
	```
- `NOT` : Perform a bitwise NOT operation on the first operand
	```assembly
		; By default, the value of ra is 0
		add ra, 90 ; ra is now equal to 90
		not ra ; ra is now equal to 165
		end ; End the program
	```
- `CMP` : Compare the two operands and set the zero flag if they are equal
	```assembly
		; By default, the value of ra is 0
		add ra, 24 ; ra is now equal to 24
		cmp ra, 24 ; The equal state is now true & ra is still equal to 24
		end ; End the program
	```

#### Data transfer

- `MOV` : Move the value of the second operand into the first one
	```assembly
		; By default, the value of ra is 0
		mov ra, 42 ; ra is now equal to 42
		mov rb, ra ; rb is now equal to 42
		end ; End the program
	```
- `CALL` : Execute the function call and return the line to jump to
	```assembly
		; By default, the value of ra is 0
		mov ra, 10 ; ra is now equal to 10

		call multiply ; Call the function multiply and return the line to jump to

		jmp finish ; Jump to the line labeled finish

		multiply: ; Label the current line as multiply

			; By default, the value of rb is 0
			mov rb, 2 ; Set the value of rb to 2

			mul ra, rb ; Multiply the value of ra by rb

			ret ; Return to the line to jump to

		finish: ; Label the current line as finish

		end ; End the program
	```

#### Control flow

- `JMP` : Jump to the specified line
	```assembly
		; By default, the value of ra is 0
		mov ra, 10 ; ra is now equal to 10

		jmp finish ; Jump to the line labeled finish

		; By default, the value of rb is 0
		mov rb, 2 ; Set the value of rb to 2

		mul ra, rb ; Multiply the value of ra by rb

		finish: ; Label the current line as finish

		; ra is still equal to 10 & rb is still equal to 0 as the jump was executed before their modification

		end ; End the program
	```
- `JE` : Jump to the specified line if the two operands are equal
	```assembly
		; By default, the value of ra is 0
		add ra, 24 ; ra is now equal to 24
		
		cmp ra, 24 ; The equal state is now true & ra is still equal to 24
		
		je finish ; Jump to the line labeled finish if the two values are equal

		finish: ; Label the current line as finish

		end ; End the program
	```
- `JNE` : Jump to the specified line if the two operands are not equal
	```assembly
		; By default, the value of ra is 0
		add ra, 24 ; ra is now equal to 24
		
		cmp ra, 78 ; The equal state is now false & ra is still equal to 24

		jne finish ; Jump to the line labeled finish if the two values are not equal

		finish: ; Label the current line as finish

		end ; End the program
	```

- `JG` : Jump to the specified line if the first operand is greater than the second one
	```assembly
		; By default, the value of ra is 0
		add ra, 24 ; ra is now equal to 24
		
		cmp ra, 4 ; The greater state is now true & ra is still equal to 24

		jg finish ; Jump to the line labeled finish if the first value is greater than the second one

		finish: ; Label the current line as finish

		end ; End the program
	
	```
- `JGE` : Jump to the specified line if the first operand is greater than or equal to the second one
	```assembly
		; By default, the value of ra is 0
		add ra, 24 ; ra is now equal to 24
		
		cmp ra, 24 ; The greater state is now true & the equal state is also set to true & ra is still equal to 24

		jge finish ; Jump to the line labeled finish if the first value is greater than the second one or if they are equal

		finish: ; Label the current line as finish

		end ; End the program
	
	```
- `JL` : Jump to the specified line if the first operand is lower than the second one
	```assembly
		; By default, the value of ra is 0
		add ra, 24 ; ra is now equal to 24
		
		cmp ra, 74 ; The lower state is now false & ra is still equal to 24

		jl finish ; Jump to the line labeled finish if the first value is lower than the second one

		finish: ; Label the current line as finish

		end ; End the program
	
	```
- `JLE` : Jump to the specified line if the first operand is less than or equal to the second one
	```assembly
		; By default, the value of ra is 0
		add ra, 24 ; ra is now equal to 24
		
		cmp ra, 24 ; The lower state is now true & the equal state is also set to true & ra is still equal to 24

		jle finish ; Jump to the line labeled finish if the first value is lower than the second one or if they are equal

		finish: ; Label the current line as finish

		end ; End the program
	
	```

#### Pointers

- `PRT` : Set the value of the first operand to the address of the second one
	```assembly
		; By default, the value of ra is 0
		add ra, 24 ; ra is now equal to 24
		
		prt rc, ra ; Set the value at the address of rc to the value of ra

		end ; End the program
	```
- `PRF` : Set the value of the first operand to the value at the address of the second one
	```assembly
		; By default, the value of ra is 0
		add ra, 24 ; ra is now equal to 24
		
		prf rc, ra ; Set the value of rc to the value at the address of ra

		end ; End the program
	```


## Syntax snippet

```assembly
mov ra, 64				; Set the value of ra to 64

mov rb, 2				; Set the value of rb to 2

prt rc, ra				; Set the value of rc to the address of ra

prf re, rc				; Set the value of re to the value at the address of reduce

mul ra, rb				; Multiply the value of ra by rb


main:					; Label the current line as main

    mov rd, ra				; Set the value of rd to the value of ra


    reduce:				; Label the current line as reduce

        sub rd, 1			; Subtract 1 from the value of rd

        cmp rd, 100			; Compare the value of rd to 100

        jne reduce			; Jump to the line labeled reduce if the two values are not equal

    call multiply			; Call the function multiply and return the line to jump to

    jmp finish				; Jump to the line labeled finish


multiply:				; Label the current line as multiply

    mov rc, 3				; Set the value of rc to 3

    mul rd, rc				; Multiply the value of rd by the value of reduce

    ret					; Return to the line to jump to


finish:					; Label the current line as finish

    end					; End the program
```
    
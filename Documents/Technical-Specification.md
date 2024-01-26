<div align="center">

# Technical Specification

---
**Title:** Virtual Processor Project - Team 8

**Author:** Pierre GORIN

**Team:** Team 8

**Reviewer(s):** Laurent BOUQUIN, Evan UHRING

**Created on:** January 22<sup>nd</sup>, 2024

**Last updated:** January 26<sup>nd</sup>, 2024

---

### Approvals

| Reviewer           | Role              | Approved | Date |
| ------------------ | ----------------- | -------- | ---- |
| Laurent BOUQUIN    | Quality Assurance |          |      |
| Evan UHRING        | Quality Assurance |          |      |
| Laura-Lee HOLLANDE | Project Manager   |          |      |
| Ian LAURENT        | Program Manager   |          |      |
| Pierre GORIN       | Technical Lead    |          |      |
| Manech LAGUENS     | Software Engineer |          |      |
| Victor LEROY       | Software Engineer |          |      |

</div>

<br><details>
<summary><h3 id="toc"> Table of Contents <i>(Click to expand)</i></h3></summary>

- [Technical Specification](#technical-specification)
    - [Approvals](#approvals)
- [1 - Overview](#1---overview)
  - [1.1 - Purpose](#11---purpose)
    - [1.1.1 - Goals](#111---goals)
    - [1.1.2 - Objectives](#112---objectives)
    - [1.1.3 - Success Criteria](#113---success-criteria)
  - [1.2 - Stakeholders](#12---stakeholders)
    - [1.2.1 - Project Team](#121---project-team)
    - [1.2.2 - Client](#122---client)
  - [1.3 - Usage](#13---usage)
    - [1.3.1 - Requirements](#131---requirements)
    - [1.3.2 - Installation](#132---installation)
      - [1.3.2.1 - Installation with Bash](#1321---installation-with-bash)
      - [1.3.2.2 - Installation with Github Desktop](#1322---installation-with-github-desktop)
    - [1.3.3 - Running](#133---running)
  - [1.4 - Scope](#14---scope)
    - [1.4.1 - In Scope](#141---in-scope)
    - [1.4.2 - Out of Scope](#142---out-of-scope)
- [2 - Overall Description](#2---overall-description)
  - [2.1 System Environment](#21-system-environment)
    - [2.1.1 - Hardware](#211---hardware)
    - [2.1.2 - Software](#212---software)
  - [2.2 - Project Folder Structure](#22---project-folder-structure)
  - [2.3 - Conventions](#23---conventions)
    - [2.3.1 - Naming Conventions](#231---naming-conventions)
      - [2.3.1.1 Folders](#2311-folders)
      - [2.3.1.2 Files](#2312-files)
      - [2.3.1.3 Variables](#2313-variables)
      - [2.3.1.4 Constants](#2314-constants)
      - [2.3.1.5 Functions](#2315-functions)
    - [2.3.2 - Formatting Conventions](#232---formatting-conventions)
      - [2.3.2.1 - Indentation](#2321---indentation)
      - [2.3.2.2 - Line Length](#2322---line-length)
      - [2.3.2.3 - Line Breaks](#2323---line-breaks)
      - [2.3.2.4 - Comments](#2324---comments)
  - [2.4 - Assembly Syntax](#24---assembly-syntax)
    - [2.4.1 - Registers](#241---registers)
      - [2.4.1.1 - Storing an immediate value into a register](#2411---storing-an-immediate-value-into-a-register)
      - [2.4.1.2 Copying the value of a register into another register](#2412-copying-the-value-of-a-register-into-another-register)
      - [2.4.1.3 Reading the value from the memory to a register](#2413-reading-the-value-from-the-memory-to-a-register)
      - [2.4.1.4 Writing the value from a register to the memory](#2414-writing-the-value-from-a-register-to-the-memory)
    - [2.4.2 - Jumping to a label](#242---jumping-to-a-label)
      - [2.4.2.1 - Jumping unconditionally](#2421---jumping-unconditionally)
      - [2.4.2.2 - Jumping conditionally (where "cc" is a condition code)](#2422---jumping-conditionally-where-cc-is-a-condition-code)
    - [2.4.3 - Comparing registers](#243---comparing-registers)
    - [2.4.4 - Calling a subroutine](#244---calling-a-subroutine)
    - [2.4.5 - Returning from a subroutine](#245---returning-from-a-subroutine)
    - [2.4.6 - Arithmetic operations](#246---arithmetic-operations)
      - [2.4.6.1 - Addition](#2461---addition)
      - [2.4.6.2 - Subtraction](#2462---subtraction)
      - [2.4.6.3 - Multiplication](#2463---multiplication)
      - [2.4.6.4 - Division](#2464---division)
    - [2.4.7 - Logical operations](#247---logical-operations)
      - [2.4.7.1 - Logical AND](#2471---logical-and)
      - [2.4.7.2 - Logical OR](#2472---logical-or)
      - [2.4.7.3 - Logical XOR](#2473---logical-xor)
      - [2.4.7.3 - Logical NOT](#2473---logical-not)
      - [2.4.8 - Comments](#248---comments)

</details>

---

# 1 - Overview

## 1.1 - Purpose

[*(Back to top)*](#toc)

### 1.1.1 - Goals

This project aims to develop a virtual processor[^1] and an interpreter[^2] for a custom assembly language[^3]. Using only standard C[^4] libraries for wide compatibility, the primary goal is to design a minimal assembly language and build a C program interpreter capable of executing and error-checking assembly code. This solution is intended to serve educational purposes and software developers interested in low-level programming[^5] and processor emulation. The project combines technical innovation with practical application, focusing on creating a user-friendly and educational tool in the field of computer architecture.

### 1.1.2 - Objectives

The project objectives are as follows:

- Design a minimal assembly language with a sufficient set of instructions.
- Develop an interpreter capable of executing assembly code.
- Develop an interpreter capable of error-checking assembly code.
- Make the interpreter user-friendly and easy to use.
- Make the interpreter compatible with a wide range of operating systems.

### 1.1.3 - Success Criteria

The project will be considered successful if the following criteria are met:

- The interpreter is capable of executing assembly code.
- The interpreter is compatible with the most common operating systems.
- 50% of the set of instructions are implemented.

## 1.2 - Stakeholders

[*(Back to top)*](#toc)

This project is for educational purposes and is not intended for commercial use. The project team will be responsible for the development of the project and the client will be responsible for providing feedback and guidance throughout the development process.

### 1.2.1 - Project Team

| Name               | Role              | Github                                                    |
| ------------------ | ----------------- | --------------------------------------------------------- |
| Laura-Lee HOLLANDE | Project Manager   | [Laura-Lee's Github](https://github.com/lauraleehollande) |
| Ian LAURENT        | Program Manager   | [Ian's Github](https://github.com/Ianlaur)                |
| Pierre GORIN       | Technical Lead    | [Pierre's Github](Pierre2103)                             |
| Victor LEROY       | Software Engineer | [Victor's Github](https://github.com/Victor-Leroy)        |
| Manech LAGUENS     | Software Engineer | [Manech's Github](https://github.com/Manech-Laguens)      |
| Laurent BOUQUIN    | Quality Assurance | [Laurent's Github](https://github.com/Ianlaur)            |
| Evan UHRING        | Quality Assurance | [Evan's Github](https://github.com/Evan-UHRING)           |

### 1.2.2 - Client

| Name             | Role                 | Contact                                                         |
| ---------------- | -------------------- | --------------------------------------------------------------- |
| ALGOSUP          | Client               | [Website](https://www.algosup.com/)                             |
| Franck JEANNIN   | ALGOSUP's Co-Founder | [LinkedIn](https://www.linkedin.com/in/franck-jeannin/)         |
| Eric LARCHEVEQUE | ALGOSUP's Co-Founder | [LinkedIn](https://www.linkedin.com/in/ericlarch/)              |
| Natacha BOEZ     | ALGOSUP's Co-Founder | [LinkedIn](https://www.linkedin.com/in/natacha-boez-913a33167/) |

## 1.3 - Usage

[*(Back to top)*](#toc)

The interpreter is designed to be user-friendly and easy to use. The interpreter will be compatible with the most common operating systems and will be capable of executing assembly code and error-checking assembly code. The interpreter will be capable of displaying the output of the assembly code.
Following are the instructions to install and run the interpreter.

### 1.3.1 - Requirements

To run your custom assembly code, you will need to install the following dependencies:

- [VS Code](https://code.visualstudio.com/download) - Visual Studio Code is a free source-code editor made by Microsoft for Windows, Linux and macOS.
- [C/C++ for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) - C/C++ for Visual Studio Code is an extension for VS Code that provides IntelliSense, debugging, and code browsing support for C and C++ code.
- [GCC](https://gcc.gnu.org/install/) - GCC, the GNU Compiler Collection, is a free collection of compilers for C, C++, Objective-C, Fortran, Ada, Go, and D programming languages.

### 1.3.2 - Installation

To install the interpreter, you will need to follow these steps:

1. Clone the repository on your local machine, or download the repository as a ZIP file and extract it.

#### 1.3.2.1 - Installation with Bash

Open a terminal and run the following commands:

```bash
git clone https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8.git
cd 2023-2024-project-3-virtual-processor-team-8
```

#### 1.3.2.2 - Installation with Github Desktop

Open Github Desktop and click on `File > Clone Repository`. Select the URL tab and enter the following URL:

```bash
https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8.git
```

Then click on `Clone` and click on `Repository > Open in Visual Studio Code`.

### 1.3.3 - Running

To run the interpreter, you will need to follow these steps:

1. Open the repository in VS Code.
2. Navigate to the `src` folder.
3. Modify the `code.asm` file to include your custom assembly code.
4. Open the terminal in VS Code.
<!-- TODO: Add the command(s) to run the assembly -->

## 1.4 - Scope

[*(Back to top)*](#toc)

### 1.4.1 - In Scope

The project will include the following features:

- Basic assembly language with a minimal set of instructions.
- Interpreter capable of executing assembly code.
- Interpreter capable of error-checking assembly code.
- User-friendly interface.
- Compatibility with the most common operating systems.

### 1.4.2 - Out of Scope

The project will not include the following features:

- Advanced assembly language with a complex set of instructions.
- Graphical user interface.
- Debugging tools.
- Compatibility with specific hardware configurations.
- Compatibility with other programming languages.
- Real-time performance analysis.
- Advanced memory management.

# 2 - Overall Description

## 2.1 System Environment

[*(Back to top)*](#toc)

### 2.1.1 - Hardware

The interpreter will be compatible with the most common hardware configurations, and will be tested on the following hardware:

| Specification | Lenovo ThinkBook 14 G2 | Apple MacBook Air M1 2020 |
| ------------- | ---------------------- | ------------------------- |
| Processor     | Intel Core i7-1165G7   | Apple Silicon M1          |
| RAM           | 16 GB                  | 8 GB                      |

### 2.1.2 - Software

The interpreter will be compatible with the most common operating systems, and will be tested on the following operating systems:

| Operating System | Windows 11 Pro | macOS Sonoma |
| ---------------- | ---------- | ------------ |
| Version          | 22H2       | 14.3         |

## 2.2 - Project Folder Structure

[*(Back to top)*](#toc)

The project will be organized in the following folder structure:

```bash
~ 2023-2024-project-3-virtual-processor-team-8  # Root folder
├── Bin                                         # Binary folder
├── Tests                                       # Tests folder
│   ├── tests_interpreter.c                     # Interpreter tests C file
│   ├── tests_interpreter.h                     # Interpreter tests C header file
│   ├── tests_scraper.c                         # Scraper tests C file
│   ├── tests_scraper.h                         # Scraper tests C header file
│   ├── tests_parser.c                          # Parser tests C file
│   └── tests_parser.h                          # Parser tests C header file
├── Docs                                        # Documentation folder
│   ├── Management                              # Management folder
│   │   ├── Team-Management                     # Team management folder
│   │   │   ├── Gantt-Charter.pdf               # Gantt chart file
│   │   │   └── Racii.md                        # RACII file
│   │   ├── Weekly-Reports                      # Weekly reports folder
│   │   │   ├── Img                             # Images folder
│   │   │   ├── Weekly-Report-1.md              # Weekly report file
│   │   │   ├── Weekly-Report-2.md              # Weekly report file
│   │   │   └── [etc...]                        # Others Weekly report file
│   │   ├── Project-Charter.md                  # Project charter file
│   │   └── Risk-Management-Plan.md             # Risk management plan file
│   └── Specs                                   # Specifications folder
│       ├── Img                                 # Images folder
│       │   ├── Functional-Specification        # Functional specification images folder
│       │   ├── Technical-Specification         # Technical specification images folder
│       │   └── Test-Plan                       # Test plan images folder
│       ├── Functional-Specification.md         # Functional specification file
│       ├── Technical-Specification.md          # Technical specification file
│       └── Test-Plan.md                        # Test plan file
├── Src                                         # Source code folder
│   ├── code.asm                                # Assembly code file
│   ├── interpreter.c                           # Interpreter C file
│   ├── interpreter.h                           # Interpreter C header file
│   ├── main.c                                  # Main C file
│   ├── main.h                                  # Main C header file
│   ├── scraper.c                               # Parser C file
│   ├── scraper.h                               # Parser C header file
│   ├── parser.c                                # Parser C file
│   ├── parser.h                                # Parser C header file
│   └── temp                                    # Temporary folder
├── .gitignore                                  # Git ignore file
├── LICENSE                                     # License file
└── README.md                                   # Readme file
```

## 2.3 - Conventions

[*(Back to top)*](#toc)

### 2.3.1 - Naming Conventions

The project will follow the following naming conventions:

#### 2.3.1.1 Folders

- Folder names will be written in `Train-Case`.

#### 2.3.1.2 Files

- File related to documentation or managemnt will be written in `Train-Case`.
- File related to source code will be written in `snake_case`.

#### 2.3.1.3 Variables

- Variable names will be written in `snake_case`.

#### 2.3.1.4 Constants

- Constant names will be written in `UPPER_SNAKE_CASE`.

#### 2.3.1.5 Functions

- Function names will be written in `camelCase`.

### 2.3.2 - Formatting Conventions

The project will follow the following formatting conventions:

#### 2.3.2.1 - Indentation

- Indentation will be done with 4 spaces.
- Indentation will be done with spaces, not tabs.

#### 2.3.2.2 - Line Length

- Lines will be limited to 80 characters.
- Lines will be limited to 120 characters for comments.

#### 2.3.2.3 - Line Breaks

- Break the line two spaces before a function call.
- Break the line two spaces before a function declaration.
- Break the line one space between each variables declaration.
- Do not break the line between a function name and its parameters.
- Do not break the line in an if or a switch statement.
- Do not break the line in a for or a while loop.

#### 2.3.2.4 - Comments

- Comments will be written in English.
- Comments will be written on the line above the code they refer to.
- Comments will be written in `Sentence case`.

## 2.4 - Assembly Syntax

[*(Back to top)*](#toc)

### 2.4.1 - Registers

**Question:** What is a register?

**Answer:** A register is a small amount of storage available as part of a CPU. Registers usually consist of a small amount of fast storage, although some registers have specific hardware functions, and may be read-only or write-only.

#### 2.4.1.1 - Storing an immediate value into a register

We'll use the following syntax:

```asm
MOV reg, immediate_value
```

Here is an example:

```asm
MOV ra, 5
```

In this example, the value `5` is stored in the register `ra`.

#### 2.4.1.2 Copying the value of a register into another register

We'll use the following syntax:

```asm
MOV destination_reg, source_reg
```

Here is an example:

```asm
MOV ra, rb
```

In this example, the value of the register `rb` is copied into the register `ra`.

#### 2.4.1.3 Reading the value from the memory to a register 

We'll use the following syntax:

```asm
PRF source_reg, destination_reg
```

Here is an example:

```asm
PRF ra, rb
```
In this example, the value of the register `ra` is copied into the register `rb`.

#### 2.4.1.4 Writing the value from a register to the memory

We'll use the following syntax:

```asm
PRF destination_reg, source_reg
```

Here is an example:

```asm
PRF rb, ra
```

In this example, the value of the register `rb` is copied into the register `ra`.

### 2.4.2 - Jumping to a label

**Question:** What is jumping?

**Answer:** Jumping is the process of transferring control from one part of a program to another.

#### 2.4.2.1 - Jumping unconditionally

We'll use the following syntax:

```asm
JMP label
```

Here is an example:

```asm
JMP labelOne
```

In this example, the program will jump to the label `labelOne`.

#### 2.4.2.2 - Jumping conditionally (where "cc" is a condition code)

We'll use the following syntax:

```asm
Jcc label
```

List of condition codes:

- `JE` - Jump if equal
- `JNE` - Jump if not equal
- `JZ` - Jump if zero
- `JNZ` - Jump if not zero
- `JG` - Jump if greater than
- `JL` - Jump if less than
- `JGE` - Jump if greater than or equal
- `JLE` - Jump if less than or equal

Here are some examples:

```asm
JE labelOne
JNE labelTwo
JZ labelThree
JNZ labelFour
JG labelFive
JL labelSix
JGE labelSeven
JLE labelEight
```

In these examples, the program will jump to the label :

- `labelOne` if the result of the previous instruction are equal.
- `labelTwo` if the result of the previous instruction are not equal.
- `labelThree` if the result of the previous instruction are zero.
- `labelFour` if the result of the previous instruction are not zero.
- `labelFive` if the result of the previous instruction are greater than.
- `labelSix` if the result of the previous instruction are less than.
- `labelSeven` if the result of the previous instruction are greater than or equal.
- `labelEight` if the result of the previous instruction are less than or equal.

### 2.4.3 - Comparing registers

**Question:** What is comparing?

**Answer:** Comparing is the process of comparing the content of registers.

We'll use the following syntax:

```asm
CMP reg1, reg2
```

Here is an example:

```asm
CMP ra, rb
```

In this example, the content of the register `ra` is compared to the content of the register `rb`.

### 2.4.4 - Calling a subroutine

**Question:** What is a subroutine?

**Answer:** A subroutine is a sequence of program instructions that performs a specific task, packaged as a unit.

We'll use the following syntax:

```asm
CALL subroutine_label
```

Here is an example:

```asm
CALL subroutineOne
```

In this example, the program will call the subroutine `subroutineOne`.

### 2.4.5 - Returning from a subroutine

We'll use the following syntax:

```asm
RET
```

### 2.4.6 - Arithmetic operations

#### 2.4.6.1 - Addition

We'll use the following syntax:

```asm
ADD destination_reg, source_reg/immediate_value
```

Here is an example:

```asm
ADD ra, rb
ADD ra, 5
```

In these examples, the value of the register `rb` is added to the value of the register `ra`. In the second example, the value `5` is added to the value of the register `ra`.

#### 2.4.6.2 - Subtraction

We'll use the following syntax:

```asm
SUB destination_reg, source_reg/immediate_value
```

Here is an example:

```asm
SUB ra, rb
SUB ra, 8
```

In these examples, the value of the register `rb` is subtracted from the value of the register `ra`. In the second example, the value `8` is subtracted from the value of the register `ra`.

#### 2.4.6.3 - Multiplication

We'll use the following syntax:

```asm
MUL destination_reg, source_reg/immediate_value
```

Here is an example:

```asm
MUL ra, rb
MUL ra, 3
```

In these examples, the value of the register `ra` is multiplied by the value of the register `rb`. In the second example, the value of the register `ra` is multiplied by the value `3`.

#### 2.4.6.4 - Division

We'll use the following syntax:

```asm
DIV destination_reg, source_reg/immediate_value
```

Here is an example:

```asm
DIV ra, rb
DIV ra, 2
```

In these examples, the value of the register `ra` is divided by the value of the register `rb`. In these example, the value of the register `ra` is divided by the value `2`.

### 2.4.7 - Logical operations

**Question:** What is a logical operation?

**Answer:** A logical operation is an operation that can be performed on one or more logical operands and that produces a logical result.

#### 2.4.7.1 - Logical AND

We'll use the following syntax:

```asm
AND destination_reg, source_reg/immediate_value
```

Here is an example:

```asm
AND ra, rb
AND ra, 1
```

In these examples, the value of the register `ra` is compared to the value of the register `rb`. In the second example, the value of the register `ra` is compared to the value `1`.

If the result of the comparison is true, the value `1` is stored in the register `ra`. If the result of the comparison is false, the value `0` is stored in the register `ra`.

#### 2.4.7.2 - Logical OR

We'll use the following syntax:

```asm
OR destination_reg, source_reg/immediate_value
```

Here is an example:

```asm
OR ra, rb
OR ra, 4
```

In these examples, the value of the register `ra` is compared to the value of the register `rb`. In the second example, the value of the register `ra` is compared to the value `4`.

If the result of the comparison is true, the value `1` is stored in the register `ra`. If the result of the comparison is false, the value `0` is stored in the register `ra`.

#### 2.4.7.3 - Logical XOR

We'll use the following syntax:

```asm
XOR destination_reg, source_reg/immediate_value
```

Here is an example:

```asm
XOR ra, rb
XOR ra, 2
```

In these examples, the value of the register `ra` is compared to the value of the register `rb`. In the second example, the value of the register `ra` is compared to the value `2`.

If the result of the comparison is true, the value `1` is stored in the register `ra`. If the result of the comparison is false, the value `0` is stored in the register `ra`.

#### 2.4.7.3 - Logical NOT

We'll use the following syntax:

```asm
NOT destination_reg
```

Here is an example:

```asm
NOT ra
```

In this example, the value of the register `ra` is inverted.

If the result of the comparison is true, the value `1` is stored in the register `ra`. If the result of the comparison is false, the value `0` is stored in the register `ra`.

#### 2.4.8 - Comments

We'll use the following syntax:

```asm
; This is a comment
```

Here is an example:

```asm
; The following code will add 5 to the value of the register ra
ADD ra, 5
```
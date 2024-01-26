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
- [================================================================================================](#)
- [================================================================================================](#-1)
- [================================================================================================](#-2)
- [================================================================================================](#-3)
- [================================================================================================](#-4)
    - [1.4 - Product and Technical Requirements](#14---product-and-technical-requirements)
    - [1.5 - Out of Scope](#15---out-of-scope)
          - [*(Back to top)*](#back-to-top)
    - [1.6 - Future Goals](#16---future-goals)
          - [*(Back to top)*](#back-to-top-1)
    - [1.7 - Assumptions](#17---assumptions)
          - [*(Back to top)*](#back-to-top-2)
  - [2 - Solutions](#2---solutions)
    - [2.1 - Proposed Solution](#21---proposed-solution)
          - [*(Back to top)*](#back-to-top-3)
  - [3 - Further Considerations](#3---further-considerations)
  - [4 - Work](#4---work)
  - [5 - Deliberation](#5---deliberation)
  - [6 - End Matter](#6---end-matter)
    - [6.2 - References](#62---references)
          - [*(Back to top)*](#back-to-top-4)
    - [6.3 - Glossary and Terminology](#63---glossary-and-terminology)
          - [*(Back to top)*](#back-to-top-5)
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

| Name   | Role | Contact |
| ------ | ---- | ------- |
| ALGOSUP | Client | [Website](https://www.algosup.com/) |
| Franck JEANNIN | ALGOSUP's Co-Founder  | [LinkedIn](https://www.linkedin.com/in/franck-jeannin/) |
| Eric LARCHEVEQUE | ALGOSUP's Co-Founder  | [LinkedIn](https://www.linkedin.com/in/ericlarch/) |
| Natacha BOEZ | ALGOSUP's Co-Founder  | [LinkedIn](https://www.linkedin.com/in/natacha-boez-913a33167/) |

## 1.3 - Usage
[*(Back to top)*](#toc)



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





# ================================================================================================
# ================================================================================================
# ================================================================================================
# ================================================================================================
# ================================================================================================

### 1.4 - Product and Technical Requirements
[*(Back to top)*](#toc)


**Assembly Language Design:** The assembly language will be designed to be as simple as possible, with a minimal set of instructions and features. The language will be designed to be easy to learn and use for beginners, while still providing a useful tool for more advanced users.

Here is a list of the instructions that will be implemented in the assembly language:

| Instruction | Description                                                                                          | Syntax                                            |
| ----------- | ---------------------------------------------------------------------------------------------------- | ------------------------------------------------- |
| `MOV`       | Storing an immediate value into a register.                                                          | `MOV reg, immediate_value`                        |
| `MOV`       | Copying the value of a register into another register.                                               | `MOV destination_reg, source_reg`                 |
| `MOV`       | Reading the value of the memory at the address contained by a register into another register.        | `MOV destination_reg, [source_reg]`               |
| `MOV`       | Storing the value of a register into memory at the address contained by another register.            | `MOV [destination_reg], source_reg`               |
| `CMP`       | Comparing the content of registers.                                                                  | `CMP reg1, reg2`                                  |
| `JMP`       | Jumping unconditionally to a label.                                                                  | `JMP label`                                       |
| `JE`        | Jumping conditionally to a label if equal.                                                           | `JE label`                                        |
| `Jcc`       | Jumping conditionally to a label (where "cc" is a condition code).                                   | `Jcc label`                                       |
| `CALL`      | Calling a subroutine.                                                                                | `CALL subroutine_label`                           |
| `RET`       | Returning from a subroutine.                                                                         | `RET`                                             |
| `ADD`       | Addition - Adds the value of the second operand to the first operand.                                | `ADD destination_reg, source_reg/immediate_value` |
| `SUB`       | Subtraction - Subtracts the value of the second operand from the first operand.                      | `SUB destination_reg, source_reg/immediate_value` |
| `MUL`       | Multiplication - Multiplies the first operand by the second operand.                                 | `MUL source_reg/immediate_value`                  |
| `DIV`       | Division - Divides the first operand by the second operand.                                          | `DIV source_reg/immediate_value`                  |
| `OR`        | Logical OR - Combines the bits of the first operand and second operand.                              | `OR destination_reg, source_reg/immediate_value`  |
| `AND`       | Logical AND - Compares each bit of the first operand to the corresponding bit of the second operand. | `AND destination_reg, source_reg/immediate_value` |
| `XOR`       | Logical XOR - Performs a bitwise exclusive OR operation on each pair of bits.                        | `XOR destination_reg, source_reg/immediate_value` |
| `NOT`       | Logical NOT - Inverts all the bits of the operand.                                                   | `NOT destination_reg`                             |


### 1.5 - Out of Scope
###### [*(Back to top)*](#toc)


**GU:** Development of a GUI for the interpreter is not included.

**Hardware-specific optimizations:** The project will not focus on optimizations for specific hardware configurations.

**Advanced Assembly Features**: Complex assembly language features like threading or advanced memory management are not within the scope.

**Cross-language Support:** Integration with languages other than C for the interpreter is not planned.

**Real-time Execution Monitoring:** Tools for real-time performance analysis are not included.

### 1.6 - Future Goals
###### [*(Back to top)*](#toc)


**Enhanced Assembly Language:** Future versions may include more complex instructions and features to expand the utility of the processor.

**GUI Development:** Developing a user-friendly GUI for easier interaction with the virtual processor.

**Cross-Platform Compatibility:** Enhancements for seamless operation across different operating systems.

**Performance Optimization:** Advanced performance optimization for specific use cases or hardware.

**Integration with Other Programming Languages:** Enabling the interpreter to work with other popular programming languages.

### 1.7 - Assumptions
###### [*(Back to top)*](#toc)


**Environment:** The project assumes availability of a standard C development environment with GCC compiler.

**Standard C Libraries:** C standard libraries are assumed to not be used for the development of the interpreter.

**Stakeholder Engagement:** Continuous engagement and feedback from stakeholders throughout the development process.

**Technical Expertise:** The team assumes a foundational understanding of assembly language and processor architecture among its members.

**Testing and Validation:** Access to sufficient resources for thorough testing and validation of the software.

---

## 2 - Solutions


<!-- ### 2.1 - Existing Solution
**Analysis:** Discussion of the current solution and its pros/cons. -->

### 2.1 - Proposed Solution
###### [*(Back to top)*](#toc)


**Components:**
Our Solution will be composed of 2 main components:

- The **Parser**, which will be in charge of reading the assembly code and split it into tokens. It will also be in charge of checking the syntax of the code and report any error to the user.

- The **Interpreter**, which will be in charge of executing the assembly code. It will also be in charge of checking the semantics of the code and report any error to the user.

**Architecture:**
The architecture of our solution will be composed of 3 main layers:

- The **User Interface**, which will be in charge of interacting with the user. It will also be in charge of displaying the output of the assembly code.

**Test Plan:** How tests will ensure user requirements are met.

**Monitoring and Alerting Plan:** Tools and strategies for monitoring and alerting.

**Release / Roll-out and Deployment Plan:** Details of deployment, phased roll-out, and user communication.

**Rollback Plan:** Strategies for rollback and minimizing impact on other systems.

**Alternate Solutions / Designs:** Evaluation of alternative solutions with pros/cons.


## 3 - Further Considerations

Impact on Other Teams, Third-party Services, Cost Analysis, Security, Privacy, Regional, Accessibility, Operational Considerations, and Risks: Detailed analysis of these aspects.
Success Evaluation

<!-- ### 3.1 - Impact
**Analysis:** Security, performance, cost, and impact on other components. -->

<!-- ### 3.2 - Metrics
**Measurement:** Metrics and tools for evaluation. -->

## 4 - Work

<!-- ### 4.1 - Work Estimates and Timelines
**Breakdown:** List of tasks with resources and timelines. -->

<!-- ### 4.2 - Prioritization
**Urgency and Impact:** Categorization of tasks. -->

<!-- ### 4.3 - Milestones
**Checkpoints:** Significant points in the project timeline. -->

<!-- ### 4.4 - Future Work
**Roadmap:** Tasks planned for future implementation. -->

## 5 - Deliberation

<!-- ### 5.1 - Discussion
**Debate Points:** Areas of disagreement or uncertainty. -->

<!-- ### 5.2 - Open Questions
**Inquiries:** Questions seeking team input. -->

## 6 - End Matter

<!-- ### 6.1 - Related Work
**External References:** Similar projects or initiatives by other teams. -->

### 6.2 - References
###### [*(Back to top)*](#toc)


**Functional Specifications:** *[Click Here](../Functional-Specification.md)*

**Test Plan:** *[Click Here](../Test-Plan.md)*

<!-- ### 6.3 - Acknowledgments
**Contributions:** Recognition of key contributors. -->

### 6.3 - Glossary and Terminology
###### [*(Back to top)*](#toc)

[^1]:Virtual Processor: A software emulation of a computer processor.

[^2]:Interpreter: A program that executes instructions written in a high-level language.

[^3]:Assembly Language: A low-level programming language for a computer or other programmable device, in which each statement corresponds to a single machine instruction.

[^4]:C: A general-purpose, procedural computer programming language supporting structured programming, lexical variable scope, and recursion, with a static type system.

[^5]:Low-level programming: Programming at a level close to a computer's hardware/software interface.


<!-- 

Header
Overview


 -->
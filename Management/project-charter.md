# Project Proposal: Virtual Processor and Interpreter

## Project Overview

The purpose of this project is to develop a virtual processor and an interpreter for executing assembly[^1] code on the proposed processor. The project will be implemented in plain, portable C language without external libraries, with the recommended use of gcc as a compiler and Visual Studio Code as the IDE.

## Project Goals

- Create a minimal assembly language for the virtual processor with essential instructions.
- Develop a virtual processor capable of executing assembly programs written in the specified language.
- Implement a C program to read, validate, and run assembly code, checking for semantic and syntactic errors.
- Introduce a virtual system call for text display in a virtual terminal, enabling interaction with assembly code.
- Include features like displaying register content and a built-in debugger for effective debugging.

## Assembly Language Specifications

The assembly language will include, but is not limited to, the following instructions:

- Storing an immediate value into a register.
- Copying the value of a register into another register.
- Reading and storing values between registers and memory.
- Comparison of register contents.
- Unconditional and conditional jumps.
- Subroutine calls and returns.
- Arithmetic operations: addition, subtraction, multiplication, and division.
- Logical operations: OR, AND, XOR, and NOT.

## Glossary

- **Assembly Language:** A low-level programming language that closely corresponds to the architecture of a computer's machine code.

- **Virtual Processor:** A simulated processor implemented in software, emulating the behavior of a physical CPU.

- **Interpreter:** A program that reads and executes instructions directly, without the need for a separate compilation step.

- **Semantic Errors:** Errors related to the meaning or logic of the program rather than its syntax.

- **Syntactic Errors:** Errors related to the structure and grammar of the programming language.

- **System Call:** A request in a Unix-like operating system made via a software interrupt to the kernel for a specific service.

## Deliverables and Deadlines

- **Functional Specification Deadline (30/1, 5pm):**
  - Detailed description of assembly language syntax, semantics, and virtual processor behavior.

- **Technical Specification Deadline (9/2, 5pm):**
  - In-depth explanation of the implementation, architecture, and interactions within the system.

- **Test Plan Deadline (16/2, 5pm):**
  - Comprehensive testing strategy covering unit and integration tests.

- **Final Product Deadline (23/2, 5pm):**
  - Delivery of the completed project, including the virtual processor, interpreter, C program, and documentation.

## Team Roles

- Project Manager: [Laura-Lee Hollande]()
- Program Manager: [Ian Laurent]()
- Technical Lead: [Pierre Gorin]()
- Software Engineer: [Victor Leroy]() & [Manech Laguens]()
- Quality Assurance: [Evan Uhring]() & [Laurent Bouquin]()

## Communication Plan

- Regular team meetings: [Specify frequency and mode of communication]
- Progress updates: [Specify reporting structure and tools]

## Risks and Mitigation

- Identify potential risks: [List potential risks]
- Mitigation strategies: [Describe strategies to address each risk]

## Budget and Resources

- Budget allocation: [Specify budget for any required resources]
- Required resources: [List hardware, software, or external services needed]

## Conclusion

This project proposal outlines the scope, goals, and deliverables of the Virtual Processor and Interpreter project. The successful completion of this project will result in a robust system capable of executing assembly code within the specified parameters.

---
**Project Manager: [Your Name]**
**Date: [Current Date]**

[^1]: An assembly language is a type of low-level programming language that is intended to communicate directly with a computer’s hardware. Unlike machine language, which consists of binary and hexadecimal characters, assembly languages are designed to be readable by humans.
*source : [Investopedia](https://www.investopedia.com/terms/a/assembly-language.asp)*

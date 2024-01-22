# Project Proposal: Virtual Processor and Interpreter

## Project Overview

The purpose of this project is to develop a virtual processor[^1] and an interpreter[^2]: for executing assembly[^3] code on the proposed processor. The project will be implemented in plain, portable C language without external libraries, with the recommended use of gcc as a compiler and Visual Studio Code as the IDE.

## Project Goals

- Create a minimal assembly language for the virtual processor with essential instructions.
- Develop a virtual processor capable of executing assembly programs written in the specified language.
- Implement a C program to read, validate, and run assembly code, checking for semantic[^4] and syntactic errors[^5]:.
- Introduce a virtual system call[^6]: for text display in a virtual terminal, enabling interaction with assembly code.
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

## Deliverables and Deadlines

- **Functional Specification Deadline (01/30, 5pm):**
  - Detailed description of assembly language syntax, semantics, and virtual processor behavior.

- **Technical Specification Deadline (02/9, 5pm):**
  - In-depth explanation of the implementation, architecture, and interactions within the system.

- **Test Plan Deadline (02/16, 5pm):**
  - Comprehensive testing strategy covering unit and integration tests.

- **Final Product Deadline (02/23, 5pm):**
  - Delivery of the completed project, including the virtual processor, interpreter, C program, and documentation.

## Team Roles

- Project Manager: [Laura-Lee Hollande](https://github.com/lauraleehollande)
- Program Manager: [Ian Laurent](https://github.com/Ianlaur)
- Technical Lead: [Pierre Gorin](https://github.com/Pierre2103)
- Software Engineer: [Victor Leroy](https://github.com/Victor-Leroy) & [Manech Laguens](https://github.com/Manech-Laguens)
- Quality Assurance: [Evan Uhring](https://github.com/Evan-UHRING) & [Laurent Bouquin](https://github.com/laurentbouquin)

## Communication Plan

- Regular team meetings: [Specify frequency and mode of communication]
- Progress updates: [Specify reporting structure and tools]

## Risks and Mitigation

1. **Technical Complexity:**
   - **Risk:** The project involves complex technical aspects that may lead to delays or difficulties in implementation.
   - **Mitigation:** Conduct thorough research and prototyping in the early stages. Regularly review progress with the technical lead and seek external expertise if needed.

2. **Resource Constraints:**
   - **Risk:** Limited budget and resources may affect the project's timeline and quality.
   - **Mitigation:** Clearly define resource requirements in advance. Explore open-source tools and libraries to minimize costs. Regularly reassess the budget and allocate resources judiciously.

3. **Unexpected Changes in Requirements:**
   - **Risk:** Stakeholders may introduce changes to project requirements during development.
   - **Mitigation:** Establish a robust change management process. Document and review any changes before implementation. Communicate changes promptly to the team.

4. **Quality Assurance Challenges:**
   - **Risk:** Identifying and resolving bugs and issues may be time-consuming.
   - **Mitigation:** Develop a comprehensive test plan early in the project. Conduct thorough testing at each stage. Implement continuous integration for automated testing. Allocate sufficient time for debugging and issue resolution.

5. **Team Communication Breakdown:**
   - **Risk:** Lack of effective communication may lead to misunderstandings and delays.
   - **Mitigation:** Implement regular team meetings, clearly define communication channels, and encourage open and transparent communication. Use collaboration tools to facilitate information sharing.

## Resources

- **Required Resources:**
The following resources are essential for the successful completion of the project:
  - **Development Environment:**
    - Workstations for development, including appropriate hardware specifications.
    - Software licenses for development tools and IDEs.
  - **Collaboration Tools:**
    - Project management tools for task tracking and team collaboration.
    - Version control system for code management.
  - **Testing Environment:**
    - Hardware or virtual machines for testing the virtual processor and interpreter.
    - Testing tools and frameworks.
  - **Documentation Tools:**
    - Software for creating and maintaining project documentation.
  - **Management Tools:**
    - Software for managing the team.

<!-- Add budget if needed -->

## Conclusion

This project proposal outlines the scope, goals, and deliverables of the Virtual Processor and Interpreter project. The successful completion of this project will result in a robust system capable of executing assembly code within the specified parameters.

---
**Project Manager: Laura-Lee Hollande**
**Date: 01/16/24**

---
[^1]: A virtual processor is a representation of a physical processor core to the operating system of a logical partition that uses shared processors.
*source : [IBM](https://www.ibm.com/docs/en/power8?topic=processors-virtual)*
[^2]: The interpreter in the compiler checks the source code line-by-line and if an error is found on any line, it stops the execution until the error is resolved.
*source : [GeeksforGeeks](https://www.geeksforgeeks.org/introduction-to-interpreters/)*
[^3]: An assembly language is a type of low-level programming language that is intended to communicate directly with a computer’s hardware. Unlike machine language, which consists of binary and hexadecimal characters, assembly languages are designed to be readable by humans.
*source : [Investopedia](https://www.investopedia.com/terms/a/assembly-language.asp)*
[^4]: A semantic error has to do with meaning. If a program contains this kind of error, it will successfully run, but won’t output the correct result.
*source : [Educative](https://www.educative.io/answers/what-is-the-difference-between-syntax-and-semantic-errors)*
[^5]: A programming language is very strict and unambiguous, so a syntax error occurs when we don’t respect or follow the language vocabulary. As a result, the program can’t run, and a useful error message will print instead.
*source : [Educative](https://www.educative.io/answers/what-is-the-difference-between-syntax-and-semantic-errors)*
[^6]: A system call is a mechanism used by programs to request services from the operating system (OS). In simpler terms, it is a way for a program to interact with the underlying system, such as accessing hardware resources or performing privileged operations.
*source : [GeeksforGeeks](https://www.geeksforgeeks.org/introduction-of-system-call/)*

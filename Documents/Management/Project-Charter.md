# Project Proposal: Virtual Processor and Interpreter

## Project Overview

The purpose of this project is to develop a virtual processor[^1] and an interpreter[^2] for executing assembly[^3] code on the proposed processor. The project will be implemented in plain, portable C language without external libraries, with the recommended use of gcc[^4] as a compiler and Visual Studio Code as the IDE.

## Project Goals

- Create a minimal assembly language for the virtual processor with essential instructions.
- Develop a virtual processor capable of executing assembly programs written in the specified language.
- Implement a C program to read, validate, and run assembly code, checking for semantic[^5] and syntactic errors[^6].
- Introduce a virtual system call[^7] for text display in a virtual terminal, enabling interaction with assembly code.
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

## Stakeholders

| Name                            | Role     | Representative | Point of contact | Influence                                                                                                                                                                                                                                                                | Expectations                                                                                                                                                                                                                                                                                                                                                 |
| ------------------------------- | -------- | -------------- | ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| [ALGOSUP](https://algosup.com/) | Customer | Franck Jeannin | Mail/Slack       | The customer sets the requirements for the final product. The team seeks approval from the client for major decisions, making them the key decision-maker in the project. Their input holds the utmost significance in shaping the direction of the development process. | The customer expects the development of a reliable virtual processor and interpreter that follows the specified assembly language standards. The product should perform well, be compatible with different systems, and include features like system calls and a debugger. Clear documentation and timely communication are crucial for successful delivery. |

## Communication Plan

- Regular team meetings: 2 by week.

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

The following resources are essential for the successful completion of the project:

- **Development Environment:**
  - Workstations for development, including appropriate hardware specifications.
  - Software licenses for development tools and the integrated development environment[^8].
    - [Visual Studio Code](https://code.visualstudio.com/)[^9]
- **Collaboration Tools:**
  - Project management tools for task tracking and team collaboration.
  - Version control system for code management.
    - [Git](https://git-scm.com/)[^10]
    - [GitHub](https://github.com/)[^11]
- **Testing Environment:**
  - Hardware or virtual machines for testing the virtual processor and interpreter.
  - Testing tools and frameworks.
- **Documentation Tools:**
  - Software for creating and maintaining project documentation.
    - GitHub
- **Management Tools:**
  - Software for managing the team
    - [Trello](https://trello.com/home)[^12]
    - [Slack](https://slack.com/)[^13]

## Success criteria

The success of the project will be evaluated based on the following criteria:

1. **Functionality:**
   - Successful implementation of the virtual processor and interpreter with a complete set of essential assembly language instructions.
   - Correct execution of arithmetic operations, logical operations, and control flow as specified in the functional specification.

2. **Performance:**
   - Efficient performance of the virtual processor, meeting or exceeding predefined benchmarks for speed and resource utilization.

3. **Portability:**
   - Successful development of the project in plain C language with compatibility across different systems.
   - Seamless integration with the recommended development tools, specifically gcc as the compiler and Visual Studio Code as the IDE.

4. **Reliability:**
   - Reliable execution of assembly code with minimal errors or unexpected behavior.
   - Robust handling of system calls for text display and the built-in debugger.

5. **Documentation:**
   - Completion of a comprehensive Functional Specification (by 01/30/2024 5 PM) and Technical Specification (by 09/02/2023 5 pm).
   - Clear and accessible documentation for the assembly language, virtual processor, and interpreter.

6. **Testing:**
   - Execution of a thorough testing plan (by 02/16/2024 5 PM) covering unit tests, system tests, and any additional testing requirements.
   - Timely identification and resolution of any issues discovered during testing.

7. **Timeliness:**
   - Adherence to the project schedule with the completion of the Final Product by the specified deadline (by 02/23/2024 5 PM).
   - Timely delivery of intermediate milestones, including the Functional Specification, Technical Specification, and Test Plan.

8. **Client Satisfaction:**
   - Approval and acceptance of major decisions by the client.
   - Ongoing collaboration and satisfaction with the development process and deliverables.

This criteria for success section outlines the key benchmarks and expectations that will determine the success of the project. Adjust the details based on the specific nuances and priorities of your project.

## Conclusion

This project proposal outlines the scope, goals, and deliverables of the Virtual Processor and Interpreter project. The successful completion of this project will result in a robust system capable of executing assembly code within the specified parameters.

---
[^1]: A virtual processor is a representation of a physical processor core to the operating system of a logical partition that uses shared processors.
*source : [IBM](https://www.ibm.com/docs/en/power8?topic=processors-virtual)*
[^2]: The interpreter in the compiler checks the source code line-by-line and if an error is found on any line, it stops the execution until the error is resolved.
*source : [GeeksforGeeks](https://www.geeksforgeeks.org/introduction-to-interpreters/)*
[^3]: An assembly language is a type of low-level programming language that is intended to communicate directly with a computer’s hardware. Unlike machine language, which consists of binary and hexadecimal characters, assembly languages are designed to be readable by humans.
*source : [Investopedia](https://www.investopedia.com/terms/a/assembly-language.asp)*
[^4]: It is an optimizing compiler produced by the GNU Project supporting various programming languages, hardware architectures and operating systems.
*source : [Wikipedia](https://en.wikipedia.org/wiki/GNU_Compiler_Collection)*
[^5]: A semantic error has to do with meaning. If a program contains this kind of error, it will successfully run, but won’t output the correct result.
*source : [Educative](https://www.educative.io/answers/what-is-the-difference-between-syntax-and-semantic-errors)*
[^6]: A programming language is very strict and unambiguous, so a syntax error occurs when we don’t respect or follow the language vocabulary. As a result, the program can’t run, and a useful error message will print instead.
*source : [Educative](https://www.educative.io/answers/what-is-the-difference-between-syntax-and-semantic-errors)*
[^7]: A system call is a mechanism used by programs to request services from the operating system (OS). In simpler terms, it is a way for a program to interact with the underlying system, such as accessing hardware resources or performing privileged operations.
*source : [GeeksforGeeks](https://www.geeksforgeeks.org/introduction-of-system-call/)*
[^8]: An IDE, enables programmers to consolidate the different aspects of writing a computer program.
*source : [Codecademy](https://www.codecademy.com/article/what-is-an-ide)*
[^9]: It is a source-code editor developed by Microsoft for Windows, Linux and macOS.
*source : [Wikipedia](https://en.wikipedia.org/wiki/Visual_Studio_Code)*
[^10]: Git is a free and open source distributed version control system designed to handle everything from small to very large projects with speed and efficiency.
*source : [Git](https://git-scm.com/)*
[^11]: It is a developer platform that allows developers to create, store, manage and share their code..
*source : [Wikipedia](https://en.wikipedia.org/wiki/GitHub)*
[^12]: Trello is a web-based, kanban-style, list-making application and is developed by Trello Enterprise, a subsidiary of Atlassian.
*source : [Wikipedia](https://en.wikipedia.org/wiki/Trello)*
[^13]: Slack is a cloud-based team communication platform developed by Slack Technologies, which is currently owned by Salesforce.
*source : [Wikipedia](https://en.wikipedia.org/wiki/Slack_(software))*

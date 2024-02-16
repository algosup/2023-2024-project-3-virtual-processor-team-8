# Test plan


## Table of contents

- [Test plan](#test-plan)
	- [Table of contents](#table-of-contents)
	- [1. Introduction](#1-introduction)
		- [A. Overview](#a-overview)
		- [B. Hardware and software](#b-hardware-and-software)
	- [2. Test strategy and criteria](#2-test-strategy-and-criteria)
		- [A. Quality assurance team](#a-quality-assurance-team)
		- [B. Testing scope and method](#b-testing-scope-and-method)
		- [C. Tools](#c-tools)
		- [D. Test criteria](#d-test-criteria)
	- [3. Test plan environment](#3-test-plan-environment)
	- [4. Schedule estimation](#4-schedule-estimation)
	- [5. Deliverables](#5-deliverables)
		- [**Glossary**](#glossary)
		- [Footnotes](#footnotes)


## 1. Introduction

### A. Overview

The goal of the project is to create a virtual processor[^1] and an interpreter[^2] to execute a lookalike assembly language. It has to be made in the C language, and has to be portable. The compiler[^3] used is gcc and the IDE[^4] is Visual Studio Code.


### B. Hardware and software

During the project, we will use computers running on Windows and MAC OS. The language used is C, and the assembly language that will be executed by the program created will be written in a ".asm" file.



## 2. Test strategy and criteria

### A. Quality assurance team

For this project, are team is composed of 2 QAs[^5] :

- Laurent BOUQUIN
- Evan UHRING


### B. Testing scope and method

We will verify the quality of the program, as well as every documents.

For the documents, we will verify the content, as well as the syntax and the grammar, to be sure that no misunderstanding is left over, and thus having clear and readable documents for the client, and also for the team. In case of a problem in the content, the subject will be discussed with the team to find a solution that corresponds to the problem. If there is a problem with the syntax or the grammar, each QA[^5] of our group will check the mistake then discuss it between them and if the mistake is proven, an issue will be created on Github[^6] using the template for typographical syntax errors. Once the issue is created, the person responsible for the document will be in charge of modifying the document and closing the issue.

For the program, as asked by the client, we will create multiple assembly language templates that will be used as help for unit testing. There will also be a document grouping all the test cases that the group can think of and they will be tested by the QAs[^5] of the group on the program. If a problem is found, an issue will be created on Github[^6] using the template for bugs. Once the issue is created, the person responsible for the program will be in charge of modifying the program and closing the issue.

As an help for the QAs[^5], files will be created to help them to test the program. Those files will be named based on the file they are testing and will contains tests for each function that can be tested (functions only used to print things can't be tested).

We have decided to give to each issue that we find a different level of importance. Those level of importance will help us to tell if the issue is important or not, and thus helping us having a better organization. The different level of importance are :
- ${\color{green}Optional \space (P4)}$ (Task not important but can be done if there is time left)
- ${\color{yellow}Can \space wait \space (P3)}$ (Task not important but should be done)
- ${\color{orange}Should \space be \space done \space quickly \space (P2)}$ (Task that alter the quality of the project)
- ${\color{red}Urgent \space (P1)}$ (Task that alter the quality of the project and can't wait)

Their name are explicit to help us understand much quicker the importance of the issue.


### C. Tools

To report issues, we will use a functionality of Github[^6], called Github Issue[^7]. It helps us to do reports faster, and to have reports easier to read. We have decided to make two types templates for the reports, one for the documents and one for the program.

The report template for the typographical errors tells which document is concerned, what are the errors and what is its priority. 
![Typographical Error report template](Images/Typographical-Error-Report-Template.png)

The report template for the bugs tells what happened during the testing, which operating system was used, and a way to tell which operating system was used if it was not in the selection box, the log outputs for more precise information and its priority.
![Bug report template](Images/Bug-Report-Template.png)


### D. Test criteria

We will judge if the program is working properly by testing each function of the program that can be tested. We will be able to determine if the code is working properly by comparing the output of the program with the expected output using the units tests we have created. If the output is the same, the function is working properly, if not, the function is not working properly and will output an error message with as much details as possible.




## 3. Test plan environment

Our team members have different computer OS, which are Windows and MacOs, that gives us the opportunity of testing that the program is working properly on the different OS. But also the environment is different and so the steps to be capable to test are different.


The tests will be run on the following computers :

| Specification    | Lenovo ThinkBook 14  | Lenovo ThinkBook 14  | Lenovo ThinkPad 2023 | Apple MacBook Air M1 2020 | Apple MacBook Air M1 2020 |
| ---------------- | -------------------- | -------------------- | -------------------- | ------------------------- | ------------------------- |
| Processor        | Intel Core i7-1065G7 | Intel Core i7-1165G7 | Intel Core i7-1355U  | Apple Silicon M1          | Apple Silicon M1          |
| RAM         | 16 GB                 | 16 GB                | 16 GB                 | 8 GB                      | 8 GB                      |
| Operating System | Windows 11 Pro       | Windows 11 Pro       | Windows 11 Pro       | macOS Ventura             | macOS Sonoma              |



## 4. Schedule estimation

It is necessary to correctly spread out our time between each task, so we can be more efficient on the tests we have to do. Our total number of hours we have is 104 hours.

| Task | Subtask | Time estimation |
| --- | --- | --- |
| Analyze requirement specification | - Review functional specifications <br> - Review technical specification| - 6 hours <br> - 6 hours |
| Create the test specification |  - Create the test plan <br> - Create test cases <br> - Review the test cases|- 30 hours <br> - 12 hours <br> - 4 hours |
| Execute the test cases | - Build up the test environment <br> - Execute the test cases <br> - Update test cases status|- 10 hours <br> - 14 hours <br> - 6 hours |
| Report the bug | - Create bug reports <br> - Create bug data report | - 6 hours <br> - 6 hours |

If this estimation is correct, we will have spent 100 hours for the quality assurance of the project, as our number of working time we have available.



## 5. Deliverables

The testing deliverables for this project are :
- From the client:
	- The Test Plan ( 02/09/2024 at 5:00pm )
	- The Test Cases ( 02/09/2024 at 5:00pm )
	- The Bugs Report ( 02/23/2024 at 5:00pm )
- From the team :
	- Unit tests ( 02/16/2024 at 5:00pm )




### **Glossary**


| Term | Definition | additional content |
| :---: | :---: | :---: |
| Virtual Processor[^1] | A virtual processor is a software engine that executes instructions, emulating the behavior of a physical processor. | [IBM](https://www.ibm.com/docs/en/power8?topic=processors-virtual) |
| Interpreter[^2] | In computer science, an interpreter is a computer program that directly executes instructions written in a programming or scripting language, without requiring them previously to have been compiled into a machine language program. | [Wikipedia](https://en.wikipedia.org/wiki/Interpreter_(computing)) |
| Compiler[^3] | A compiler is a computer program that translates computer code written in one programming language (the source language) into another language (the target language). | [Wikipedia](https://en.wikipedia.org/wiki/Compiler) |
| Integrated Development Environment ( IDE )[^4] | An integrated development environment (IDE) is a software application that provides comprehensive facilities to computer programmers for software development. | [Wikipedia](https://en.wikipedia.org/wiki/Integrated_development_environment) |
| QA[^5] | Quality Assurance is the term used in both manufacturing and service industries to describe the systematic efforts taken to assure that the product(s) delivered to customer(s) meet with the contractual.  | [Wikipedia](https://en.wikipedia.org/wiki/Quality_assurance) |
| Github[^6] | GitHub, Inc. is a provider of Internet hosting for software development and version control using Git. | [Wikipedia](https://en.wikipedia.org/wiki/GitHub) |
| Github Issue[^7] | Issues are a great way to keep track of tasks, enhancements, and bugs for your projects. They’re kind of like email—except they can be shared and discussed with the rest of your team. | [Github](https://docs.github.com/en/issues/tracking-your-work-with-issues/creating-an-issue) |




### Footnotes


[^1]: [IBM - Virtual Processor](https://www.ibm.com/docs/en/power8?topic=processors-virtual)
[^2]: [Wikipedia - Interpreter](https://en.wikipedia.org/wiki/Interpreter_(computing))
[^3]: [Wikipedia - Compiler](https://en.wikipedia.org/wiki/Compiler)
[^4]: [Wikipedia - Integrated Development Environment (IDE)](https://en.wikipedia.org/wiki/Integrated_development_environment)
[^5]: [Wikipedia - Quality Assurance](https://en.wikipedia.org/wiki/Quality_assurance)
[^6]: [Wikipedia - Github](https://en.wikipedia.org/wiki/GitHub)
[^7]: [Github - Github Issue](https://docs.github.com/en/issues/tracking-your-work-with-issues/creating-an-issue)
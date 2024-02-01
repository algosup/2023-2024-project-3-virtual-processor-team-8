# Test plan

## Table of content

- [Test plan](#test-plan)
	- [Table of content](#table-of-content)
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



## 1. Introduction

### A. Overview
The goal of the project is to create a virtual processor and an interpreter to execute a lookalike assembly language. It has to be made in the C language, and has to be portable. The compiler used is gcc and the IDE is Visual Studio Code.


### B. Hardware and software
During the project, we will use computers running on Windows and MAC OS. The language used is C, and the assembly language that will be executed by the program created will be written in a .asm file.



## 2. Test strategy and criteria

### A. Quality assurance team
For this project, we will collaborate with the QAs of team 7, for a total of 4 QAs :

From team 8 :
- Laurent BOUQUIN
- Evan UHRING

From team 7 :
- Abderrazaq MAKRAN
- Raphaël PROUDHON

With this collaboration, knowledge and expertise will be shared for a better quality of testing, and thus having more results to help our project solving problems and assuring a better quality. It will allow each group to have the point of view of the other group, and thus having multiple testing methods and results for a better quality of testing of the project.


### B. Testing scope and method
We will verify the quality of the program, as well as every documents.

For the documents, we will verify the content, as well as the syntax and the grammar, to be sure that no misunderstanding is left over, and thus having clear and readable documents for the client, and also for the team. In case of a problem in the content, the subject will be discussed with the team to find a solution that corresponds to the problem. If there is a problem with the syntax or the grammar, each QA of our group will check the mistake then discuss it between them and if the mistake is proven, an issue will be created on Github using the template for typographical syntax errors. Once the issue is created, the person responsible for the document will be in charge of modifying the document and closing the issue.

For the program, as asked by the client, we will create multiple assembly language templates that will be used as help for unit testing. There will also be a document grouping all the test cases that the group can think of and they will be tested by the QAs of the group on the program. If a problem is found, an issue will be created on Github using the template for bugs. Once the issue is created, the person responsible for the program will be in charge of modifying the program and closing the issue.

As an help for the QAs, files will be created to help them to test the program. Those files will be named based on the file they are testing and will contains tests for each function that can be tested (functions only used to print things can't be tested).

We have decided to give to each issue that we find a different level of importance. Those level of importance will help us to tell if the issue is important or not, and thus helping us having a better organization. The different level of importance are :
- Optional
- Can wait
- Should be done quickly
- Urgent

Their name are explicit to help us understand much quicker the importance of the issue.


### C. Tools
To report issues, we will use a functionality of Github, called Github Issue. It helps us to do reports faster, and to have reports easier to read. We have decided to make two types of reports by using templates, one for the documents and one for the program.

The report template for the documents tells which document is concerned, what are the errors and what is its priority. 
![Typographical Error report template](Images/Typographical-Error-Report-Template.png)

The report template for the program tells what happened during the testing, which operating system was used, and a way to tell which operating system was used if it was not in the selection box, the log outputs for more precise information and its priority.
![Bug report template](Images/Bug-Report-Template.png)


### D. Test criteria

We will judge if the program is working properly by testing each function of the program. We will be able to determine if the code is working properly by comparing the output of the program with the expected output using the units tests we have created. If the output is the same, the function is working properly, if not, the function is not working properly and will output an error message with as much details as possible.




## 3. Test plan environment

Our team members have different computer OS, which are Windows and MacOs, that gives us the opportunity of testing that the program is working properly on the different OS. But also the environment is different and so the steps to be capable to test are different.



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
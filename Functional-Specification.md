# Functional specification

## Table of content </summary>
  - [A) Introduction](#b-introduction)
    - [1) Project Overview](#2-project-overview)
    - [2) Project Definition](#3-project-definition)
      - [➭ Vision](#-vision)
      - [➭ Objectives](#-objectives)
      - [➭ Scope](#-scope)
      - [➭ Deliverables](#-deliverables)
      - [ Personas Definition](#2-personas-definition)
        - Persona 1
        - Persona 2
    - [3) Project Organization](#4-project-organisation)
      - [➭ Stakeholders](#-stakeholders)
      - [➭ Project Reviewers](#-project-reviewers)
    - [4) Project Plan](#5-Project-plan)
      - [➭ Retroplanning](#-retroplanning)
      - [➭ Milestones](#-milestones)
      - [➭ Resources / tools](#-resources-tools)
      - [➭ Assumptions/Constraints](#-assumptions-constraints)
  - [B) Functional Requirements](#c-functional-requirements)
      - [➭ Customers requirements] (#Customers-requirements)
      - [➭ Objectives and loss condition](#-objectives-and-loss-condition)
      - [Operability](#operability)
      - [Reliability](#reliability)
      - [Final Product requirements(Foundations for a MVP)](#final-product-requirements)
      - [Emulators features break down](#1b-Emulators-features-breakdown)
      - [➭ Terminal](#Terminal)
      - [➭ Other](#-other)
    - [3) Use Cases Analysis](#3-use-cases-analysis)
    - [4) Functional Analysis](#4-functional-analysis)
  - [C) Non-Functional Requirements](#d-non-functional-requirements)
    - [Response/Performance](#responseperformance)
    - [Recovery](#recovery)
    - [Delivery](#delivery)
    - [Maintainability](#maintainability)
    - [Security](#security)
  - [Conclusion] (#Conclusion)
  - [D) Glossary](#glossary)
</details>

### A. Introduction
As for the overview of the project, the client (ALGOSUP : Franck) has demanded us to create an emulator on which we will have to run an assembly ("[...].asm") file on it. The goal of the project is to create a virtual processor and an interpreter for running assembly code on that processor. The final product must be developed in plain, portable and coded in C language without the use of any external library beside C standard libraries. As for the complicator the client has recommended to use "gcc[^1]" and "Visual studio code[^2]" as IDE (integrated development environment).
As for the operating system the final product will run on MacOS and Windows, and the devices used to develop the product are :

    - Apple MacBook Air 2021, equipped with the "M1" chip running on "Ventura 13.0" MacOS version.

    - Lenovo ThinkPad 2023, equipped with "13th Gen Intel(R) Core(TM) i7-1355U", running on "Windows 11 pro". 

    - Lenovo ThinkBook 2021, equipped with "11th Gen Intel(R) Core(TM) i7-1165G7", running on "windows 11 pro".

The team is composed with 7 members each having a designated role. 

| Team members of team 8 for this project ||
|:-|:-|
| **Name** | **Role** |
| Laura-Lee HOLLANDE| Project Manager |
| Ian LAURENT | Program Manager |
| Pierre GORIN | Technical Lead |
| Manech LAGUENS | Software Engineer |
|  Victor LEROY | Software Engineer |
| Laurent BOUQUIN | Quality Assurance |
| Evan UHRING | Quality Assurance |

## <ins>2.Project overview</ins>
Our team was asked to create an emulator coded in C language, which will have to be able run an assembly code. 

## <ins>3. Project definition</ins>

###  <ins>Project vision</ins>
The project envisions the creation of a virtual processor and interpreter, facilitating the execution of assembly code written in a custom assembly language. The virtual processor aims to provide a platform for running low-level code efficiently. 
### <ins>Objectives</ins> 
Developing a virtual processor capable of executing assembly code is the principal objective.
Being able to create an interpreter for the custom assembly language.
It should implement a set of essential assembly instructions, including arithmetic, logical operations, and control flow.
The team will have to ensure it's portability by developing the project in plain C language, utilizing standard libraries, and recommending specific development tools.
To assure that the Objectives were achieved making unit tests though out the development will wrap all the code and detect as many errors in the code as possible.

### <ins>Scopes</ins>  
The project encompasses the design and development of a virtual processor, interpreter, and associated assembly language. The primary focus is to create a versatile platform capable of executing assembly code efficiently. The scope also extends to consider the potential future applications of the project, opening avenues for integration with broader systems, educational purposes, or as a foundation for building specialized computing environments.
Develop a software able to proceed some basic commands that are written based on an assembly syntax that we developed.

### <ins>Deliverables</ins>
We will have to make sure to deliver the final product in the deadlines that were given by the client. To ensure that the final product will be ready to present, the team has to ensure that all the milestones are achieved and done on time.

As for this document (<n>Functional specification</n>), it's due date is the **01/30/24** and should contain all the information regarding the overview of the project and all the success key to deliver the final product to the client. This document must also contain the outlining of assembly language, explanation of the virtual processors and it's functions, and the interpreter's specifications.

A <u>technical</u> Specification is manditory for this project, and it's due date is **02/09/24**. This document should provide insights into the implementation details, data structures, and the types of algroithms used without giving out the code. It will have to specify the technical aspects of the final product keeping it understandable for the client. Keeping terms employed understandable with explanations if needed, and clear will allow to maintain transperancy of the advancement of the project. 

Testing is key to make sure that the final product is presentable to the client and meets it's expectations. These tests will be done within the team but also with outside insights such as other external individuals. These tests will be specified in a document named a <u>test plan</u>, in this document all tests that have been done on the product must be detailed with a clear understanding on what lead to the issue, it's type meaning either if it's a technical issue or other, and other detailed information to allow to keep track of the issues for the client but also within the team members.

As for the <u>final product</u>, the deadline being 02/23/24, this should be the final version of the product. This version should be fully functional with all the features that was mentioned in this document. This version should obviously meet the satisfaction of the client and respond to the clients needs. This version will be tested before being presented to the client, and should include the virtual processor, interpreter and the associated tools.

### <ins>Personas definition</ins>

#### <ins>Persona 1 :</ins>

#### <ins>Persona 2 :</ins>

## <ins>4. Project organization</ins>

### <ins>Stake holders</ins>
The stake holders for this project is <u>ALGOSUP International software development school</u> represented by <u>Franck JEANNIN</u> backed by Eric LARCHEVEQUE, Natacha BOEZ and Jean-Philipe GRASSE.
### <ins>Project reviewers</ins>

# <ins>Project Plan</ins>

### <ins>Retro-planning</ins>

<img src="<img src="https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8/blob/documents/Img/Gcc-Logo.png" alt="Project Plan" width="75"/>

### <ins>Mile-stones</ins>

|Phases :|Pre-Development|||Development |||Post-Development|
|:-|:-|:-|:-|:-|:-|:-|:-|
|Tasks :|Functional specification|Define Assembly language|Technical specification|Test Plan|Implement Virtual Processor|Write Assembly Programs as Unit Tests|Test Phase|
|Due Date :|01/30/24|...|02/09/24|02/16/24|...|...|...|
|Desired end date :|01/30/24|01/02/24|01/02/24|02/16/24|02/16/24|02/16/24|02/16/24 -> Final deadline (02/23/24)

### <ins>Resources / tools</ins>
environement: Vs code, Github
test environement: 
management enviroment: trello slack 
### <ins>Assumptions/Constraints</ins>

# B. Functional Requirements

### <ins>Customers requirements</ins>

### <ins>Objectives and loss condition</ins>

### <ins>Operability</ins>

### <ins>Reliability</ins>

### <ins>Product requirements(Foundations for a MVP)</ins>

### <ins>Emulators features break down</ins>

### <ins>Terminal</ins>

### <ins>other</ins>

## 3. Use Cases Analysis

## 4. Functional Analysis

# C. Non-Functional Requirements

## Response/Performance

## Recovery

## Delivery

## Maintainability

## Security

## Conclusion

## Glossary 

[^1]: GCC, short for GNU Compiler Collection, is a free and open-source compiler system produced by the GNU Project. It is used to compile source code from various programming languages, including C, C++, Objective-C, Fortran, Ada, and others. In simple terms, it translates the code written by developers into a format that can be understood and executed by a computer. <img src="https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8/blob/documents/Img/Gcc-Logo.png" alt="GCC Logo" width="75"/>

[^2]:  Visual Studio Code, often referred to as VS Code, is a free and open-source code editor developed by Microsoft. It supports a variety of programming languages and features, including syntax highlighting, intelligent code completion, snippets, code refactoring, and embedded Git. Users can also extend its functionality using extensions. It's designed to be lightweight yet powerful, and it can be used on Windows, macOS, and Linux operating systems. <img src="https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8/blob/documents/Img/Vs-Code-Logo.png" alt="VS Code Logo" width="75"/>

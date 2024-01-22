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

### <ins>Objectives</ins> 

### <ins>Scopes</ins> 

### <ins>Deliverables</ins>


### <ins>Personas definition</ins>

#### <ins>Persona 1 :</ins>

#### <ins>Persona 2 :</ins>

## <ins>4. Project organization</ins>

### <ins>Stake holders</ins>

### <ins>Project reviewers</ins>

# <ins>Project Plan</ins>

### <ins>Retro-planning</ins>

### <ins>Milesstones</ins>

### <ins>Resources / tools</ins>

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

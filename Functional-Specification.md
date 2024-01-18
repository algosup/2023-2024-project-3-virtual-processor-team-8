# Functional specification

## Table of content </summary>
  - [A) Introduction](#b-introduction)
    - [2) Project Overview](#2-project-overview)
    - [3) Project Definition](#3-project-definition)
      - [➭ Vision](#-vision)
      - [➭ Objectives](#-objectives)
      - [➭ Scope](#-scope)
      - [ Personas Definition](#2-personas-definition)
        - Persona 1
        - Persona 2
      - [➭ Deliverables](#-deliverables)
    - [4) Project Organization](#4-project-organisation)
      - [➭ Project Roles](#-project-roles)
      - [➭ Stakeholders](#-stakeholders)
      - [➭ Project Reviewers](#-project-reviewers)
    - [5) Project Plan](#5-project-plan)
      - [➭ Retroplanning](#-retroplanning)
      - [➭ Milestones](#-milestones)
      - [➭ Resources / tools](#-resources-tools)
      - [➭ Assumptions/Constraints](#-assumptions-constraints)
  - [B) Functional Requirements](#c-functional-requirements)
    - [Customers requirements (Obligatory)](#customers-requirements)
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
  - [D) Glossary](#glossary)
</details>

## 1. Introduction 
As for the overview of the project, the client (Algosup : Franck) has demanded us to create an emulator on which we will have to run an assembly ("[...].asm") file on it. The goal of the project is to create a virtual processor and an interpreter for running assembly code on that processor. The final product must be developed in plain, portable and coded in C language without the use of any external library beside C standard libraries. As for the complicator the client has recommended to use "gcc[^1]" and "Visual studio code[^2]" as IDE (integrated development environment).
As for the operating system the final product will run on MacOS and Windows, and the devices used to develop the product are :

    - Apple MacBook Air 2021, equipped with the "M1" chip running on "Ventura" MacOS version.

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
    

## Conclusion

## Glossary 

[^1]: GCC, short for GNU Compiler Collection, is a free and open-source compiler system produced by the GNU Project. It is used to compile source code from various programming languages, including C, C++, Objective-C, Fortran, Ada, and others. In simple terms, it translates the code written by developers into a format that can be understood and executed by a computer. 
[^1.1]: ![GCC Logo](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8/blob/documents/Img/Gcc-Logo.png)

[^2]:  Visual Studio Code, often referred to as VS Code, is a free and open-source code editor developed by Microsoft. It supports a variety of programming languages and features, including syntax highlighting, intelligent code completion, snippets, code refactoring, and embedded Git. Users can also extend its functionality using extensions. It's designed to be lightweight yet powerful, and it can be used on Windows, macOS, and Linux operating systems. <img src="https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8/blob/documents/Img/Vs-Code-Logo.png" alt="Vs-Code-logo.png" width="75px">


# Technical Specification

**Title:** Virtual Processor Project - Team 8

**Author:** Pierre GORIN

**Team:** Team 8

**Reviewer(s):** Laurent BOUQUIN, Evan UHRING

**Created on:** January 22<sup>nd</sup>, 2024

**Last updated:** January 22<sup>nd</sup>, 2024


### Table of Contents
- [Technical Specification](#technical-specification)
    - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [a. Overview](#a-overview)
    - [b. Glossary or Terminology](#b-glossary-or-terminology)
    - [c. Context](#c-context)
    - [d. Product and Technical Requirements](#d-product-and-technical-requirements)
    - [e. Out of Scope](#e-out-of-scope)
    - [f. Future Goals](#f-future-goals)
    - [g. Assumptions](#g-assumptions)
  - [Solutions](#solutions)
    - [a. Existing Solution](#a-existing-solution)
    - [b. Proposed Solution](#b-proposed-solution)
  - [Further Considerations](#further-considerations)
    - [a. Impact](#a-impact)
    - [b. Metrics](#b-metrics)
  - [Work](#work)
    - [a. Work Estimates and Timelines](#a-work-estimates-and-timelines)
    - [b. Prioritization](#b-prioritization)
    - [c. Milestones](#c-milestones)
    - [d. Future Work](#d-future-work)
  - [Deliberation](#deliberation)
    - [a. Discussion](#a-discussion)
    - [b. Open Questions](#b-open-questions)
  - [End Matter](#end-matter)
    - [a. Related Work](#a-related-work)
    - [b. References](#b-references)
    - [c. Acknowledgments](#c-acknowledgments)


## Introduction

### a. Overview
This project aims to develop a virtual processor and an interpreter for a custom assembly language, in response to the recent call for tender. Using only standard C libraries for wide compatibility, the primary goal is to design a minimal assembly language and build a C program interpreter capable of executing and error-checking assembly code. This solution is intended to serve educational purposes and software developers interested in low-level programming and processor emulation. The project combines technical innovation with practical application, focusing on creating a user-friendly and educational tool in the field of computer architecture.

### b. Glossary or Terminology
List of technical terms and their definitions.

<ins>Assembly Language:</ins> A low-level programming language for a computer or other programmable device, in which each statement corresponds to a single machine instruction.

<ins>Interpreter:</ins> A program that executes instructions written in a high-level language.

<ins>Virtual Processor:</ins> A software emulation of a computer processor.



### c. Context
**Problem Origin:** Reasons for addressing the problem, its impact on users and company goals, previous efforts, and their outcomes.
**Alignment with Goals:** How the solution aligns with team goals, OKRs, and overall product strategy.

### d. Product and Technical Requirements

**Assembly Language Design:** The processor must support a custom assembly language with basic instructions for arithmetic, logical operations, memory management, and control flow.

**C Program Interpreter:** Develop a C program capable of reading and interpreting assembly code written for the virtual processor. It should also validate the syntax and semantics of the code.

**Error Detection:** Implement robust error detection and reporting mechanisms within the interpreter.

**Virtual System Call:** A system call for displaying text in a virtual terminal should be included, accessible from the assembly code.

**Built-in Debugger:** Incorporate debugging tools to monitor execution and state of the processor.

**Portability and Compatibility:** Ensure the project is developed using standard C libraries for maximum portability and compatibility.

**Documentation:** Comprehensive documentation of the assembly language and interpreter usage.

**Unit Tests:** Develop unit tests mimicking real-world scenarios to ensure all functionalities are working as expected.

### e. Out of Scope
**Graphical User Interface (GUI):** Development of a GUI for the interpreter is not included.

**Hardware-specific optimizations:** The project will not focus on optimizations for specific hardware configurations.

**Advanced Assembly Features**: Complex assembly language features like threading or advanced memory management are not within the scope.

**Cross-language Support:** Integration with languages other than C for the interpreter is not planned.

**Real-time Execution Monitoring:** Tools for real-time performance analysis are not included.

### f. Future Goals
**Enhanced Assembly Language:** Future versions may include more complex instructions and features to expand the utility of the processor.

**GUI Development:** Developing a user-friendly GUI for easier interaction with the virtual processor.

**Cross-Platform Compatibility:** Enhancements for seamless operation across different operating systems.

**Performance Optimization:** Advanced performance optimization for specific use cases or hardware.

**Integration with Other Programming Languages:** Enabling the interpreter to work with other popular programming languages.

### g. Assumptions
**Environment:** The project assumes availability of a standard C development environment with GCC compiler.

**Standard C Libraries:** C standard libraries are assumed to not be used for the development of the interpreter.

**Stakeholder Engagement:** Continuous engagement and feedback from stakeholders throughout the development process.

**Technical Expertise:** The team assumes a foundational understanding of assembly language and processor architecture among its members.

**Testing and Validation:** Access to sufficient resources for thorough testing and validation of the software.



## Solutions

### a. Existing Solution
**Analysis:** Discussion of the current solution and its pros/cons.

### b. Proposed Solution
**Components:** Description of external components, dependencies, data models, business logic, presentation layer, and limitations.
**Test Plan:** How tests will ensure user requirements are met.
**Monitoring and Alerting Plan:** Tools and strategies for monitoring and alerting.
**Release / Roll-out and Deployment Plan:** Details of deployment, phased roll-out, and user communication.
**Rollback Plan:** Strategies for rollback and minimizing impact on other systems.
Alternate Solutions / Designs: Evaluation of alternative solutions with pros/cons.



## Further Considerations
Impact on Other Teams, Third-party Services, Cost Analysis, Security, Privacy, Regional, Accessibility, Operational Considerations, and Risks: Detailed analysis of these aspects.
Success Evaluation

### a. Impact
**Analysis:** Security, performance, cost, and impact on other components.

### b. Metrics
**Measurement:** Metrics and tools for evaluation.



## Work

### a. Work Estimates and Timelines
**Breakdown:** List of tasks with resources and timelines.

### b. Prioritization
**Urgency and Impact:** Categorization of tasks.

### c. Milestones
**Checkpoints:** Significant points in the project timeline.

### d. Future Work
**Roadmap:** Tasks planned for future implementation.



## Deliberation

### a. Discussion
**Debate Points:** Areas of disagreement or uncertainty.

### b. Open Questions
**Inquiries:** Questions seeking team input.



## End Matter

### a. Related Work
**External References:** Similar projects or initiatives by other teams.

### b. References
**Sources:** Links to documents and resources used.

### c. Acknowledgments
**Contributions:** Recognition of key contributors.










<!-- 
DONE:
Overview
Product and Technical Requirements
Out of Scope
Future Goals
Assumptions

IN PROGRESS:
Glossary
Table of Contents

TODO:
Context
Existing Solution
Proposed Solution
Impact
Metrics
Work Estimates and Timelines
Prioritization
Milestones
Future Work
Discussion
Open Questions
Related Work
References
Acknowledgments

 -->
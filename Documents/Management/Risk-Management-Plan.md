# Risk Management Plan

## Introduction

The risk management[^1] plan for the Virtual Processor project outlines the approach, processes, and strategies to identify, assess, mitigate, and monitor potential risks that may impact the successful execution of the project. Proactive risk management is essential to ensure that the project team can anticipate and address challenges effectively, minimizing disruptions and maximizing the likelihood of project success.

## Context

### Project Overview

The Virtual Processor project project aims to develop a virtual processor and interpreter, enabling the execution of assembly code written in a custom assembly language. The project's key objectives include creating a robust and efficient virtual processing environment with specific functionalities such as arithmetic operations, logical operations, and system calls for text display.

### Project Timeline and Deliverables

The project is scheduled to be completed by February 23, 2024 at 5 PM, with the following key deliverables, leading to the final product delivery:

- **30/01/24, 5pm:** Functional specification deadline.
- **09/02/24, 5pm:** Technical specification deadline.
- **16/02/24, 5pm:** Test plan deadline.
- **23/02/24, 5pm:** Final product deadline.

### Key Contacts

- **Project Manager:** Laura-Lee Hollande
- **Customer:** ALGOSUP, Franck JEANNIN
- **Team Members:**
  - Program Manager - Ian LAURENT
  - Technical Lead - Pierre GORIN
  - Software Engineer - Victor LEROY & Manech LAGUENS
  - Quality Assurance - Evan UHRING & Laurent BOUQUIN

### Project Risks Importance

Given the complexity of the project and the importance of meeting specific milestones, it is crucial to identify potential risks early on and establish effective risk mitigation and contingency plans. This risk management plan serves as a guiding document to systematically address and manage risks throughout the project lifecycle.

## Risk Identifications

- Technical risks
  - Communications failure
  - Save failure
  - Technical skill gaps
  - Software dependencies
  - Insufficient testing coverage
  - Inadequate documentation
  - Technology obsolescence

- Project management risks
  - Scope Creep
  - Resource constraints
  - timeline delays
  - Personal issue leading to team departures
  - Lack of stakeholder involvement

## Assessing Potential Risk

### Likelihood

| Level | Meaning        | Description                                  |
| ----- | -------------- | -------------------------------------------- |
| A     | Almost certain | Expected to occur in most circumstances.     |
| B     | Likely         | Will probably occur in most circumstances.   |
| C     | Moderate       | Should occur at some time.                   |
| D     | Unlikely       | Could occur at some time.                    |
| E     | Rare           | May occur only in exceptional circumstances. |
| F     | Never          | It is not foreseeable that this will occur.  |

### Impact

| Level | Meaning       | Description                                                                                                                                                                | Example                                                                                                                                                           |
| ----- | ------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1     | Insignificant | The impact is negligible and has minimal consequences.                                                                                                                     | A minor software glitch.                                                                                                                                          |
| 2     | Minor         | The impact is noticeable but does not pose a serious threat to the project.                                                                                                | A temporary setback in development caused by a brief team member unavailability.                                                                                                          |
| 3     | Moderate      | The impact is of moderate severity and may pose a potential threat to the project's success.                                                                               | Key team member unexpectedly leaving the project.                                                                                                                 |
| 4     | Major         | The impact is substantial and poses a severe threat to the project. It has the potential to significantly hinder or even jeopardize the achievement of project objectives. | A major security breach that compromises sensitive project information.                                                                                           |
| 5     | Catastrophic  | The impact is of the highest severity, representing a catastrophic event that poses an existential threat to the project.                                                  | A critical and irreparable flaw is discovered in the core architecture, rendering the virtual processor and interpreter unusable and requiring a complete redevelopment from scratch |

### Likelihood - Impact Matrice

| Likelihood | Impact |     |     |     |     |
| ---------- | ------ | --- | --- | --- | --- |
|            | 1      | 2   | 3   | 4   | 5   |
| A          | S      | S   | H   | H   | H   |
| B          | M      | S   | S   | H   | H   |
| C          | L      | M   | S   | H   | H   |
| D          | L      | L   | M   | S   | H   |
| E          | L      | L   | M   | S   | S   |

<details>

<summary>💡Keys</summary>

**H:** High risk, detailed research and management planning required at senior levels.

**S:** Significant risk, senior management attention needed.

**M:** Moderate risk, management responsibility must be specified.

**L:** Low risk, manage by routine procedures.

</details>

### Risk Register

| Category                 | Risk                                                                                                                                     | Consequence                                                                                                 | Existing Controls                                                      | Impact Rating | Likelihood Rating | Level of Risk | Risk Priority |
| ------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------- | ------------- | ----------------- | ------------- | ------------- |
| Technical risks          | Technical skill gaps, insufficient expertise within the team for developing certain aspects of the virtual processor                     | Project delays, suboptimal code quality                                                                     | Training programs, collaboration with external experts                 | 3             | D                 | M             | 5             |
| Project management risks | Scope creep, expansion of project scope beyond the defined boundaries                                                                    | Increased workload, timeline delays                                                                         | Clearly defined project scope, regular scope reviews                   | 3             | C                 | S             | 3             |
| Project management risks | Resource constraints, limited availability of key resources, such as personnel or tools                                                  | Delayed tasks, bottlenecks                                                                                  | Resource allocation monitoring, contingency planning                   | 2             | E                 | L             | 10            |
| Technical risks          | Communications failure, breakdowns in communication channels                                                                             | Misalignment, delayed decision-making                                                                       | Redundant communication systems, regular testing, in real life meeting | 3             | D                 | M             | 6             |
| Technical risks          | Save failure, partial or complete loss of all the documentation and/or code                                                              | Project setbacks, project delays, increased workload                                                        | Github, regular push, push historic                                    | /             | F                 | /             | 11            |
| Project management risks | Personal issue leading to team departures, team members leaving the project due to personal problems                                     | Loss of expertise, project setbacks, increased workload                                                     | Monitoring team well-being, offering support                           | 2             | D                 | L             | 9             |
| Technical risks          | Software dependencies, dependencies on external software libraries or tools                                                              | Project delays, potential rework                                                                            | Not permitted in this project to use any libraries or dependecies      | /             | F                 | /             | 12            |
| Project management risks | Lack of stakeholder involvement, insufficient engagement or feedback from key stakeholders                                               | Misaligned project goals, potential scope changes                                                           | Regular stakeholder meetings                                           | 3             | D                 | M             | 7             |
| Technical risks          | Insufficient testing coverage, inadequate testing of the virtual processor                                                               | Increased post-release issues, potential user dissatisfaction                                               | Comprehensive testing plan, thorough testing at each stage             | 4             | C                 | H             | 2             |
| Technical risks          | Inadequate documentation, poorly documented code, architecture, or processes                                                             | Increased maintenance efforts, potential errors                                                             | Enforced documentation standards, regular reviews                      | 3             | C                 | S             | 4             |
| Technical risks          | Technology obsolescence, rapid advancements in technology making the chosen technology stack or architecture obsolete during development | Project delays, potential rework                                                                            | Regular evaluation and updates of the technology stack                 | 2             | D                 | L             | 8             |
| Technical risks          | Compatibility between Mac and Windows,                                                                                                   | Compatibility issues between operating systems, potential rework, suboptimal code quality, potential errors | Testing on both Mac and Windows                                        | 4             | A                 | H             | 1             |

💡 ```The likelihood and impact levels are subjective and should be assessed based on the specific context and details of your project.```

## Evaluating and Treating Potential Risks

### Risk Treatment Schedule and Plan

| Risk ID | Risk                                      | Risk Mitigation                                      | Risk Rating BEFORE Treatment | Risk Rating AFTER Treatment | Responsible                                                | Planning        | Success Criteria                                                                                                                                                                                                                                                         |
| ------- | ----------------------------------------- | ---------------------------------------------------- | ---------------------------- | --------------------------- | ---------------------------------------------------------- | --------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| #1      | Compatibility between Mac and Windows     | Thorough testing on Mac and Windows                  | 4 + A = H                    | 3 + C = S                   | Laurent Bouquin, Evan Uhring, Manech Laguens, Victor Leroy | Immediate       | - Compatibility issues between Mac and Windows are identified and resolved <br> - Positive feedback from beta testers on the seamless functionality across different operating systems                                                                                   |
| #2      | Insufficient testing coverage             | Conduct test coverage analysis regularly             | 4 + C = H                    | 4 + D = S                   | Laurent Bouquin, Evan Uhring                               | Immediate       | - Achieve at least 95% test coverage <br> - Significant reduction in post-release issues  <br> - Positive feedback from the QA team on the effectiveness of automated testing tools  <br> - Positive feedback from beta tester on the final product                      |
| #3      | Scope creep                               | Provide clear documentation for project scope        | 3 + C + S                    | 1 + B = M                   | Laura-Lee Hollande                                         | Immediate       | - No unauthorized changes to the project scope  <br>  - Changes to the scope are documented and approved by the change control board <br>  - Minimal impact on project timelines and resources due to scope changes                                                      |
| #4      | Inadequate documentation                  | Conduct regular documentation audits                 | 3 + C + S                    | 2 + D = L                   | Pierre Gorin, Manech Laguens, Victor Leroy                 | Immediate       | - All project documentation follows established templates for consistency  <br> - Regular documentation audits show compliance with documentation standards  <br> - Positive feedback from project stakeholders on the clarity and completeness of project documentation |
| #5      | Technical skill gaps                      | Encourage pair programming                           | 3 + D = M                    | 1 + C = L                   | Pierre Gorin                                               | Ongoing         | - Team members exhibit improved proficiency in cross-trained skills  <br> - Positive feedback from team members on the effectiveness of cross-training and pair programming sessions                                                                                     |
| #6       | Communications failure                    | Conduct regular team-building activities             | 3 + D = M                    | 2 + E = L                   | Laura-Lee Hollande                                         | Immediate       | - Established communication protocols and guidelines are consistently followed  <br> - Team-building activities contribute to improved team communication and collaboration                                                                                              |
| #7      | Lack of stakeholder involvement           | Conduct regular meeting                              | 3 + D = M                    | 2 + D = L                   | Ian Laurent, Laura-Lee Hollande                            | Start if needed | - Efficient feedback collection mechanism results in timely and valuable input from stakeholders  <br> - Stakeholder satisfaction with project progress and outcomes increases                                                                                           |
| #8      | Technology obsolescence                   | Implement continuous monitoring of technology trends | 2 + D = L                    | 1 + D = L                   | Pierre Gorin                                               | Ongoing         | - Continuous monitoring ensures early identification of technology trends  <br> -Minimal impact on the project due to unexpected technology shifts                                                                                                                       |
| #9      | Personal issue leading to team departures | Provide flexible work arrangements for team members  | 2 + D = L                    | 1 + E = L                   | Laura-Lee Hollande                                         | Start if needed | - Flexible work arrangements contribute to improved the productivity for team members                                                                                                                                                                                    |
| #10      | Resource constraints                      | Cross-train team members for resource flexibility    | 2 + E = L                    | 1 + E = L                   | Laura-Lee Hollande, Pierre Gorin                           | Ongoing         | - Cross-training efforts result in increased resource flexibility  <br> - Resource allocation plan adjustments lead to optimized resource utilization  <br> - Minimal disruptions due to resource shortages, as identified in regular resource reviews                   |

## Risk Action Plan

For risks that are **High, Extreme or deemed to be unacceptable**, an evaluated and specific action plans is required to manage the risk appropriately.

| Risk ID                                 | 1                                                                                                                                                                                                                                   |
| --------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Risk                                    | Compatibility between Mac and Windows                                                                                                                                                                                               |
| Summary (recommended response & impact) | To mitigate the risk of compatibility issues between Mac and Windows, the team will focus on conducting thorough testing across different operating systems, ensuring a seamless user experience on both Mac and Windows platforms. |
| Proposed Action                         | Thorough testing on Mac and Windows                                                                                                                                                                                                 |
| Resource Requirements                   | /                                                                                                                                                                                                                                   |
| Responsibilities                        | QA team to perform thorough compatibility testing across Mac and Windows environments                                                                                                                                               |
| Timing                                  | Thorough compatibility testing to be conducted before each major release                                                                                                                                                            |
| Reporting/Monitoring                    | - Regularly review testing reports for any compatibility issues </br> - Document and address any compatibility issues identified during testing </br> - Monitor user feedback for any reported compatibility concerns               |

| Risk ID                                 | 2                                                                                                                                                                                                                                  |
| --------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Risk                                    | Insufficient Testing Coverage                                                                                                                                                                                                      |
| Summary (recommended response & impact) | To address the risk of insufficient testing coverage, the team will implement automated testing tools, conduct regular test coverage analysis, and ensure that testing is thorough, reducing the likelihood of post-release issues |
| Proposed Action                         | Implement automated testing tools                                                                                                                                                                                                  |
| Resource Requirements                   | - Time for team members to research and implement automated testing tools </br> - Tools for test coverage analysis                                                                                                                 |
| Responsibilities                        | - Development team to research and implement automated testing tools </br> - QA team to conduct regular test coverage analysis                                                                                                     |
| Timing                                  | - Automated testing tools to be implemented within the next development sprint </br> - Test coverage analysis to be conducted at the end of each development cycle                                                                 |
| Reporting/Monitoring                    | - Regularly review automated testing reports and metrics </br> - Periodically assess test coverage reports and identify areas for improvement                                                                                      |

| Risk ID                                 | 3                                                                                                                                                                                                                                                            |
| --------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Risk                                    | Scope Creep                                                                                                                                                                                                                                                  |
| Summary (recommended response & impact) | To manage the risk of scope creep, a dedicated change control board will be established, and clear documentation for the project scope will be provided to all stakeholders. This aims to minimize unauthorized changes and ensure proper control over scope |
| Proposed Actions                        | Provide clear documentation for project scope                                                                                                                                                                                                                |
| Resource Requirements                   | - Time for team members to participate in change control board activities </br> - Resources for documenting and communicating project scope                                                                                                                  |
| Responsibilities                        | - Project Manager to lead the change control board </br> - Project team to follow the change control process and document scope changes </br> - Stakeholders to refer to the project scope documentation                                                     |
| Timing                                  | - Change control board to be established before the project kick-off </br> - Project scope documentation to be provided during project initiation                                                                                                            |
| Reporting/Monitoring                    | - Monitor the change control board activities and adherence to the established process </br> - Regularly review project scope documentation and update as necessary                                                                                          |

| Risk ID                                 | 4                                                                                                                                                                                                         |
| --------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Risk                                    | Inadequate Documentation                                                                                                                                                                                  |
| Summary (recommended response & impact) | To mitigate the risk of inadequate documentation, the team will implement the use of documentation templates for consistency and conduct regular documentation audits to ensure compliance with standards |
| Proposed Actions                        | Conduct regular documentation audits                                                                                                                                                                      |
| Resource Requirements                   | - Time for team members to familiarize themselves with documentation templates </br> - Resources for conducting regular documentation audits                                                              |
| Responsibilities                        | - Documentation Lead to enforce the use of templates and conduct regular audits <br> - Project team members to follow the documentation standards and contribute to audits                                |
| Timing                                  | - Documentation templates to be introduced at the start of the project </br> - Regular documentation audits to be conducted at the end of each development cycle                                          |
| Reporting/Monitoring                    | - Periodically assess compliance with documentation standards through audits </br> - Gather feedback from team members on the effectiveness of documentation templates                                    |

---

[^1]: It is the process of identifying, assessing and controlling threats to an organization's capital, earnings and operations. These risks stem from a variety of sources, including financial uncertainties, legal liabilities, technology issues, strategic management errors, accidents and natural disasters.
*source : [TechTarget](https://www.techtarget.com/searchsecurity/definition/What-is-risk-management-and-why-is-it-important)*

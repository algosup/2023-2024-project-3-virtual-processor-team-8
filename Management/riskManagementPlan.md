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
  - Inadequate site management
<!-- - **Likelihood:** Low
- **Impact:** Moderate
- **Mitigation:** Ensure a well-experienced technical team for virtual processor development. Regular training and briefings. -->
  - Communications failure
<!-- - **Likelihood:** Medium
- **Impact:** Moderate
- **Mitigation:** Implement redundant communication systems for development coordination. Regular testing of communication tools. -->
  - Save failure
<!-- - **Likelihood:** Medium
- **Impact:** High
- **Mitigation:** Establish backups and regularly push on Github. -->
  - Technical skill gaps
<!-- - **Likelihood:** Medium
- **Impact:** High
- **Mitigation:** Assess and address skill gaps within the development team. Provide necessary training or bring in external help. -->

- Project management risks
  - Scope Creep
<!-- - **Likelihood:** Medium
- **Impact:** High
- **Mitigation:** Clearly define and document project scope. Regularly review and confirm scope with stakeholders. -->
  - Resource constraints
<!-- - **Likelihood:** Medium
- **Impact:** High
- **Mitigation:** Monitor resource allocation closely. Adjust project plan if resource constraints are identified. -->

  - timeline delays
<!-- - **Likelihood:** Medium
- **Impact:** High
- **Mitigation:** Regularly review and adjust project timeline as needed. Identify and address potential delays promptly. -->

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

💡 ```The likelihood and impact levels are subjective and should be assessed based on the specific context and details of your project.```

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

| Category                 | Risk                                                                                                                                     | Consequence                                                   | Existing Controls                                                      | Impact Rating | Likelihood Rating | Level of Risk | Risk Priority |
| ------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------- | ---------------------------------------------------------------------- | ------------- | ----------------- | ------------- | ------------- |
| Technical risks          | Technical skill gaps, insufficient expertise within the team for developing certain aspects of the virtual processor                     | Project delays, suboptimal code quality                       | Training programs, collaboration with external experts                 | 3             | D                 | M             | 5             |
| Project management risks | Scope creep, expansion of project scope beyond the defined boundaries                                                                    | Increased workload, timeline delays                           | Clearly defined project scope, regular scope reviews                   | 3             | C                 | S             | 2             |
| Project management risks | Resource constraints, limited availability of key resources, such as personnel or tools                                                  | Delayed tasks, bottlenecks                                    | Resource allocation monitoring, contingency planning                   | 2             | E                 | L             | 10            |
| Technical risks          | Inadequate site management, issues with the technical oversight of the virtual processor development                                     | Reduced development efficiency, quality issues                | Experienced technical team, regular training and briefings.            | 3             | C                 | S             | 4             |
| Technical risks          | Communications failure, breakdowns in communication channels                                                                             | Misalignment, delayed decision-making                         | Redundant communication systems, regular testing, in real life meeting | 3             | D                 | M             | 6             |
| Technical risks          | Save failure, partial or complete loss of all the documentation and/or code                                                              | Project setbacks, project delays, increased workload          | Github, regular push, push historic                                    | /             | F                 | /             | 11            |
| Project management risks | Personal issue leading to team departures, team members leaving the project due to personal problems                                     | Loss of expertise, project setbacks, increased workload       | Monitoring team well-being, offering support                           | 2             | D                 | L             | 9             |
| Technical risks          | Software dependencies, dependencies on external software libraries or tools                                                              | Project delays, potential rework                              | Not permitted in this project to use any libraries or dependecies      | /             | F                 | /             | 12            |
| Project management risks | Lack of stakeholder involvement, insufficient engagement or feedback from key stakeholders                                               | Misaligned project goals, potential scope changes             | Regular stakeholder meetings                                           | 3             | D                 | M             | 7             |
| Technical risks          | Insufficient testing coverage, inadequate testing of the virtual processor                                                               | Increased post-release issues, potential user dissatisfaction | Comprehensive testing plan, thorough testing at each stage             | 4             | C                 | H             | 1             |
| Technical risks          | Inadequate documentation, poorly documented code, architecture, or processes                                                             | Increased maintenance efforts, potential errors               | Enforced documentation standards, regular reviews                      | 3             | C                 | S             | 3             |
| Technical risks          | Technology obsolescence, rapid advancements in technology making the chosen technology stack or architecture obsolete during development | Project delays, potential rework                              | Regular evaluation and updates of the technology stack                 | 2             | D                 | L             | 8             |

## Evaluating and Treating Potential Risks

### Risk Treatment Schedule and Plan

| Risk ID | Risk                                      | Possible Treatment Option                                                                                                                                   | Preferred Options | Risk Rating BEFORE Treatment | Risk Rating AFTER Treatment | Responsible                                | Planning | How will it be monitored? |
| ------- | ----------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- | ---------------------------- | --------------------------- | ------------------------------------------ | -------- | ------------------------- |
| #1      | Insufficient testing coverage             | 1) Implement automated testing tools <br> 2) Conduct test coverage analysis regularly                                                                       | 2)                | 4 + C = H                    | 4 + D = S                   | Laurent Bouquin, Evan Uhring               |          |                           |
| #2      | Scope creep                               | 1) Establish a dedicated change control board <br> 2) Provide clear documentation for project scope                                                         | 1)                | 3 + C + S                    | 1 + B = M                   | Laura-Lee Hollande                         |          |                           |
| #3      | Inadequate documentation                  | 1) Use documentation templates for consistency <br> 2) Conduct regular documentation audits                                                                 | 2)                | 3 + C + S                    | 2 + D = L                   | Pierre Gorin, Manech Laguens, Victor Leroy |          |                           |
| #4      | Inadequate site management                | 1) Provide ongoing training for site management tools <br> 2) Implement a mentorship program for site managers                                              | 1)                | 3 + C + S                    | 1 + B = M                   | Pierre Gorin, Laura-Lee Hollande           |          |                           |
| #5      | Technical skill gaps                      | 1) Implement cross-training sessions among team members <br> 2) Encourage team members to pursue relevant certifications <br> 3) Encourage pair programming | 3)                | 3 + D = M                    | 1 + C = L                   | Pierre Gorin                               |          |                           |
| #6      | Communications failure                    | 1) Establish communication protocols and guidelines <br> 2) Conduct regular team-building activities                                                        | 2)                | 3 + D = M                    | 2 + E = L                   | Laura-Lee Hollande                         |          |                           |
| #7      | Lack of stakeholder involvement           | 1) Conduct stakeholder engagement workshops <br> 2) Implement an efficient feedback collection mechanism <br> 3) Conduct regular meeting                    | 3)                | 3 + D = M                    | 2 + D = L                   | Ian Laurent, Laura-Lee Hollande            |          |                           |
| #8      | Technology obsolescence                   | 1) Implement continuous monitoring of technology trends <br> 2) Establish partnerships with technology providers for updates                                | 1)                | 2 + D = L                    | 1 + D = L                   | Pierre Gorin                               |          |                           |
| #9      | Personal issue leading to team departures | 1) Provide flexible work arrangements for team members <br> 2) Implement an employee assistance program                                                     | 1)                | 2 + D = L                    | 1 + E = L                   | Laura-Lee Hollande                         |          |                           |
| #10     | Resource constraints                      | 1) Cross-train team members for resource flexibility                                                                                                        | 1)                | 2 + E = L                    | 1 + E = L                   | Laura-Lee Hollande, Pierre Gorin           |          |                           |

---

[^1]: It is the process of identifying, assessing and controlling threats to an organization's capital, earnings and operations. These risks stem from a variety of sources, including financial uncertainties, legal liabilities, technology issues, strategic management errors, accidents and natural disasters.
*source : [TechTarget](https://www.techtarget.com/searchsecurity/definition/What-is-risk-management-and-why-is-it-important)*

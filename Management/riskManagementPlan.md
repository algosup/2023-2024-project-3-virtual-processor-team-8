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

- Health
  - Disease outbreak  
<!-- - **Likelihood:** Low
- **Impact:** High
- **Mitigation:** Implement teleworking. Adjust the management plan. -->

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

---

[^1]: It is the process of identifying, assessing and controlling threats to an organization's capital, earnings and operations. These risks stem from a variety of sources, including financial uncertainties, legal liabilities, technology issues, strategic management errors, accidents and natural disasters.
*source : [TechTarget](https://www.techtarget.com/searchsecurity/definition/What-is-risk-management-and-why-is-it-important)*

# Weekly Report - 01/22/2023 - 01/28/2024

## Project Overview

- **Project Name:** Virtual Processor
- **Project Manager:** Laura-Lee Hollande
- **Project time (hours):** 26h00

### Project summary

Successfully redesigned and reorganized Trello boards for enhanced project management and collaboration.

Developed a comprehensive risk management[^1] plan, integrating both the risk register and mitigation strategies.

Implemented risk tracking in the project management tool and Trello boards for efficient monitoring.

Conducted a thorough review of the functional specification, ensuring alignment with project goals and requirements.

Started the technical specification phase, outlining the detailed technical aspects of the virtual processor project.

Initiated discussions with the customer regarding potential modifications to the assembly language instructions and the inclusion of sections like .data and interrupts.

- **Questionning the customer:**

  - **Questions:** Do we have to completely change the name of the different instructions or can we keep them as they actually are, and maybe just change some of them & Do we have to do the section parts (i.e section .data) and the interrupts?
  - **Answer:** Create our dreamed assembly language.

Explored the possibility of creating a customized assembly language that aligns with project goals.

Continue the curation about the project.

Deals with teammembers absence, we have planned a meeting on the next week.

We encounter a compatibility problem between Mac and Windows, not solved for the moment.

## Project Key parameters

<details>

<summary>💡 Keys</summary>

1. **Scope:**
   - **On:** The project is proceeding within the defined scope without significant deviations.
   - **At Risk:** There are potential scope creep issues or uncertainties that may impact the project's boundaries.
   - **Halted:** The project has temporarily stopped due to scope-related challenges or changes.
  
2. **Schedule:**
   - **On:** The project is progressing according to the planned schedule.
   - **At Risk:** There are concerns about meeting the scheduled deadlines or milestones.
   - **Halted:** The project schedule has come to a temporary stop, possibly due to external factors or critical issues.

3. **Risks[^2]:**
   - **On:** The identified risks are being effectively managed, and mitigation strategies are in place.
   - **At Risk:** New risks have emerged, or existing risks are not being adequately addressed.
   - **Halted:** The project has stopped or is on hold due to high-risk factors that need resolution.

4. **Issues[^3]:**
   - **On:** Issues are being promptly addressed, and resolution is progressing well.
   - **At Risk:** There are issues that pose a threat to the project's progress and need attention.
   - **Halted:** The project has come to a stop due to critical unresolved issues.

5. **Quality:**
   - **On:** The project is meeting or exceeding quality standards.
   - **At Risk:** There are concerns about the quality of deliverables or processes.
   - **Halted:** The project has temporarily halted due to severe quality issues that need resolution.

</details>

| Component | Status  | Comments                                                         |
| --------- | ------- | ---------------------------------------------------------------- |
| Scope     | On      | All OK                                                           |
| Schedule  | At risk | Potential delay due to the compatibility issue                   |
| Risks     | At risk | A new risk have emerged, uncompatibility between Mac and Windows |
| Issues    | At risk | Compatibility issue between Mac and Windows                      |
| Quality   | On      | All OK                                                           |

## Project Risks and Issues (Top 5)

| Risk/Issues | Description                                                                 | Owner                         | Status   |
| ----------- | --------------------------------------------------------------------------- | ----------------------------- | -------- |
| Issue 1     | Compatibility problem between Mac and Window with the strcpy()[^4] function | Laurent Bouquin, Victor Leroy | On going |
| Issue 2     | Bug with Trello, loose everything                                           | Laura-Lee Hollande            | Closed   |
| Risk 1      | Potential loss of some teammates                                            | Laura-Lee Hollande            | pending  |

## Project Schedule

This schedule refers to the [Gantt Chart](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8/blob/management/Management/TeamManagement/ganttCharter.pdf) of this project.

![Week 3](img/week3.png)

⚠️ ```The current week is highlighted in red and the weeks are based on the real time weeks number.```

## Key Performance Indicator[^5]

<details>

<summary>💡 Keys</summary>

1. **Documentation KPIs:**
   - **0%:** Nothing.
   - **10%:** Started.
   - **70%:** Written.
   - **100%:** Validated by the group.

2. **Testing KPIs:**
   - **Test case**: Number of test that passed.

3. **Code KPIs:**
   - **Implemented:** Has been coded, pushed in the ```dev branch```, tested and merged in the main branch with no conflict.

</details>

![KPIs Week 3](img/kpi3.png)

## Next week Action Plan

| Action                                 | Note                                                                      | Owner                                      | Status  | End Date   |
| -------------------------------------- | ------------------------------------------------------------------------- | ------------------------------------------ | ------- | ---------- |
| Team meeting                           | Share what was done the previous week and the goals for the upcoming week | Laura-Lee Hollande, Ian Laurent            | Planned | 01/29/2024 |
| Conclude the functional specifications |                                                                           | Ian Laurent                                | Doing   | 01/30/2024 |
| Assembly language documentation        |                                                                           | Pierre Gorin, Laurent Bouquin, Ian Laurent | Doing   | 01/30/2024 |
| Continue the technical specifications  |                                                                           | Pierre Gorin                               | Doing   | 02/09/24   |

---

[^1]: It is the process of identifying, assessing and controlling threats to an organization's capital, earnings and operations. These risks stem from a variety of sources, including financial uncertainties, legal liabilities, technology issues, strategic management errors, accidents and natural disasters.
*source : [TechTarget](https://www.techtarget.com/searchsecurity/definition/What-is-risk-management-and-why-is-it-important)*
[^2]: Risk is any unexpected event that can affect your project — for better or for worse. Risk can affect anything: people, processes, technology, and resources. [...] Risks are events that might happen, and you may not be able to tell when.
*source : [Wrike](https://www.wrike.com/project-management-guide/faq/what-is-risk-in-project-management/)*
[^3]: Issues are things you know you’ll have to deal with, and may even have an idea of when they’ll occur.
*source : [Wrike](https://www.wrike.com/project-management-guide/faq/what-is-risk-in-project-management/)*
[^4]: It is a C standard library function that copies a string from one location to another.
*source : [Geeks for Geeks](https://www.geeksforgeeks.org/strcpy-in-c/)*
[^5]: A quantifiable measure of performance over time for a specific objective. KPIs provide targets for teams to shoot for, milestones to gauge progress, and insights that help people across the organization make better decisions.
*source : [Qlik](https://www.qlik.com/us/kpi#:~:text=KPI%20stands%20for%20key%20performance,the%20organization%20make%20better%20decisions.)*

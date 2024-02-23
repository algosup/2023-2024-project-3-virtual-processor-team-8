# Weekly Report - 01/29/2023 - 02/04/2024

## Project Overview

- **Project Name:** Virtual Processor
- **Project Manager:** Laura-Lee Hollande
- **Project time (hours):** 19h30

### Project summary

The team held its regular meeting to discuss ongoing tasks, challenges, and project updates.

The previously identified compatibility issues between Mac and Windows related to `strcpy` have been successfully closed. The team implemented a solution by changing `strcpy` to `sprintf` for improved compatibility.

The deadline for the functional specification and assembly documentation are over. The team succeeded to deliver the [functional specification](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8/blob/main/Documents/Functional-Specification.md) on time.

The review of the technical specification is currently in progress. The team is thoroughly examining the document to ensure accuracy, completeness, and alignment with project objectives.

The development of the parser code has commenced. The team is working on the implementation, considering the requirements outlined in the technical specification.

Initial testing of the parser functionality has begun. The team is conducting tests to identify and address any potential issues early in the development process.

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

3. **Risks[^1]:**
   - **On:** The identified risks are being effectively managed, and mitigation strategies are in place.
   - **At Risk:** New risks have emerged, or existing risks are not being adequately addressed.
   - **Halted:** The project has stopped or is on hold due to high-risk factors that need resolution.

4. **Issues[^2]:**
   - **On:** Issues are being promptly addressed, and resolution is progressing well.
   - **At Risk:** There are issues that pose a threat to the project's progress and need attention.
   - **Halted:** The project has come to a stop due to critical unresolved issues.

5. **Quality:**
   - **On:** The project is meeting or exceeding quality standards.
   - **At Risk:** There are concerns about the quality of deliverables or processes.
   - **Halted:** The project has temporarily halted due to severe quality issues that need resolution.

</details>

| Component | Status | Comments                                     |
| --------- | ------ | -------------------------------------------- |
| Scope     | On     | All Ok                                       |
| Schedule  | On     | All Ok                                       |
| Risks     | On     | Teammates abscence                           |
| Issues    | On     | The issue has been solved, we are testing it |
| Quality   | On     | All Ok                                       |

## Project Risks and Issues (Top 5)

| Risk/Issues | Description                                                                 | Owner                         | Status   |
| ----------- | --------------------------------------------------------------------------- | ----------------------------- | -------- |
| Issue 1     | Compatibility problem between Mac and Window with the strcpy()[^4] function | Laurent Bouquin, Victor Leroy | Closed   |
| Issue 2     | Teammates absence                                                           | Laura-Lee Hollande            | On going |
| Risk 1      | Potential loss of some teammates                                            | Laura-Lee Hollande            | Closed   |

## Project Schedule

This schedule refers to the [Gantt Chart](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-8/blob/management/Management/TeamManagement/ganttCharter.pdf) of this project.

![Week 4](img/week4.png)

⚠️  ```The current week is highlighted in red and the weeks are based on the real time weeks number.```

## Key Performance Indicator[^3]

<details>

<summary>💡 Keys</summary>

1. **Documentation KPIs:**
   - **0%:** Nothing done.
   - **10%:** Started.
   - **70%:** Written or set up.
   - **100%:** Validated by the group.

2. **Testing KPIs:**
   - **Test case:** Number of test that passed.
   - **No review:** No review was initiated.
   - **Review:** The documentation has been reviewved.
   - **Review and fix:** The documentation has been reviewved and all the GitHub Issues[^3] are closed.

3. **Language KPIs:**
   - **0%:** Nothing done.
   - **10%:** Started.
   - **70%:** Difined.
   - **100%:** Validated by the group.

4. **Parser & Interpreter KPIs:**
   - **Not started:** We have not started working on the feature.
   - **On going:** We have started working on the feature.
   - **Pushed:** The feature is done and push in the ```dev branch```, ready to be tested.
   - **Pushed and tested:** The feature is tested, ready to be merged.
   - **Implemented:** The feature has been coded, pushed in the ```dev branch```, tested and merged in the main branch with no conflict.
   - **Instrustions:** Number of instructions that worked and was tested.

</details>

This KPIs refers to the [cumulative KPIs](https://docs.google.com/spreadsheets/d/1_-OPSj577hdU58cxgzBR1Y8urz92UQi0AUktgfbjqTI/edit?usp=sharing) of this project.

![KPIs Week 4](img/kpi4.png)

## Next week Action Plan

| Action                               | Note                                                                      | Owner                            | Status   | End Date   |
| ------------------------------------ | ------------------------------------------------------------------------- | -------------------------------- | -------- | ---------- |
| Team meeting                         | Share what was done the previous week and the goals for the upcoming week | Laura-Lee Hollande, Ian Laurent  | Planned  | 02/05/2024 |
| Conclude the technical specification | Set time for the review and to fix the issues (if needed)                 | Pierre Gorin                     | On going | 02/09/2024 |
| Pair programming session             | Initiate duo to work on the code                                          | Pierre Gorin, Laura-Lee Hollande | To do    | 02/09/2024 |

<!-- Week 3, add problem solving -->

---

[^1]: Risk is any unexpected event that can affect your project — for better or for worse. Risk can affect anything: people, processes, technology, and resources. [...] Risks are events that might happen, and you may not be able to tell when.
*source : [Wrike](https://www.wrike.com/project-management-guide/faq/what-is-risk-in-project-management/)*
[^2]: Issues are things you know you’ll have to deal with, and may even have an idea of when they’ll occur.
*source : [Wrike](https://www.wrike.com/project-management-guide/faq/what-is-risk-in-project-management/)*
[^3]: A quantifiable measure of performance over time for a specific objective. KPIs provide targets for teams to shoot for, milestones to gauge progress, and insights that help people across the organization make better decisions.
*source : [Qlik](https://www.qlik.com/us/kpi#:~:text=KPI%20stands%20for%20key%20performance,the%20organization%20make%20better%20decisions.)*
[^4]: GitHub issue is a tool to track ideas, feedback, tasks, or bugs for work on GitHub.
*source : [Github](https://docs.github.com/en/issues/tracking-your-work-with-issues/about-issues)*

# Project Philosophers

## Introduction

In this project, you will dive into the fascinating world of dining philosophers. Imagine a scenario where one or more philosophers sit at a round table with a large bowl of spaghetti placed in the middle. These philosophers have a unique set of rules governing their actions:

- The philosophers take turns either eating, thinking, or sleeping.
- While a philosopher is eating, they cannot think or sleep.
- While thinking, they cannot eat or sleep.
- And, naturally, while sleeping, they cannot eat or think.

To facilitate their dining experience, there are as many forks on the table as there are philosophers. Dining with only one fork would be quite inconvenient, so each philosopher takes both their right and left forks, one in each hand, to eat.

Once a philosopher finishes their meal, they place their forks back on the table and begin sleeping. Upon waking up, they resume thinking. The simulation continues until, unfortunately, a philosopher succumbs to starvation.

The primary objective of this assignment is to ensure that every philosopher gets a fair chance to eat and, most importantly, never starves. It's worth noting that these philosophers do not communicate with each other, and they remain oblivious to the imminent demise of their fellow philosophers.

Your task is to design a solution that ensures the philosophers' survival by avoiding starvation. Philosophers should be able to peacefully coexist at the dining table, engaging in their cyclic activities without risking their lives.


## Common Instructions

Before diving into the project details, let's review some common instructions that apply to this project:

- **Language**: Your project must be written in C.

- **Norm Compliance**: Your project must adhere to the Norm. Norm errors, including those in bonus files/functions, will result in a score of 0.

- **Stability**: Your functions should not quit unexpectedly (e.g., segmentation fault, bus error, double free) apart from undefined behaviors. Unexpected crashes will lead to a non-functional evaluation.

- **Memory Management**: Properly free all heap allocated memory space. No leaks will be tolerated.

- **Makefile**: If required by the subject, include a Makefile to compile your source files with the flags -Wall, -Wextra, and -Werror using cc. Ensure your Makefile does not relink and includes the rules $(NAME), all, clean, fclean, and re.

- **Bonuses**: If applicable, create a bonus rule in your Makefile to include headers, libraries, or functions forbidden in the main part of the project. Store bonus code in separate _bonus.{c/h} files.

- **Libft Integration**: If permitted, integrate your libft by copying its sources and associated Makefile into a libft folder with its own Makefile. Your project’s Makefile should compile the library via its Makefile, then compile the project.

- **Testing**: Develop test programs for your project, although they won't be submitted or graded. These tests will assist in verifying your work and evaluating your peers' work during the defense.

- **Submission**: Submit your work to your assigned git repository. Deepthought may grade your work after peer evaluations, and any errors during Deepthought’s grading will halt the evaluation.

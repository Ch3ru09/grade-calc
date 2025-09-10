# Grade Calculator

This is a grade calculator for the course ece150 made in C++

## How to run

Use your default c++ compiler to compile (of course).

For me , it's clang so here

```bash
clang++ ./main.cpp -o main
./main
```

## Values

Here are the grades that will be calculated:

- Final Exam
- Midterm Exam
- Project 1
- Project 2
- Project 3
- Project 4
- Project 5

## Input System

After taking the input of the user:

1. Checks if the input is a number by taking a regex match of `[0-9.]+` which groups chunks that contain a digit or a dot and compares it with the initial input to see if there's more than just a number.

2. Checks if the input is negative and will error because you cannot have a negative grade.

3. Checks if the grade is above 10000, for the sake of the project, I set this hard limit because I don't think it's necessary to consider a grade above 10000 (even 1000 is a little much).

#### For Max Grade:

4. Checks if the input is fractional by comparing the input with it's floor. The max grade cannot be fractional.

#### For Personal Grade

4. Checks if the input is bigger than the Max grade. I know that in some classes, the student is allowed to have more than 100% but for the sake of the project, the cap is 100%.

When all the checks are passed, the velue will be stored in a variable whose pointer was passed to the function.

### Calculating the grade

First, the if the final grade is greater than any other exam, the grade of that exam is the final grade.

#### Exams

The Exam Grade is calculated from

<img src="https://latex.codecogs.com/svg.image?{\color{White}Exams={3\over&space;4}Final&plus;{1\over&space;4}Midterm}" title="{\color{White}Exam={3\over 4}Final+{1\over 4}Midterm}" />

#### Projects

<img src="https://latex.codecogs.com/svg.image?{\color{white}Project={P1&plus;P2&plus;P3&plus;P4&plus;P5\over&space;5}}" title="{\color{white}Project={P1+P2+P3+P4+P5\over 5}}" />

#### Final grade

The final grade is dependent on a few conditions:

If the Exam grade is ≤ 40%, then the final grade is the Exam grade.

If the Exam grade is ≥ 60%, then the final grade is

```cpp
std::round((2. / 3.) * exams + (1. / 3.) * projects);
```

However, if the Exam grade is between 40 and 60, there's is a linear interpolation of the grade

```cpp
std::round(projects * ((1. / 3.) * ((exams - 40.) / 20.)) + exams * (1. - ((1. / 3.) * ((exams - 40.) / 20.))))
```

## Screen

### Screen refreshing

The console prints a clear screen.

### Progress tracking

The Program tracks where the user input is and will print out everything before it.

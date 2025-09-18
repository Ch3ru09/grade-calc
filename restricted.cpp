#include <iostream>
#include <climits>
#include <cmath>

class Grade
{
private:
  double total_final;
  double grade_final;

  double total_midterm;
  double grade_midterm;

  double total_project_1;
  double grade_project_1;

  double total_project_2;
  double grade_project_2;

  double total_project_3;
  double grade_project_3;

  double total_project_4;
  double grade_project_4;

  double total_project_5;
  double grade_project_5;

  double final_exam;
  double midterm;
  double project_1;
  double project_2;
  double project_3;
  double project_4;
  double project_5;

  void ask_grade(std::string question, double *grade)
  {
    std::string temp;
    std::cout << question;
    std::cin >> temp;

    while (std::stod(temp) <= 0. || std::stod(temp) > UINT_MAX || std::stod(temp) != std::floor(std::stod(temp)))
    {
      std::cout << "Can you answer something sensical to the question: " << question;
      std::cin >> temp;
    };

    *grade = std::stoi(temp);
  }

  void ask_grade(std::string question, double *grade, double max)
  {
    std::string temp;
    std::cout << question;
    std::cin >> temp;

    while (std::stod(temp) < 0 || std::stod(temp) > UINT_MAX || std::stod(temp) > max)
    {
      std::cout << "Can you answer something sensical to the question: " << question;
      std::cin >> temp;
    };

    *grade = std::stod(temp);
  }

  void calculate_grades()
  {
    final_exam = (grade_final / total_final) * 100;

    midterm = std::max((grade_midterm / total_midterm) * 100, final_exam);
    project_1 = std::max((grade_project_1 / total_project_1) * 100, final_exam);
    project_2 = std::max((grade_project_2 / total_project_2) * 100, final_exam);
    project_3 = std::max((grade_project_3 / total_project_3) * 100, final_exam);
    project_4 = std::max((grade_project_4 / total_project_4) * 100, final_exam);
    project_5 = std::max((grade_project_5 / total_project_5) * 100, final_exam);
  }

  double calculate_exams()
  {
    if (final_exam >= midterm)
    {
      // this doesn't really matter because the supremacy of the final grade is already applied in calculate_grades
      return final_exam;
    }
    return final_exam * 0.75 + midterm * 0.25;
  }

  double calculate_projects()
  {
    return (project_1 + project_2 + project_3 + project_4 + project_5) / 5;
  }

  double get_final_grade()
  {
    calculate_grades();

    double exams = calculate_exams();
    double projects = calculate_projects();

    if (exams <= 40.)
    {
      return std::round(exams);
    }

    if (exams >= 60.)
    {
      return std::round((2. / 3.) * exams + (1. / 3.) * projects);
    }

    return std::round(projects * ((1. / 3.) * ((exams - 40.) / 20.)) + exams * (1. - ((1. / 3.) * ((exams - 40.) / 20.))));
  }

public:
  void ask_grades()
  {
    ask_grade("What is the max grade for the Final?", &total_final);
    ask_grade("What is your grade for the Final?", &grade_final, total_final);
    ask_grade("What is the max grade for the Midterm?", &total_midterm);
    ask_grade("What is your grade for the Midterm?", &grade_midterm, total_midterm);

    ask_grade("What is the max grade for the Project 1?", &total_project_1);
    ask_grade("What is your grade for the Project 1?", &grade_project_1, total_project_1);
    ask_grade("What is the max grade for the Project 2?", &total_project_2);
    ask_grade("What is your grade for the Project 2?", &grade_project_2, total_project_2);
    ask_grade("What is the max grade for the Project 3?", &total_project_3);
    ask_grade("What is your grade for the Project 3?", &grade_project_3, total_project_3);
    ask_grade("What is the max grade for the Project 4?", &total_project_4);
    ask_grade("What is your grade for the Project 4?", &grade_project_4, total_project_4);
    ask_grade("What is the max grade for the Project 5?", &total_project_5);
    ask_grade("What is your grade for the Project 5?", &grade_project_5, total_project_5);
  }

  void print_final_grade()
  {
    int final_grade = (int)get_final_grade();

    std::cout << "Here's your final grade: " << final_grade << std::endl;
  }
};

int main()
{
  Grade grade;

  grade.ask_grades();
  grade.print_final_grade();

  return 0;
}
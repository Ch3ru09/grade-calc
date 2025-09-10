#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

bool isNumber(std::string x)
{
  std::smatch match;
  std::regex_search(x, match, std::regex("[0-9.]+"));
  return x == match[0];
}

void clear_screen()
{
  std::cout << "\x1B[2J\x1B[H";
}

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

  double results[7]{};

  void ask_grade(std::string question, double *grade, int index)
  {
    std::string temp;
    clear_screen();
    print_progress(index);
    std::cout << question << std::endl;
    std::cin >> temp;

    while (temp == "" || !isNumber(temp) || std::stod(temp) <= 0 || std::stod(temp) != std::floor(std::stod(temp)))
    {
      clear_screen();
      print_progress(index);
      std::cout << "Can you answer something sensical to the question: " << question << std::endl;
      std::cin >> temp;
    };

    *grade = std::stoi(temp);
  }

  void ask_grade(std::string question, double *grade, double max, int index)
  {
    std::string temp;
    clear_screen();
    print_progress(index);
    std::cout << question << std::endl;
    std::cin >> temp;

    while (temp == "" || !isNumber(temp) || std::stod(temp) <= 0 || std::stod(temp) > max)
    {
      clear_screen();
      print_progress(index);
      std::cout << "Can you answer something sensical to the question: " << question << std::endl;
      std::cin >> temp;
    };

    *grade = std::stod(temp);
  }

  std::string get_messages(int lengthAt)
  {
    std::string messages[14] = {
        "Final Exam Max: " + std::to_string((int)total_final),
        "Final Exam Grade: " + std::to_string((int)grade_final),
        "Midterm Exam Max: " + std::to_string((int)total_midterm),
        "Midterm Exam Grade: " + std::to_string((int)grade_midterm),

        "Project 1 Exam Max: " + std::to_string((int)total_project_1),
        "Project 1 Exam Grade: " + std::to_string((int)grade_project_1),
        "Project 2 Exam Max: " + std::to_string((int)total_project_2),
        "Project 2 Exam Grade: " + std::to_string((int)grade_project_2),
        "Project 3 Exam Max: " + std::to_string((int)total_project_3),
        "Project 3 Exam Grade: " + std::to_string((int)grade_project_3),
        "Project 4 Exam Max: " + std::to_string((int)total_project_4),
        "Project 4 Exam Grade: " + std::to_string((int)grade_project_4),
        "Project 5 Exam Max: " + std::to_string((int)total_project_5),
        "Project 5 Exam Grade: " + std::to_string((int)grade_project_5),
    };

    std::stringstream s;
    for (int i = 0; i < lengthAt; i++)
    {
      s << "  " << messages[i] << "\n";
    }

    return s.str();
  }

  double *calculate_grades()
  {
    double final_exam = (grade_final / total_final) * 100;

    results[0] = final_exam;
    results[1] = std::max((grade_midterm / grade_final) * 100, final_exam);
    results[2] = std::max((grade_project_1 / total_project_1) * 100, final_exam);
    results[3] = std::max((grade_project_2 / total_project_2) * 100, final_exam);
    results[4] = std::max((grade_project_3 / total_project_3) * 100, final_exam);
    results[5] = std::max((grade_project_4 / total_project_4) * 100, final_exam);
    results[6] = std::max((grade_project_5 / total_project_5) * 100, final_exam);
  }

  double calculate_exams()
  {
    if (results[0] >= results[1])
    {
      return results[0];
    }
    return results[0] * 0.75 + results[1] * 0.25;
  }

  double calculate_projects()
  {
    return (results[2] + results[3] + results[4] + results[5] + results[6]) / 5;
  }

  void print_progress(int index)
  {
    std::cout << "Grades:" << std::endl;
    std::cout << get_messages(index) << std::endl;
  }

  double get_final_grade()
  {
    calculate_grades();

    double exams = calculate_exams();
    double projects = calculate_projects();

    if (exams <= 40)
      return std::round(exams);

    if (exams >= 60)
      return std::round((2 / 3) * exams + (1 / 3) * projects);

    return std::round(projects * ((1 / 3) * ((exams - 40) / 20)) + exams * (1 - ((1 / 3) * ((exams - 40) / 20))));
  }

public:
  void ask_grades()
  {
    ask_grade("What is the max grade for the Final?", &total_final, 0);
    ask_grade("What is your grade for the Final?", &grade_final, total_final, 1);
    ask_grade("What is the max grade for the Midterm?", &total_midterm, 2);
    ask_grade("What is your grade for the Midterm?", &grade_midterm, total_midterm, 3);

    ask_grade("What is the max grade for the Project 1?", &total_project_1, 4);
    ask_grade("What is your grade for the Project 1?", &grade_project_1, total_project_1, 5);
    ask_grade("What is the max grade for the Project 2?", &total_project_2, 6);
    ask_grade("What is your grade for the Project 2?", &grade_project_2, total_project_2, 7);
    ask_grade("What is the max grade for the Project 3?", &total_project_3, 8);
    ask_grade("What is your grade for the Project 3?", &grade_project_3, total_project_3, 9);
    ask_grade("What is the max grade for the Project 4?", &total_project_4, 10);
    ask_grade("What is your grade for the Project 4?", &grade_project_4, total_project_4, 11);
    ask_grade("What is the max grade for the Project 5?", &total_project_5, 12);
    ask_grade("What is your grade for the Project 5?", &grade_project_5, total_project_5, 13);
  }

  void print_final_grade()
  {
    std::string msg[7] = {"Final", "Midterm", "Project 1", "Project 2", "Project 3", "Project 4", "Project 5"};

    clear_screen();
    std::cout << "Here are your grades:\n"
              << std::endl;
    for (int i = 0; i < (sizeof(msg) / sizeof(*msg)); i++)
    {
      std::cout << msg[i] << ": " << results[i] << std::endl;
    }

    std::cout << "Here's your final grade: " << (int)get_final_grade();
  }

  std::string to_string()
  {
    std::stringstream s;
    s << "Grade {\n";
    s << get_messages(14);
    s << "}";

    return s.str();
  }
};

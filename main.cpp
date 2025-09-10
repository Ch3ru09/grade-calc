#include "./Grade.cpp"

int main()
{
    Grade grade;

    grade.ask_grades();
    grade.print_final_grade();

    // std::cout << grade.to_string() << std::endl;
    return 0;
}
#include "./Grade.cpp"

int main()
{
    Grade grade;

    grade.ask_grades();

    std::cout << grade.to_string() << std::endl;
    return 0;
}
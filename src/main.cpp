#include "../include/StudentManager.hpp"
#include <iostream>

int main(void)
{
    StudentManager studentManager;
    studentManager.addStudent("Alice", 20);
    studentManager.addStudent("Bob", 22);
    studentManager.addStudent("Charlie", 19);
    studentManager.addStudent("Rithy", 18);
    studentManager.addStudent("Reaksmey", 18);

    studentManager.printAllStudentsInfo();

    return 0;
}
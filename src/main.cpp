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
    std::cout << "\nTotal students: " << studentManager.countAllStudents() << "\n";

    int id;
    std::cout << "\nEnter student ID to delete: ";
    std::cin >> id;
    studentManager.deleteStudentById(id);

    studentManager.printAllStudentsInfo();
    std::cout << "\nTotal students: " << studentManager.countAllStudents() << "\n";

    return 0;
}
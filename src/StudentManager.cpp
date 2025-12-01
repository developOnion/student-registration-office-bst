#include "../include/StudentManager.hpp"

StudentManager::StudentManager()
{
    this->root = nullptr;
}

StudentManager::~StudentManager()
{
}

void StudentManager::addStudent(Student newStudent)
{
}

void StudentManager::deleteStudentById(int id)
{
}

Student StudentManager::searchById(int id)
{
    return Student();
}

Student StudentManager::searchByName(std::string name)
{
    return Student();
}

void StudentManager::sortStudentsByName()
{
}

void StudentManager::sortStudentsByAge()
{
}

void StudentManager::sortStudentsById()
{
}

int StudentManager::countAllStudents()
{
    return 0;
}

void StudentManager::printAllStudentsInfo()
{
}
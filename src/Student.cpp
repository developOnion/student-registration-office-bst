#include "../include/Student.hpp"

Student::Student(int id, std::string name, int age)
{
    this->id = id;
    this->name = name;
    this->age = age;
}

Student::~Student()
{
}

int Student::getId()
{
    return this->id;
}

std::string Student::getName()
{
    return this->name;
}

int Student::getAge()
{
    return this->age;
}

void Student::toString()
{
    std::cout << "ID: " << this->id << ", Name: " << this->name << ", Age: " << this->age << "\n";
}

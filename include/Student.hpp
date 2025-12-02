#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>

class Student
{
private:
    int id;
    std::string name;
    int age;

public:
    // constructor
    Student() {};
    Student(int id, std::string name, int age);

    // deconstructor
    ~Student();

    // getter
    int getId();
    std::string getName();
    int getAge();

    // util
    void toString();
};

#endif
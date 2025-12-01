#ifndef STUDENTMANAGER_HPP
#define STUDENTMANAGER_HPP

#include "./Student.hpp"

class StudentManager
{
private:
    typedef struct Node
    {
        Student data;
        Node *left;
        Node *right;

        Node(Student student)
        {
            this->data = student;
            this->left = this->right = nullptr;
        }
    } Node;

    Node *root;

public:
    StudentManager();

    ~StudentManager();

    void addStudent(Student newStudent);
    void deleteStudentById(int id);
    Student searchById(int id);
    Student searchByName(std::string name);
    void sortStudentsByName();
    void sortStudentsByAge();
    void sortStudentsById();
    int countAllStudents();
    void printAllStudentsInfo();
};

#endif
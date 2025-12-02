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

    // helper function
    Node *addStudentRecursive(Node *node, Student newStudent);
    void printAllStudentsInfoRecursive(Node *node); // inorder traversal

    bool isIDExist(Node *node, int id);

public:
    StudentManager();

    ~StudentManager();

    void addStudent(std::string name, int age);
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
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
    Node *deleteStudentByIdRecursive(Node *node, int id);

    void printAllStudentsInfoRecursive(Node *node); // inorder traversal
    int countAllStudentsRecursive(Node *node);

    // check if ID exists
    bool isIDExist(Node *node, int id);
    void freeTreeRecursive(Node *node);

public:
    // constructor
    StudentManager();

    // deconstructor
    ~StudentManager();

    // add student to BST by generating unique ID
    void addStudent(std::string name, int age);

    // delete student by ID
    void deleteStudentById(int id);

    Student searchById(int id);
    Student searchByName(std::string name);

    void sortStudentsByName();
    void sortStudentsByAge();
    void sortStudentsById();

    // utils
    int countAllStudents();
    void printAllStudentsInfo();
    int height(Node *node);
    Node *inorderPredecessor(Node *node);
    Node *inorderSuccessor(Node *node);
};

#endif
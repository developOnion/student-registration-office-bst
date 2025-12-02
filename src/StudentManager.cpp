#include "../include/StudentManager.hpp"

StudentManager::StudentManager()
{
    this->root = nullptr;
}

StudentManager::~StudentManager()
{
}

StudentManager::Node *StudentManager::addStudentRecursive(Node *node, Student newStudent)
{
    if (node == nullptr)
        return new Node(newStudent);

    if (newStudent.getId() < node->data.getId())
        node->left = addStudentRecursive(node->left, newStudent);
    else if (newStudent.getId() > node->data.getId())
        node->right = addStudentRecursive(node->right, newStudent);

    return node;
}

void StudentManager::addStudent(std::string name, int age)
{
    int newId;
    int minId = 20250000;
    int maxId = 20259999;
    std::srand(std::time(NULL));

    do
    {
        newId = std::rand() % (maxId - minId + 1) + minId;
    } while (isIDExist(this->root, newId));

    Student newStudent(newId, name, age);

    if (this->root == nullptr)
        this->root = new Node(newStudent);
    else
        this->root = addStudentRecursive(this->root, newStudent);
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

void StudentManager::printAllStudentsInfoRecursive(Node *node)
{
    if (node == nullptr)
        return;

    printAllStudentsInfoRecursive(node->left);
    node->data.toString();
    printAllStudentsInfoRecursive(node->right);
}

void StudentManager::printAllStudentsInfo()
{
    printAllStudentsInfoRecursive(this->root);
}

bool StudentManager::isIDExist(Node *node, int id)
{
    if (node == nullptr)
        return false;

    if (node->data.getId() == id)
        return true;

    if (node->data.getId() > id)
        return isIDExist(node->left, id);
    else
        return isIDExist(node->right, id);
}
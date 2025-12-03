#include "../include/StudentManager.hpp"

StudentManager::StudentManager()
{
    this->root = nullptr;
}

void StudentManager::freeTreeRecursive(Node *node)
{
    if (node == nullptr)
        return;

    freeTreeRecursive(node->left);
    freeTreeRecursive(node->right);
    delete node;
}

StudentManager::~StudentManager()
{
    freeTreeRecursive(this->root);
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

StudentManager::Node *StudentManager::deleteStudentByIdRecursive(Node *node, int id)
{
    if (node == nullptr)
    {
        std::cout << "\nStudent with ID " << id << " not found.\n";
        return nullptr;
    }

    if (id < node->data.getId())
        node->left = deleteStudentByIdRecursive(node->left, id);
    else if (id > node->data.getId())
        node->right = deleteStudentByIdRecursive(node->right, id);
    else
    {
        Node *tmp;
        // leaf node
        if (node->left == nullptr && node->right == nullptr)
        {
            if (node == this->root)
                this->root = nullptr;

            delete node;
            return nullptr;
        }
        // node with only right child
        else if (node->left == nullptr)
        {
            tmp = node->right;

            delete node;
            return tmp;
        }
        // node with only left child
        else if (node->right == nullptr)
        {
            tmp = node->left;

            delete node;
            return tmp;
        }
        // node with two children
        else
        {
            if (height(node->left) > height(node->right))
            {
                tmp = inorderPredecessor(node->left);
                node->data = tmp->data;
                node->left = deleteStudentByIdRecursive(node->left, tmp->data.getId());
            }
            else
            {
                tmp = inorderSuccessor(node->right);
                node->data = tmp->data;
                node->right = deleteStudentByIdRecursive(node->right, tmp->data.getId());
            }
        }
    }

    return node;
}

void StudentManager::deleteStudentById(int id)
{
    if (this->root == nullptr)
    {
        std::cout << "Database is empty, no students to delete.\n";
        return;
    }

    this->root = deleteStudentByIdRecursive(this->root, id);
}

StudentManager::Node *StudentManager::searchByIdRecursive(Node *node, int id)
{
    if (node == nullptr)
        return nullptr;

    if (node->data.getId() == id)
        return node;

    if (node->data.getId() > id)
        return searchByIdRecursive(node->left, id);
    else
        return searchByIdRecursive(node->right, id);
}

Student StudentManager::searchById(int id)
{
    Node *resultNode = searchByIdRecursive(this->root, id);
    if (resultNode != nullptr)
        return resultNode->data;
    else
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

int StudentManager::countAllStudentsRecursive(Node *node)
{
    if (node == nullptr)
        return 0;

    return 1 + countAllStudentsRecursive(node->left) + countAllStudentsRecursive(node->right);
}

// utils

int StudentManager::height(Node *node)
{
    if (node == nullptr)
        return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return std::max(leftHeight, rightHeight) + 1;
}

int StudentManager::countAllStudents()
{
    return countAllStudentsRecursive(this->root);
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
    std::cout << "\nAll Students Information:\n";
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

StudentManager::Node *StudentManager::inorderPredecessor(Node *node)
{
    if (node == nullptr || node->right == nullptr)
        return node;

    return inorderPredecessor(node->right);
}

StudentManager::Node *StudentManager::inorderSuccessor(Node *node)
{
    if (node == nullptr || node->left == nullptr)
        return node;

    return inorderSuccessor(node->left);
}
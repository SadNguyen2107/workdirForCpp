#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Node.hpp"

class LinkedList
{
private:
    Node *_head;

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList &other);

    int GetTotalNodes();
    void Insert(int positionToInsert, int value);
};

LinkedList::LinkedList() : _head(nullptr) {}

LinkedList::~LinkedList()
{
    Node *current_node = this->_head;

    while (current_node != nullptr)
    {
        Node *node_to_delete = current_node;

        // Move to the next Node
        current_node = current_node->_next;
        delete node_to_delete;
    }

    // Assign the nullptr for the HEAD
    // To prevent memory leak
    _head = nullptr;
}

LinkedList::LinkedList(const LinkedList &other)
{
    // Assign the Head
    this->_head = new Node(other._head->_value);

    // Make 2 pointer to keep track Other and This
    Node *this_current_node = this->_head;
    Node *other_current_node = other._head->_next;

    while (other_current_node != nullptr)
    {
        // Make a node
        this_current_node->_next = new Node(other_current_node->_value);

        // Move to the next node
        other_current_node = other_current_node->_next;
    }
}

int LinkedList::GetTotalNodes()
{
    // Counter to return
    int counter = 0;

    Node *current_node = this->_head;
    while (current_node != nullptr)
    {
        counter++;

        // Move to the next node -> To increase the counter
        current_node = current_node->_next;
    }

    return counter;
}

/// @brief Insert at positionToInsert with the value. LinkedList start with index 0
/// @param positionToInsert must larger than 0
/// @param value
void LinkedList::Insert(int positionToInsert, int value)
{
    if (positionToInsert < 0)
    {
        std::cout << "===============================================================" << std::endl;
        std::cerr << "Illegal Position!" << std::endl;
        std::cerr << "Index Must Start From 0" << std::endl;
        return;
    }

    // Node to insert
    Node *newNode = new Node(value);

    // Insert At Head
    if (positionToInsert == 0 || this->_head == nullptr)
    {
        std::cout << "===============================================================" << std::endl;
        std::cout << "Insert!" << std::endl;

        newNode->_next = this->_head;
        this->_head = newNode;
        return;
    }

    // Node to travel
    Node *prev_node = nullptr;
    Node *current_node = this->_head;

    for (size_t index = 0; index < positionToInsert; index++)
    {
        // If Found
        if (current_node == nullptr)
        {
            break;
        }

        prev_node = current_node;
        current_node = current_node->_next;
    }

    // Assign the Node
    std::cout << "===============================================================" << std::endl;
    std::cout << "Insert!" << std::endl;

    prev_node->_next = newNode;
    newNode->_next = current_node;
}

#endif
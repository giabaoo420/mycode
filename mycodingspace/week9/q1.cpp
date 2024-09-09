/*Exercise 1 – Linked List:
Define a class namely Node with three attributes are value (int), next (pointer to the next linked
node), prev (pointer to the previous linked node), and provide class constructor to initialize
values.
a) Create four nodes with values are 8, 5, 3, 6. Create a doubly linked list by connect them
together in sequence.
Write two functions to print out values of connected nodes in forward and backward orders.
Sample Run:
8 --> 5 --> 3 --> 6 -->
6 --> 3 --> 5 --> 8 -->
b) Write two functions to allow insert a node, and delete a node as below:
• void insertNode(Node *&head, Node *&tail, Node *priorNode, Node *newNode)
Insert the newNode right after priorNode (insert at the beginning if priorNode is NULL,
and insert at the end if priorNode is the tail).
• void deleteNode(Node *&head, Node *&tail, Node *delNote)
Delete the delnote from the linked list (remove at the beginning if delNote is the head,
and remove at the end if delNote is the tail).
Test them by inserting a new node with value 100 at the head of the list, another one with
value 200 between nodes of values 3 and 6, and removing the node of value 5.
Print out values to check.
100 -->8 --> 3 --> 200 --> 6 -->
c) Write a function to swap two nodes (swap their positions, not values).
d) Write a function to sort elements of the linked list in ascending order using Bubble Sort.*/

#include <iostream>
#include <algorithm>  // For std::swap

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

// Function to print the list from head to tail
void printForward(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value;
        if (current->next != nullptr) cout << " --> ";
        current = current->next;
    }
    cout << " --> " << endl;
}

// Function to print the list from tail to head
void printBackward(Node* tail) {
    Node* current = tail;
    while (current != nullptr) {
        cout << current->value;
        if (current->prev != nullptr) cout << " --> ";
        current = current->prev;
    }
    cout << " --> " << endl;
}

// Function to insert a node
void insertNode(Node*& head, Node*& tail, Node* priorNode, Node* newNode) {
    if (priorNode == nullptr) {
        newNode->next = head;
        if (head != nullptr) head->prev = newNode;
        head = newNode;
        if (tail == nullptr) tail = newNode;
    } else if (priorNode == tail) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        newNode->next = priorNode->next;
        newNode->prev = priorNode;
        if (priorNode->next != nullptr) priorNode->next->prev = newNode;
        priorNode->next = newNode;
    }
}

// Function to delete a node
void deleteNode(Node*& head, Node*& tail, Node* delNode) {
    if (delNode == head) {
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        if (delNode == tail) tail = nullptr;
    } else if (delNode == tail) {
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        if (delNode == head) head = nullptr;
    } else {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    delete delNode;
}

// Function to swap two nodes
void swapNodes(Node*& head, Node*& tail, Node* node1, Node* node2) {
    if (node1 == node2) return;  // No need to swap identical nodes

    Node* tempPrev = node1->prev;
    Node* tempNext = node1->next;

    if (node1->prev) node1->prev->next = node2;
    if (node1->next) node1->next->prev = node2;

    node2->prev = tempPrev;
    node2->next = tempNext;

    if (node2->prev) node2->prev->next = node2;
    if (node2->next) node2->next->prev = node2;

    if (node1 == head) head = node2;
    if (node2 == tail) tail = node1;

    node1->prev = node2;
    node1->next = node2->next;
    node2->prev = tempPrev;
    node2->next = tempNext;

    if (node1->next == nullptr) tail = node1;
    if (node2->prev == nullptr) head = node2;
}

// Function to sort the list using bubble sort
void bubbleSort(Node*& head, Node*& tail) {
    if (head == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->value > current->next->value) {
                swap(current->value, current->next->value);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Main function to test all functionalities
int main() {
    // Creating initial nodes
    Node* head = new Node(8);
    Node* tail = head;
    Node* node2 = new Node(5);
    Node* node3 = new Node(3);
    Node* node4 = new Node(6);

    // Connecting nodes
    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    tail = node4;

    // Test insertion and deletion
    Node* newNode1 = new Node(100);
    insertNode(head, tail, nullptr, newNode1);  // Insert at the head

    Node* newNode2 = new Node(200);
    insertNode(head, tail, node3, newNode2);  // Insert between nodes 3 and 6

    deleteNode(head, tail, node2);  // Remove node with value 5

    // Print the updated list
    cout << "Forward: ";
    printForward(head);

    cout << "Backward: ";
    printBackward(tail);

    // Swap nodes
    swapNodes(head, tail, head, node3);  // Swap head (100) and node3 (3)

    cout << "After Swap - Forward: ";
    printForward(head);

    cout << "After Swap - Backward: ";
    printBackward(tail);

    // Sort the list
    bubbleSort(head, tail);

    cout << "After Sorting - Forward: ";
    printForward(head);

    cout << "After Sorting - Backward: ";
    printBackward(tail);

    // Clean up
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
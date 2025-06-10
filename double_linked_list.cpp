#include <iostream>
using namespace std;
// Node class for doubly linked list
class DoublyNode {
    public:
        int data;
        DoublyNode* next;
        DoublyNode* prev;
    
        DoublyNode(int n) {
            data = n;
            next = prev = nullptr;
        }
    };
    
    // Doubly Linked List class
    class DoublyLinkedList {
    public:
        DoublyNode* head;
    
        DoublyLinkedList() {
            head = nullptr;
        }
    
        // Insert a node at the front of the doubly linked list
        void insertFromFront(int n) {
            DoublyNode* newNode = new DoublyNode(n);
            if (head != nullptr) {
                newNode->next = head;
                head->prev = newNode;
            }
            head = newNode;
        }
        // Insert a node at a specific position in the doubly linked list
        void insertAtPosition(int n, int pos) {
            DoublyNode* newNode = new DoublyNode(n);
            if (pos == 0) {
                insertFromFront(n);
                return;
            }
            DoublyNode* temp = head;
            for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Position out of bounds\n";
                delete newNode;
                return;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
        // insert a node at the end of the doubly linked list
        void insertFromEnd(int n) {
            DoublyNode* newNode = new DoublyNode(n);
            if (head == nullptr) {
                head = newNode;
                return;
            }
            DoublyNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
// insert sorted node in the doubly linked list
        void insertSorted(int n) {
            DoublyNode* newNode = new DoublyNode(n);
            if (head == nullptr || head->data >= n) {
                newNode->next = head;
                if (head != nullptr) {
                    head->prev = newNode;
                }
                head = newNode;
                return;
            }
            DoublyNode* temp = head;
            while (temp->next != nullptr && temp->next->data < n) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    // Delete a node from the doubly linked list
        void deleteNode(int n) {
            if (head == nullptr) {
                cout << "List is empty\n";
                return;
            }
            DoublyNode* temp = head;
            while (temp != nullptr && temp->data != n) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Node not found\n";
                return;
            }
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next; // If it's the head node
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            delete temp;
        }
        // Display the doubly linked list
        void display() {
            DoublyNode* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << "null\n";
        }
        // Print the doubly linked list in reverse order
        void printReverse() {
            DoublyNode* temp = head;
            if (temp == nullptr) {
                cout << "List is empty\n";
                return;
            }
            // Move to the end of the list
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // Print in reverse order
            while (temp != nullptr) {
                cout << temp->data << " <-> ";
                temp = temp->prev;
            }
            cout << "null\n";
        }
    };

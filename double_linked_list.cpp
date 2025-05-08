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
    
        // Display the doubly linked list
        void display() {
            DoublyNode* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << "null\n";
        }
    };
    
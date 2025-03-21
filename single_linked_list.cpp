#include <iostream>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int n) {
        data = n;
        next = nullptr;
    }
};

// Singly Linked List class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the front of the list
    void insertFromFront(int n) {
        Node* newNode = new Node(n);
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at a specific position in the list
    void insertInMiddle(int n, int position) {
        Node* newNode = new Node(n);
        if (position == 0 || head == nullptr) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete the first node in the list
    void deleteFromFront() {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    // sorting function using bubble sort
    void  sortlist()
    {
        if(!head || !head->next)
            return;
            bool swapped;
            do 
            {
                swapped = false;
                Node* cur = head;
                while (cur->next!=nullptr)
                {
                    if(cur->data > cur->next->data)
                    {
                     swap (cur->data, cur->next->data);
                        swapped = true;
                    }
                    cur = cur->next;
                }}
                while(swapped);
            }

    // Split the list into two based on sign (positive and negative numbers)
    void splitBySign(LinkedList &positiveList, LinkedList &negativeList) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data >= 0) {
                positiveList.insertFromFront(temp->data);
            } else {
                negativeList.insertFromFront(temp->data);
            }
            temp = temp->next;
        }
        positiveList.sortlist();
        negativeList.sortlist();
    }

    // Remove duplicate values from the list
    void removeDuplicates() {
        Node* current = head;
        while (current != nullptr) {
            Node* runner = current;
            while (runner->next != nullptr) {
                if (runner->next->data == current->data) {
                    Node* duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        if (head == nullptr)
            cout << "Empty linked list\n";
        else {
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "null\n";
        }
    }
};

// Ordered Linked List (Maintains ascending order)
class OrderedLinkedList : public LinkedList {
public:
    // Insert node in sorted order
    void insertOrdered(int n) {
        Node* newNode = new Node(n);
        if (head == nullptr || head->data >= n) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->data < n) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
};

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

// List implemented as an array
class ArrayList {
public:
    int* arr;
    int size;
    int capacity;

    ArrayList(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // Insert an element into the array list
    void insert(int n) {
        if (size == capacity) {
            cout << "Array is full\n";
            return;
        }
        arr[size++] = n;
    }

    // Display the array list
    void display() {
        if (size == 0) {
            cout << "Empty array list\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~ArrayList() {
        delete[] arr;
    }
};

int main() {
    LinkedList ll;
    ll.insertFromFront(-10);
    ll.insertFromFront(20);
    ll.insertFromFront(-30);
    ll.insertFromFront(40);
    cout << "Original List: ";
    ll.display();

    LinkedList positiveList, negativeList;
    ll.splitBySign(positiveList, negativeList);
    cout << "Positive List: ";
    positiveList.display();
    cout << "Negative List: ";
    negativeList.display();

    ll.insertFromFront(20);
    ll.insertFromFront(-10);
    cout << "List with Duplicates: ";
    ll.display();
    ll.removeDuplicates();
    cout << "After Removing Duplicates: ";
    ll.display();

    return 0;
}

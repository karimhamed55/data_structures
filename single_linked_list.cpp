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

    // Insert a new node at the end of the list
    void insertFromEnd(int n) {
        Node* newNode = new Node(n);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert a new node at a specific position in the list
    void insertAtPosition(int n, int pos) {
        Node* newNode = new Node(n);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds\n";
            delete newNode;
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

    // Delete the last node in the list
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete a node at a specific position in the list
    void deleteAtPosition(int pos) {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }

        if (pos < 0) {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        int i = 0;
        while (temp != nullptr && i < pos - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // Delete nodes by key
    void delete_key(int n) {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }

        while (head && head->data == n) {
            Node* del = head;
            head = head->next;
            delete del;
        }

        if (head == nullptr) return;

        Node* temp = head;
        while (temp->next != nullptr) {
            if (temp->next->data == n) {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            } else {
                temp = temp->next;
            }
        }
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

    // Sort the linked list (bubble sort)
    void sort() {
        if (head == nullptr || head->next == nullptr) {
            return; // List is empty or has only one element
        }

        Node* current = head;
        Node* index = nullptr;
        int temp;

        while (current != nullptr) {
            index = current->next;
            while (index != nullptr) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    // Split the list into two based on sign (positive and negative numbers)
    void splitBySign(LinkedList &positiveList, LinkedList &negativeList) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data >= 0) {
                positiveList.insertFromEnd(temp->data);
            } else {
                negativeList.insertFromEnd(temp->data);
            }
            temp = temp->next;
        }
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
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
    ll.removeDuplicates();

    cout << "\nList after removing duplicates: ";
    ll.display();

    ll.delete_key(20);
    cout << "List after deleting key 20: ";
    ll.display();

    return 0;
}

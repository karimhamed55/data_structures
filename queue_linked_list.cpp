#include <iostream>
using namespace std;

class Node {
public:
    int data;  // Data to store the element
    Node* next;  // Pointer to the next node

    // Constructor to create a new node
    Node(int n) {
        data = n;
        next = nullptr;  // Initially, the next pointer is null
    }
};

class Queue {
public:
    Node* head;  // Pointer to the front node of the queue (formerly 'front')
    Node* tail;  // Pointer to the rear node of the queue (formerly 'rear')
    int count;    // Tracks the number of elements in the queue

    // Constructor to initialize the queue
    Queue() {
        head = tail = nullptr;  // Initially, both head and tail are null (empty queue)
        count = 0;  // Queue is initially empty
    }

    // Destructor to delete all nodes and free memory
    ~Queue() {
        while (!isempty()) {
            dequeue();  // Remove all elements
        }
    }

    // Function to check if the queue is empty
    bool isempty() {
        return head == nullptr;  // If head is null, the queue is empty
    }

    // Function to add an element to the queue (enqueue operation)
    void enqueue(int n) {
        Node* newNode = new Node(n);  // Create a new node with the given value
        if (isempty()) {  // If the queue is empty, both head and tail should point to the new node
            head = tail = newNode;
        } else {  // Otherwise, add the new node to the end of the queue and move tail to it
            tail->next = newNode;
            tail = newNode;
        }
        count++;  // Increment the count of elements
    }

    // Function to remove an element from the front of the queue (dequeue operation)
    int dequeue() {
        if (isempty()) {  // If the queue is empty, we cannot dequeue
            cout << "Queue is empty\n";
            return -1;  // Return -1 to indicate empty queue
        }
        int value = head->data;  // Save the data of the head element
        Node* temp = head;  // Store the head node to delete it later
        head = head->next;  // Move the head pointer to the next node
        delete temp;  // Free the memory of the old head node
        if (head == nullptr) {  // If the queue becomes empty, set tail to null as well
            tail = nullptr;
        }
        count--;  // Decrease the count of elements
        return value;  // Return the dequeued value
    }

    // Function to get the element at the front of the queue without removing it
    int peek() {
        if (isempty()) {  // If the queue is empty, return -1
            cout << "Queue is empty\n";
            return -1;
        }
        return head->data;  // Return the data of the head node
    }

    // Function to display the elements of the queue
    void display() {
        if (isempty()) {  // If the queue is empty, print a message
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        Node* temp = head;
        while (temp != nullptr) {  // Traverse the linked list and print the data of each node
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;  // New line after displaying the queue
    }

    // Function to get the size of the queue
    int size() {
        return count;  // Return the count of elements
    }
};

int main() {
    Queue q;  // Create a queue

    // Add elements to the queue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // Display the queue elements
    q.display();

    // Display the size of the queue
    cout << "Queue size: " << q.size() << endl;

    // Dequeue elements and display the queue after each dequeue
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    // Peek at the front element without removing it
    cout << "Front element: " << q.peek() << endl;

    // Display the size of the queue after some dequeues
    cout << "Queue size: " << q.size() << endl;

    return 0;
}

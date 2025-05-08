#include <iostream>
using namespace std;

class queue {
public:
    int* items;  // Array to hold the queue elements
    int front;   // Index of the front element
    int rear;    // Index of the next available slot for enqueue
    int count;   // Tracks the current number of elements in the queue
    int size;    // Maximum capacity of the queue

    // Constructor to initialize the queue with a given size
    queue(int sz) {
        front = rear = 0;  // Initially, front and rear are at the beginning of the array
        count = 0;  // Queue is initially empty
        size = sz;  // Set the size of the queue
        items = new int[size]; // Dynamically allocate memory for the queue array
    }

    // Destructor to free the dynamically allocated memory for the queue
    ~queue() {
        delete[] items;  // Free up the allocated memory
    }

    // Function to check if the queue is empty
    bool isempty() {
        return count == 0;  // If count is 0, the queue is empty
    }

    // Function to check if the queue is full
    bool isfull() {
        return count == size;  // If count is equal to size, the queue is full
    }

    // Function to calculate the next index in a circular manner
    int next(int pos) {
        return (pos + 1) % size;  // Circular increment, wraps around to 0 when pos reaches size
    }

    // Function to add an element to the queue
    void enqueue(int n) {
        if (isfull()) {  // If the queue is full, no more elements can be added
            cout << "Queue is full\n";
            return;  // Exit the function as no element can be added
        }
        items[rear] = n;  // Place the new element at the rear of the queue
        rear = next(rear);  // Move the rear index to the next available slot (circularly)
        count++;  // Increment the count of elements in the queue
    }

    // Function to remove an element from the front of the queue
    int dequeue() {
        if (isempty()) {  // If the queue is empty, no elements can be removed
            cout << "Queue is empty\n";
            return -1;  // Return -1 to indicate the queue is empty
        }
        int value = items[front];  // Save the front element to return it
        front = next(front);  // Move the front index to the next element (circularly)
        count--;  // Decrease the count of elements in the queue
        return value;  // Return the dequeued element
    }

    // Function to display the elements of the queue
    void display() {
        if (isempty()) {  // If the queue is empty, print a message and exit
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front, step = 0; step < count; ++step, i = next(i)) {  // Loop through the queue circularly
            cout << items[i] << " ";  // Print each element in the queue
        }
        cout << endl;  // Print a newline after displaying the elements
    }
};

int main() {
    queue q(5);  // Create a queue with a capacity of 5 elements

    q.enqueue(1);  // Add 1 to the queue
    q.enqueue(2);  // Add 2 to the queue
    q.enqueue(3);  // Add 3 to the queue
    q.enqueue(4);  // Add 4 to the queue
    q.enqueue(5);  // Add 5 to the queue

    q.display();  // Display the queue after enqueuing elements

    cout << "Dequeued: " << q.dequeue() << endl;  // Dequeue and display the removed element
    q.display();  // Display the queue after dequeuing one element

    q.enqueue(6);  // Add 6 to the queue (circular behavior)
    q.display();  // Display the queue after enqueuing 6

    return 0;  // End of the program
}

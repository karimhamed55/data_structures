#include<iostream>
using namespace std;

class stack {
public:
    int top;
    int size;
    int* array;

    // Constructor to initialize the stack with given size
    stack(int size = 100) {
        this->size = size;
        this->top = -1;
        this->array = new int[size];
    }

    // Pushes an element onto the stack
    void push(int n) {
        if (isfull())
            cout << "stack overflow\n";
        else
            array[++top] = n;
    }

    // Pops the top element from the stack
    int pop() {
        if (isempty()) {
            cout << "empty stack\n";
            return -1;
        }
        return array[top--];
    }

    // Returns the top element without removing it
    int peek() {
        if (!isempty())
            return array[top];
        else {
            cout << "empty stack\n";
            return -1;
        }
    }

    // Checks if the stack is full
    bool isfull() const {
        return top == size - 1;
    }

    // Checks if the stack is empty
    bool isempty() const {
        return top == -1;
    }

    // Displays all elements in the stack
    void display() {
        if (isempty()) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << array[i] << " ";
        cout << "\n";
    }

    // Destructor to free allocated memory
    ~stack() {
        delete[] array;
    }
};

int main() {
    stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.display();

    st.pop();
    st.pop();
    st.display();

    return 0;
}

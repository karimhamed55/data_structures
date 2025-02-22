#include <iostream>
using namespace std;

struct node {
    node* next;
    int data;
    node(int data) : data(data), next(nullptr) {}
};

// Print using while loop
void print_while_loop(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Count nodes
int count_nodes(node* head) {
    int counter = 0;
    while (head != nullptr) {
        counter++;
        head = head->next;
    }
    return counter;
}

// Print using for loop
void print_for_loop(node* head) {
    node* temp = head; 
    int n = count_nodes(head);
    for (int i = 0; i < n; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Print recursively
void print_recursive(node* head) {
    if (head == nullptr) {
        cout << "\n"; 
        return;
    }
    cout << head->data << " ";
    print_recursive(head->next);
}

// Print in reverse recursively
void print3_reverse(node* head) {
    if (head == nullptr) {
        return; 
    }
    print3_reverse(head->next);
    cout << head->data << " ";
}
// search node by value function
node* search(node* head, int n)
{
    while (head!=nullptr)
    {
        if(n==head->data)
        return head;
        head = head->next;
    }
    return nullptr;
}

int main() {
    // Creating nodes
    node* node1 = new node(6);
    node* node2 = new node(8);
    node* node3 = new node(99);
    node* node4 = new node(213);

    // Linking nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr; 

    // Printing manually
    cout << node1->data << " " << node1->next->data << " " << node1->next->next->data
         << " " << node1->next->next->next->data << endl;

    // print functions 
    print_while_loop(node1);
    print_for_loop(node1);
    print_recursive(node1);
    print3_reverse(node1);
    cout << "\n";
    
    node* result = search(node1, 99);

    // Checking the result
    if (result != nullptr) {
        cout  << "found"<< endl;
    } else {
        cout  << "not found" << endl;
    }

    // Free allocated memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}

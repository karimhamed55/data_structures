#include <iostream>
using namespace std;

struct node {
    node* next;
    int data;
    node(int data) : data(data), next(nullptr) {}
};

// linked_list class
class linkedlist {
    private:
    node*head{};
    node*tail{};
    int length = 0;
    public:
    // Print using while loop
    void print_while_loop(node* head) {
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << "\n";
    }
    
    // Print using for loop
    void print_for_loop(node* head) {
      for(node* cur = head;cur;cur=cur->next)
        cout << cur->data << " ";
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
    // get_nth_item
    node* get_nth_item(int n)
    {
        int x = 0;
        for(node* cur =head;cur;cur=cur->next)
        {
            if(++x==n)
            return cur;

        }
        return nullptr;
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
 // insert at the end
    void insert_end(int n)
    {
        node* item = new node(n);
        if(!head)
        head = tail = item;
        else
        tail->next = item;
        tail = item;
    }
    // search item 
    int search(int n)
    {
        int x = 0;
        for(node* cur = head;cur;cur=cur->next,x++)
        {if (cur->data == n)
        return x;
        }
        return -1;
    }
    // search_by_shifting
    int search_improved(int n)
    {
        int x =0;
        for(node* cur = head,*prv = nullptr;cur;prv=cur,cur=cur->next,x++){
        if(cur->data == n)
     {
            if(!prv)
            return x;
            swap(prv->data,cur->data);
             return x-1;
        }   
    }
        return -1;
    }
    };
  
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

    // Free allocated memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}

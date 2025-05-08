#include <iostream>
using namespace std;

class node{
    public:
  int data{};
  node* next{};
  node(int n)
  {
      data=n;
  }
};

class stack_linked_list
{
    public:
    node*head;
    stack_linked_list()
    {
        head=nullptr;
    }
    void push(int n){
        node*item= new node(n);
        item->next=head;
        head=item;
    }
    int pop()
    {
       int element=head->data;
       node* temp=head;
       head=head->next;
       delete temp;
       return element;
    }
    int peek()
    {
        if(head)
        return head->data;
    }
    bool is_empty()
    {
        return !head;
    }
   void display() {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

};


int main() {
   
stack_linked_list st;
st.push(4);
st.push(5);
st.push(6);
st.push(7);
st.display();

   
    return 0;
}
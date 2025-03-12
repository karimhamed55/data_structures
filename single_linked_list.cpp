#include <iostream>
#include <cassert>
#include <climits>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
    int data { };
    Node* next { };
    Node(int data) : data(data) {}
    ~Node() {
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
};

class LinkedList {
private:
    Node* head { };
    Node* tail { };
    int length = 0;
    vector<Node*> debug_data;

    void debug_add_node(Node* node) {
        debug_data.push_back(node);
    }
    void debug_remove_node(Node* node) {
        auto it = find(debug_data.begin(), debug_data.end(), node);
        if (it == debug_data.end())
            cout << "Node does not exist\n";
        else
            debug_data.erase(it);
    }

public:
    LinkedList() {}
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // Debug and utility functions
    void debug_print_address() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur << "," << cur->data << "\t";
        cout << "\n";
    }

    void debug_verify_data_integrity() {
        if (length == 0) {
            assert(head == nullptr);
            assert(tail == nullptr);
            return;
        }
        assert(head != nullptr);
        assert(tail != nullptr);
        assert(tail->next == nullptr);
        if (length == 1)
            assert(head == tail);
        else {
            assert(head != tail);
            if (length == 2)
                assert(head->next == tail);
            else if (length == 3)
                assert(head->next && head->next->next == tail);
        }
        int len = 0;
        for (Node* cur = head; cur; cur = cur->next, len++)
            assert(len < 10000);
        assert(length == len);
        assert(length == (int)debug_data.size());
    }

    // Basic operations
    void print() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    void insert_end(int value) {
        Node* item = new Node(value);
        debug_add_node(item);
        length++;
        
        if (!head)
            head = tail = item;
        else
            tail->next = item, tail = item;
        
        debug_verify_data_integrity();
    }

    // Get nth node (1-based index)
    Node* get_nth(int n) {
        int cnt = 1;
        for (Node* cur = head; cur; cur = cur->next, cnt++) {
            if (cnt == n)
                return cur;
        }
        return nullptr;
    }

    // Delete nth node from the list (1-based index)
    void delete_from_middle(int n) {
        if (n < 1 || n > length) {
            cout << "Error. No such nth node\n";
            return;
        }
        else if (n == 1) {
            delete_front();
        }
        else {
            // Get the node before nth
            Node* previous = get_nth(n - 1);
            Node* current = previous->next;
            bool is_tail = current == tail;
            
            // Link previous node to the one after current
            previous->next = current->next;
            if (is_tail)
                tail = previous;

            delete current;
            length--;
            debug_verify_data_integrity();
        }
    }

    // Delete the first node in the list
    void delete_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
        if (length == 0)
            tail = nullptr;
    }

    // Utility functions
    int get_length() const {
        return length;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.insert_end(10);
    list.insert_end(20);
    list.insert_end(30);
    list.insert_end(40);
    list.print();

    list.delete_from_middle(2); // Delete second node (20)
    list.print();

    return 0;
}

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

    // Enhanced functions from first code
    Node* get_nth(int n) {
        int cnt = 0;
        for (Node* cur = head; cur; cur = cur->next)
            if (++cnt == n)
                return cur;
        return nullptr;
    }

    Node* search(int value) {
        for (Node* cur = head; cur; cur = cur->next)
            if (cur->data == value)
                return cur;
        return nullptr;
    }

    int search_index(int value) {
        int idx = 0;
        for (Node* cur = head; cur; cur = cur->next, idx++)
            if (cur->data == value)
                return idx;
        return -1;
    }

    int search_improved(int value) {
        int idx = 0;
        for (Node *cur = head, *prev = nullptr; cur; prev = cur, cur = cur->next, idx++) {
            if (cur->data == value) {
                if (!prev) return idx; // Already head
                swap(prev->data, cur->data);
                return idx - 1;
            }
        }
        return -1;
    }

    int add_from_front ( int n)
    {
        if(head==nullptr)
        return -1;
        else 
        {
            Node* temp = new Node(n);
            temp->next = head;
            head = temp;
            delete temp;
            return 0;
        }
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

    return 0;
}
#include <iostream>
#include <cassert>
using namespace std;

class vector {
private:
    int* arr = nullptr;
    int size = 0;
    int capacity = 10;;
public:
    vector(int initial_size) : size(initial_size) {
        if (size < 1) size = 1;
        capacity = size+10;
        arr = new int[size]{};
    } // constructor
    
    ~vector() {
        delete[] arr;
        arr = nullptr;
    } // destructor

    
    int get(int idx) {
        assert(0 <= idx && idx < size);
        return arr[idx];
    }

    void set(int idx, int val) {
        assert(0 <= idx && idx < size);
        arr[idx] = val;
    }
// print function
    void print() {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
// find an integer function
    int find(int value) {
        for(int i = 0; i < size; i++) {
            if(arr[i] == value)
                return i;
        }
        return -1;  
    }
    // push back function and solution for overflowing
     void push_back(int n)
    {
         if(size==capacity)
         expand_capacity();
         arr[size++]= n;
    }
    void expand_capacity()
    {
        capacity*=2;
        int *arr2 = new int[capacity]{};
        for(int i =0;i<size;i++)
        arr2[i]=arr[i];
        swap(arr,arr2);
        delete[] arr2;
    }
    // insert function
     void insert (int idx,int value)
    {
        assert(0<=idx && idx<size);
        if(size == capacity)
        expand_capacity();
        for(int i =size-1;i>=idx;i--)
        arr[i+1]= arr[i];
        arr[idx]=value;
        size++;
    }
};

int main() {
    vector v(10);  
    for(int i = 0; i < 10; i++)
        v.set(i, i);
    v.print();
    cout << v.find(5) << " " << v.find(55);
    v.push_back(888);
    v.print();
    return 0;
}
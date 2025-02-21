#include <iostream>
#include <vector>
using namespace std;

/*
🚀 Welcome to the "Asymptotic Complexity" Showcase! 🚀

In this program, you'll explore different complexities - from O(1) (constant time)
to O(N!) (factorial time) - with **real C++ implementations**. Understanding how
code scales is crucial for writing efficient programs.

Let's dive in! 🎯
*/

// 📌 O(1) - Constant Time Complexity
void constantTime(int arr[], int n) {
    cout << "First element: " << arr[0] << endl; // Always executes in constant time
}

// 📌 O(log N) - Logarithmic Time Complexity (Binary Search)
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// 📌 O(N) - Linear Time Complexity (Linear Search)
void linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

// 📌 O(N²) - Quadratic Time Complexity (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 📌 O(2^N) - Exponential Time Complexity (Recursive Fibonacci)
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 📌 O(N!) - Factorial Time Complexity (Generating Permutations)
void permute(vector<int>& nums, int l, int r) {
    if (l == r) {
        for (int num : nums) cout << num << " ";
        cout << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(nums[l], nums[i]);
            permute(nums, l + 1, r);
            swap(nums[l], nums[i]); // Backtrack
        }
    }
}

/*
💾 Space Complexity Considerations 💾

Just like time complexity, memory usage matters! 
Here’s a breakdown of memory complexities:

- O(1)  → Constant space (e.g., swapping variables)
- O(N)  → Linear space (e.g., using an array of size N)
- O(N²) → Quadratic space (e.g., adjacency matrix in graphs)
- O(2^N) → Exponential space (e.g., recursive calls in Fibonacci)
*/

// Main function to test everything!
int main() {
    cout << "\n🚀 Asymptotic Complexity Demonstration 🚀\n" << endl;

    // Test O(1) - Constant Time
    int arr[] = {10, 20, 30, 40, 50};
    constantTime(arr, 5);

    // Test O(log N) - Binary Search
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    cout << "Binary Search index: " << binarySearch(arr, 0, size - 1, target) << endl;

    // Test O(N) - Linear Search
    linearSearch(arr, size, 40);

    // Test O(N²) - Bubble Sort
    int unsortedArr[] = {5, 3, 8, 4, 2};
    int arrSize = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
    bubbleSort(unsortedArr, arrSize);
    cout << "Sorted array: ";
    for (int num : unsortedArr) cout << num << " ";
    cout << endl;

    // Test O(2^N) - Fibonacci
    cout << "Fibonacci(6): " << fibonacci(6) << endl;

    // Test O(N!) - Permutations
    vector<int> nums = {1, 2, 3};
    cout << "All permutations of {1,2,3}:" << endl;
    permute(nums, 0, nums.size() - 1);

    cout << "\n🎉 Done! Now you know how different complexities affect performance! 🎉\n";

    return 0;
}

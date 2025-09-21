#include "sort.h"
#include <iostream>
using namespace std;

void display(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << i + 1 << " element is " << arr[i] << endl;
    }
}

void initialise(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        int x; cin >> x;
        arr.push_back(x);
    }
}

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    vector<int> arr;
    initialise(arr, size);
    display(arr);

    int choice;
    cout << "\nEnter\n1. Insertion\n2. Selection\n3. BubbleSort\n4. MergeSort\n5. QuickSort\n\nChoice: ";
    cin >> choice;

    switch (choice) {
        case 1: insertion(arr); break;
        case 2: selection(arr); break;
        case 3: bubblesort(arr); break;
        case 4: mergesort(arr, 0, size - 1); display(arr); break;
        case 5: quicksort(arr, 0, size - 1); display(arr); break;
        default: cout << "Invalid choice!\n"; return 0;
    }

    int target;
    cout << "\nEnter target number: ";
    cin >> target;

    int choice2;
    cout << "\nEnter\n1. Linear Search\n2. Binary Search\nChoice: ";
    cin >> choice2;

    switch (choice2) {
        case 1: linear(arr, target); break;
        case 2: binary(arr, 0, size - 1, target); break;
        default: cout << "Invalid choice!\n"; break;
    }

    return 0;
}

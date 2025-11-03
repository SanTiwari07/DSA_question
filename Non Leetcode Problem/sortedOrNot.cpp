#include <iostream>
#include <vector>

using namespace std;

bool isSorted(const vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false; 
        }
    }
    return true; 
}

void displayArray(const vector<int>& arr) {
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    cout << "--- Check Given Array Is Sorted or Not ---" << endl;

    vector<int> sorted_arr = {1, 5, 10, 15, 20};
    cout << "Array 1: ";
    displayArray(sorted_arr);
    if (isSorted(sorted_arr)) {
        cout << "Result: Array is SORTED." << endl;
    } else {
        cout << "Result: Array is NOT sorted." << endl;
    }

    vector<int> unsorted_arr = {1, 15, 5, 20, 10};
    cout << "\nArray 2: ";
    displayArray(unsorted_arr);
    if (isSorted(unsorted_arr)) {
        cout << "Result: Array is SORTED." << endl;
    } else {
        cout << "Result: Array is NOT sorted." << endl;
    }

    return 0;
}

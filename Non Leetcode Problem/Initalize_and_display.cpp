#include <iostream>
#include <vector>

using namespace std;


void displayArray(const vector<int>& arr) {
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;
}


int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
    
            return i;
        }
    }

    return -1;
}

int main() {
    cout << "--- Initialize, Display, and Linear Search ---" << endl;

    vector<int> numbers = {10, 5, 20, 8, 15};
    int target = 8;

    cout << "Array elements: ";
    displayArray(numbers);

    cout << "Searching for target: " << target << endl;
    
    int index = linearSearch(numbers, target);

    if (index != -1) {
        cout << "Element " << target << " found at index: " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }
    
    target = 99;
    cout << "\nSearching for target: " << target << endl;
    index = linearSearch(numbers, target);

    if (index != -1) {
        cout << "Element " << target << " found at index: " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }


    return 0;
}

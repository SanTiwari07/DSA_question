#include <iostream>
#include "sort.h"
using namespace std;

void initialise(int arr[], int n) {
    for (int a = 0; a < n; a++) {
        cout << "Enter " << a + 1 << " element: ";
        cin >> arr[a];
    }
}
void display(int arr[], int n) {
    for (int a = 0; a < n; a++) {
        cout << arr[a] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;
    int arr[size];

    initialise(arr, size);
    display(arr, size);

    int choice;
    cout << "Enter\n1. Insertion\n2. Selection\n3. BubbleSort\n4. MergeSort\n5. Quick Sort\nChoice: ";
    cin >> choice;

    switch (choice) {
        case 1: insertion(arr, size); break;
        case 2: selection(arr, size); break;
        case 3: bubblesort(arr, size); break;
        case 4: merge(arr, size, 0, size - 1); display(arr, size); break;
        case 5: quicksort(arr, 0, size - 1); display(arr, size); break;
        default: cout << "Invalid choice!" << endl;
    }

    int target, choice2;
    cout << "Enter target: ";
    cin >> target;
    cout << "Enter\n1. Linear Search\n2. Binary Search\nChoice: ";
    cin >> choice2;

    if (choice2 == 1) linear(arr, size, target);
    else binary(arr, 0, size - 1, target);

    return 0;
}

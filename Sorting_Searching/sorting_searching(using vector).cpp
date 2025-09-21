#include <iostream>
#include <vector>
using namespace std;

// Function to initialize vector
void initialise(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        int x;
        cin >> x;
        arr.push_back(x);
    }
}

// Function to display vector
void display(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << i + 1 << " element is " << arr[i] << endl;
    }
}

// Bubble sort
void bubblesort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    display(arr);
}

// Insertion sort
void insertion(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    display(arr);
}

// Selection sort
void selection(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    display(arr);
}

// Merge helper
void combine(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge sort
void mergesort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        combine(arr, left, mid, right);
    }
}

// Partition for quicksort
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// Quick sort
void quicksort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);
        quicksort(arr, left, p - 1);
        quicksort(arr, p + 1, right);
    }
}

// Linear search
int linear(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            cout << "Found the number at index: " << i << endl;
            return i;
        }
    }
    cout << "Not Found!" << endl;
    return -1;
}

// Binary search
int binary(const vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            cout << "Number found at index: " << mid << endl;
            return mid;
        }
        else if (arr[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    cout << "Not Found!" << endl;
    return -1;
}

// Main
int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    vector<int> arr;
    initialise(arr, size);
    display(arr);

    int choice;
    cout << "\nEnter\n1. Insertion\n2. Selection\n3. BubbleSort\n4. MergeSort\n5. Quick Sort\n\nEnter choice: ";
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
    cout << "\nEnter Target number: ";
    cin >> target;

    int choice2;
    cout << "\nEnter\n1. Linear Search\n2. Binary Search\n\nEnter choice: ";
    cin >> choice2;

    switch (choice2) {
        case 1: linear(arr, target); break;
        case 2: binary(arr, 0, size - 1, target); break;
        default: cout << "Invalid choice!\n"; break;
    }

    return 0;
}

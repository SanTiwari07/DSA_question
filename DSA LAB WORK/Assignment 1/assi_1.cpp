#include <iostream>
using namespace std;

// 🧱 Initialize array
void initialise(int arr[], int n) {
    for (int a = 0; a < n; a++) {
        cout << "Enter " << a + 1 << " element: ";
        cin >> arr[a];
    }
}

// 🧱 Display array
void display(int arr[], int n) {
    cout << "\nArray elements: ";
    for (int a = 0; a < n; a++) {
        cout << arr[a] << " ";
    }
    cout << endl;
}

// 🌀 Bubble Sort
void bubblesort(int arr[], int n) {
    for (int a = 0; a < n - 1; a++) {
        for (int b = 0; b < n - 1 - a; b++) {
            if (arr[b] > arr[b + 1]) {
                swap(arr[b], arr[b + 1]);
            }
        }
    }
    cout << "\nArray after Bubble Sort:\n";
    display(arr, n);
}

// 📘 Insertion Sort
void insertion(int arr[], int n) {
    for (int a = 1; a < n; a++) {
        int sample = arr[a];
        int number = a - 1;
        while (number >= 0 && arr[number] > sample) {
            arr[number + 1] = arr[number];
            number--;
        }
        arr[number + 1] = sample;
    }
    cout << "\nArray after Insertion Sort:\n";
    display(arr, n);
}

// 📗 Selection Sort
void selection(int arr[], int n) {
    for (int a = 0; a < n - 1; a++) {
        int minIndex = a;
        for (int b = a + 1; b < n; b++) {
            if (arr[b] < arr[minIndex]) {
                minIndex = b;
            }
        }
        swap(arr[a], arr[minIndex]);
    }
    cout << "\nArray after Selection Sort:\n";
    display(arr, n);
}

// 🔹 Merge Sort
void combine(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        arr2[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }

    while (i < n1)
        arr[k++] = arr1[i++];
    while (j < n2)
        arr[k++] = arr2[j++];
}

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        combine(arr, left, mid, right);
    }
}

// 🔸 Quick Sort
int partition(int arr[], int left, int right) {
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

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);
        quicksort(arr, left, p - 1);
        quicksort(arr, p + 1, right);
    }
}

// 🔍 Linear Search
int linear(int arr[], int n, int target) {
    for (int a = 0; a < n; a++) {
        if (arr[a] == target) {
            cout << "Found the number at index: " << a << endl;
            return a;
        }
    }
    cout << "Not Found!" << endl;
    return -1;
}

// 🔍 Binary Search (works only on sorted arrays)
int binary(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            cout << "Number found at index: " << mid << endl;
            return mid;
        } else if (arr[mid] > target)
            return binary(arr, left, mid - 1, target);
        else
            return binary(arr, mid + 1, right, target);
    }
    cout << "Not Found!" << endl;
    return -1;
}

// 🚀 Main Function
int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];
    initialise(arr, size);
    display(arr, size);

    int choice;
    cout << "\nEnter Sorting Choice:\n"
         << "1. Insertion Sort\n"
         << "2. Selection Sort\n"
         << "3. Bubble Sort\n"
         << "4. Merge Sort\n"
         << "5. Quick Sort\n"
         << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: insertion(arr, size); break;
        case 2: selection(arr, size); break;
        case 3: bubblesort(arr, size); break;
        case 4:
            mergesort(arr, 0, size - 1);
            cout << "\nArray after Merge Sort:\n";
            display(arr, size);
            break;
        case 5:
            quicksort(arr, 0, size - 1);
            cout << "\nArray after Quick Sort:\n";
            display(arr, size);
            break;
        default:
            cout << "Invalid choice!\n";
    }

    int target, choice_2;
    cout << "\nEnter Target number to search: ";
    cin >> target;
    cout << "\nEnter Search Choice:\n"
         << "1. Linear Search\n"
         << "2. Binary Search\n"
         << "Enter choice: ";
    cin >> choice_2;

    switch (choice_2) {
        case 1: linear(arr, size, target); break;
        case 2: binary(arr, 0, size - 1, target); break;
        default: cout << "Invalid choice!\n";
    }

    return 0;
}

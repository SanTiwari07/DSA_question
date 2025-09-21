// write a c++ program to sort given data element in ascending order using bubble , quick and merge sort. Search any element in given dataset using linear and binary search.
#include <iostream>
using namespace std;
void initialise(int arr[], int n)
{
    for (int a = 0; a < n; a++)
    {
        cout << "Enter " << a + 1 << " element: ";
        cin >> arr[a];
    }
}
void display(int arr[], int n)
{
    for (int a = 0; a < n; a++)
    {
        cout << a + 1 << " element is " << arr[a] << endl;
    }
}
void bubblesort(int arr[], int n)
{
    for (int a = 0; a < n - 1; a++)
    {
        for (int b = 0; b < n - 1 - a; b++)
        {
            if (arr[b] > arr[b + 1])
            {
                swap(arr[b], arr[b + 1]);
            }
        }
    }
    display(arr, n);
}
void insertion(int arr[], int n)
{
    for (int a = 1; a < n; a++)
    {
        int sample = arr[a];
        int number = a - 1;
        while (number >= 0 && arr[number] > sample)
        {
            arr[number + 1] = arr[number];
            number--;
        }
        arr[number + 1] = sample;
    }
    display(arr, n);
}
void selection(int arr[], int n)
{
    int min = arr[0];
    for (int a = 0; a < n; a++)
    {
        for (int b = a; b < n; b++)
        {
            if (arr[a] > arr[b])
            {
                swap(arr[a], arr[b]);
            }
        }
    }
    display(arr, n);
}
void combine(int arr[], int n, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int arr1[n1], arr2[n2];
    for (int a = 0; a < n1; a++)
    {
        arr1[a] = arr[left + a];
    }
    for (int a = 0; a < n2; a++)
    {
        arr2[a] = arr[mid + 1 + a];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = arr1[i++];
    }
    while (i < n2)
    {
        arr[k++] = arr2[j++];
    }
}
void merge(int arr[], int n, int left, int right)
{
    int mid = (left + right) / 2;
    if (left < right)
    {

        merge(arr, n, left, mid);
        merge(arr, n, mid + 1, right);
    }
    combine(arr, n, left, mid, right);
}
int quick_2(int arr[], int left, int right)
{
    int pivot = arr[left];
    int counter = 0;
    for (int a = left + 1; a <= right; a++)
    {
        if (pivot > arr[a])
        {
            counter++;
        }
    }
    int p = left + counter;
    swap(arr[p], arr[left]);
    int i = left;
    int j = right;
    while (i < p && j > p)
    {
        while (arr[i] > pivot)
        {
            i++;
        }
        while (arr[j] < pivot)
        {
            j--;
        }
        swap(arr[i], arr[j]);
    }
    return p;
}
void quicksort(int arr[], int left, int right)
{
    if (left < right)
    {
        int p = quick_2(arr, left, right);
        quicksort(arr, left, p - 1);
        quicksort(arr, p + 1, right);
    }
}
int binary(int arr[], int left, int right, int target)
{
    int mid = (left + right) / 2;
    if (left <= right)
    {

        if (arr[mid] == target)
        {
            cout << "Number found at the index: "<<mid<<endl;
            return mid;
        }
        else if (arr[mid] > target)
        {
            binary(arr, left, mid - 1, target);
        }
        else if (arr[mid] < target)
        {
            binary(arr, mid + 1, right, target);
        }
    }
    else{
        cout << "not found!";
    }
    return 0;
}
int linear(int arr[], int n, int target)
{
    for (int a = 0; a < n; a++)
    {
        if (arr[a] == target)
        {
            cout << "Found the number at index: "<<a<<endl;
            return a;
        }
    }
    cout << "Not Found!" << endl;
    return 0;
}
int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    int arr[size];
    initialise(arr, size);
    display(arr, size);
    int choice;
    cout << "Enter\n1. Insertion\n2. Selection\n3. BubbleSort\n4. MergeSort\n5. Quick Sort\n\nEnter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        insertion(arr, size);
        break;

    case 2:
        selection(arr, size);
        break;

    case 3:
        bubblesort(arr, size);
        break;

    case 4:
        merge(arr, size, 0, size - 1);
        display(arr, size);
        break;
    case 5:
        quicksort(arr, 0, size - 1);
        display(arr, size);
        break;
    }

    cout << "Enter Target number: ";
    int target;
    cin >> target;
    int choice_2;
    cout << endl
         << "Enter\n1.Linear Search\n2.Binary search\n\nEnter choice: ";
    cin >> choice_2;
    switch (choice_2)
    {
    case 1:
        return linear(arr, size, target);
        break;
    case 2:
        return binary(arr, 0, size - 1, target);
        break;
    }
}

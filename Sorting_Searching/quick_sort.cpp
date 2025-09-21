#include <iostream>
#include "sort.h"
using namespace std;

int quick_2(int arr[], int left, int right) {
    int pivot = arr[left];
    int counter = 0;
    for (int a = left + 1; a <= right; a++) {
        if (pivot > arr[a]) counter++;
    }
    int p = left + counter;
    swap(arr[p], arr[left]);

    int i = left, j = right;
    while (i < p && j > p) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < p && j > p) swap(arr[i++], arr[j--]);
    }
    return p;
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int p = quick_2(arr, left, right);
        quicksort(arr, left, p - 1);
        quicksort(arr, p + 1, right);
    }
}

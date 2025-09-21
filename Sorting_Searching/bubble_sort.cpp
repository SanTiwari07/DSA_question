#include <iostream>
#include "sort.h"
using namespace std;

void bubblesort(int arr[], int n) {
    for (int a = 0; a < n - 1; a++) {
        for (int b = 0; b < n - 1 - a; b++) {
            if (arr[b] > arr[b + 1]) {
                swap(arr[b], arr[b + 1]);
            }
        }
    }
    display(arr, n);
}

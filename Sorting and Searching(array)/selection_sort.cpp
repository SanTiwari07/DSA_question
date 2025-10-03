#include <iostream>
#include "sort.h"
using namespace std;

void selection(int arr[], int n) {
    for (int a = 0; a < n - 1; a++) {
        int minIndex = a;  // assume current is min
        for (int b = a + 1; b < n; b++) {
            if (arr[b] < arr[minIndex]) {
                minIndex = b;  // found smaller element
            }
        }
        // Swap only once after finding minimum
        swap(arr[a], arr[minIndex]);
    }
    display(arr, n);
}
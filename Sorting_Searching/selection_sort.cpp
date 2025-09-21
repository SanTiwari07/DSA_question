#include <iostream>
#include "sort.h"
using namespace std;

void selection(int arr[], int n) {
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            if (arr[a] > arr[b]) {
                swap(arr[a], arr[b]);
            }
        }
    }
    display(arr, n);
}

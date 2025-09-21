#include <iostream>
#include "sort.h"
using namespace std;

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
    display(arr, n);
}
    
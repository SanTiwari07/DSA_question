#include <iostream>
#include "sort.h"
using namespace std;

int linear(int arr[], int n, int target) {
    for (int a = 0; a < n; a++) {
        if (arr[a] == target) {
            cout << "Found at index: " << a << endl;
            return a;
        }
    }
    cout << "Not Found!" << endl;
    return -1;
}

int binary(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            cout << "Found at index: " << mid << endl;
            return mid;
        } else if (arr[mid] > target) {
            return binary(arr, left, mid - 1, target);
        } else {
            return binary(arr, mid + 1, right, target);
        }
    }
    cout << "Not Found!" << endl;
    return -1;
}

#include "sort.h"
#include <iostream>
using namespace std;

int linear(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            cout << "Found at index: " << i << endl;
            return i;
        }
    }
    cout << "Not Found!" << endl;
    return -1;
}

int binary(const vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            cout << "Found at index: " << mid << endl;
            return mid;
        } else if (arr[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    cout << "Not Found!" << endl;
    return -1;
}

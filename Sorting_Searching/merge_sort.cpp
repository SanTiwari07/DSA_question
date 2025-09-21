#include <iostream>
#include "sort.h"
using namespace std;

void combine(int arr[], int n, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int arr1[n1], arr2[n2];

    for (int a = 0; a < n1; a++) arr1[a] = arr[left + a];
    for (int a = 0; a < n2; a++) arr2[a] = arr[mid + 1 + a];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) arr[k++] = arr1[i++];
        else arr[k++] = arr2[j++];
    }
    while (i < n1) arr[k++] = arr1[i++];
    while (j < n2) arr[k++] = arr2[j++];
}

void merge(int arr[], int n, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge(arr, n, left, mid);
        merge(arr, n, mid + 1, right);
        combine(arr, n, left, mid, right);
    }
}

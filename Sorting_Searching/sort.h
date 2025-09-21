#ifndef SORT_H
#define SORT_H

void initialise(int arr[], int n);
void display(int arr[], int n);

// Sorting
void bubblesort(int arr[], int n);
void insertion(int arr[], int n);
void selection(int arr[], int n);
void merge(int arr[], int n, int left, int right);
void quicksort(int arr[], int left, int right);

// Searching
int linear(int arr[], int n, int target);
int binary(int arr[], int left, int right, int target);

#endif

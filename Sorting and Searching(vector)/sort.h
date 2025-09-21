#ifndef SORT_H
#define SORT_H

#include <vector>
using namespace std;

// Sorting
void bubblesort(vector<int>& arr);
void insertion(vector<int>& arr);
void selection(vector<int>& arr);
void mergesort(vector<int>& arr, int left, int right);
void quicksort(vector<int>& arr, int left, int right);

// Searching
int linear(const vector<int>& arr, int target);
int binary(const vector<int>& arr, int left, int right, int target);

// Utility
void display(const vector<int>& arr);
void initialise(vector<int>& arr, int n);

#endif

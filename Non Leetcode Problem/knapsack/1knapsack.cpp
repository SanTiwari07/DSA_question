#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive function to solve 0/1 Knapsack
int knapsackRecursive(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // Base case: If no items left or knapsack capacity is 0
    if (n == 0 || W == 0) {
        return 0;
    }

    // If the weight of the nth item is more than the capacity W, 
    // this item cannot be included. Check the remaining n-1 items.
    if (weights[n - 1] > W) {
        return knapsackRecursive(W, weights, values, n - 1);
    }
    
    // Otherwise, there are two possibilities:
    
    // 1. Include the nth item: value[n-1] + recurse with reduced capacity (W - weights[n-1])
    int included = values[n - 1] + knapsackRecursive(W - weights[n - 1], weights, values, n - 1);
    
    // 2. Exclude the nth item: recurse with the same capacity W
    int excluded = knapsackRecursive(W, weights, values, n - 1);

    // Return the maximum of the two possibilities
    return max(included, excluded);
}

int main() {
    cout << "--- 0/1 Knapsack Problem using Recursive Solution ---" << endl;

    vector<int> values = {60, 100, 120}; // Value of items
    vector<int> weights = {10, 20, 30};  // Weight of items
    int W = 50;                         // Knapsack capacity
    int n = values.size();              // Number of items

    cout << "Knapsack Capacity (W): " << W << endl;
    cout << "Items (Weight, Value): (10, 60), (20, 100), (30, 120)" << endl;

    int max_value = knapsackRecursive(W, weights, values, n);

    cout << "Maximum value in Knapsack: " << max_value << endl; 
    // Expected: 220 (100 + 120, by taking items of weight 20 and 30)

    return 0;
}

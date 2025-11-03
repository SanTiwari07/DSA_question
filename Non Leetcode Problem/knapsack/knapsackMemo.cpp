#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Memoization table (DP table)
// dp[i][j] stores the max value using first 'i' items with capacity 'j'
vector<vector<int>> memo;

// Memoized recursive function
int knapsackMemoization(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // Base case
    if (n == 0 || W == 0) {
        return 0;
    }

    // Check if the result is already computed and stored
    if (memo[n][W] != -1) {
        return memo[n][W];
    }

    // If weight of the nth item is more than the capacity W, exclude it
    if (weights[n - 1] > W) {
        // Store and return the result of excluding
        return memo[n][W] = knapsackMemoization(W, weights, values, n - 1);
    }
    
    // Otherwise, compute and store the max of (included, excluded)
    // 1. Included
    int included = values[n - 1] + knapsackMemoization(W - weights[n - 1], weights, values, n - 1);
    
    // 2. Excluded
    int excluded = knapsackMemoization(W, weights, values, n - 1);

    return memo[n][W] = max(included, excluded);
}

int main() {
    cout << "--- 0/1 Knapsack Problem using Memoization (Top-Down DP) ---" << endl;

    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();

    cout << "Knapsack Capacity (W): " << W << endl;
    cout << "Items (Weight, Value): (10, 60), (20, 100), (30, 120)" << endl;

    // Initialize memo table with -1 (n+1 rows for items, W+1 columns for capacity)
    memo.assign(n + 1, vector<int>(W + 1, -1));

    int max_value = knapsackMemoization(W, weights, values, n);

    cout << "Maximum value in Knapsack: " << max_value << endl;

    return 0;
}

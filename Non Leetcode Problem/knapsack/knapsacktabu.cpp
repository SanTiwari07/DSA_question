#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve 0/1 Knapsack using Tabulation (Bottom-Up DP)
int knapsackTabulation(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // dp[i][w] will store the maximum value with first 'i' items and capacity 'w'
    // Size: (n+1) rows, (W+1) columns
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Fill the DP table
    for (int i = 0; i <= n; ++i) { // i represents the number of items considered (1 to n)
        for (int w = 0; w <= W; ++w) { // w represents the current capacity
            
            // Base case: If no items (i=0) or zero capacity (w=0), max value is 0
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } 
            // Case 1: If the weight of the current item (i-1) can fit in the knapsack
            else if (weights[i - 1] <= w) {
                // dp[i][w] is the maximum of:
                // 1. Including the current item: values[i-1] + value from remaining capacity
                // 2. Excluding the current item: value without the current item
                dp[i][w] = max(
                    values[i - 1] + dp[i - 1][w - weights[i - 1]], // Included
                    dp[i - 1][w]                                   // Excluded
                );
            } 
            // Case 2: If the item's weight is more than the current capacity, exclude it
            else {
                dp[i][w] = dp[i - 1][w]; // Same as the max value without this item
            }
        }
    }

    // The final answer is in the bottom-right corner of the DP table
    return dp[n][W];
}

int main() {
    cout << "--- 0/1 Knapsack Problem using Tabulation (Bottom-Up DP) ---" << endl;

    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();

    cout << "Knapsack Capacity (W): " << W << endl;
    cout << "Items (Weight, Value): (10, 60), (20, 100), (30, 120)" << endl;

    int max_value = knapsackTabulation(W, weights, values, n);

    cout << "Maximum value in Knapsack: " << max_value << endl;

    return 0;
}

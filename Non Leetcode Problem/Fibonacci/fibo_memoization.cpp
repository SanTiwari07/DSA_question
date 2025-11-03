#include <iostream>
#include <vector>

using namespace std;

// Memoization (Top-Down DP) approach for Fibonacci
// dp array is used to store results of subproblems
int fib_memo(int n, vector<int>& dp) {
    if (n <= 1) {
        return n;
    }
    
    // Check if the result for n is already computed
    if (dp[n] != -1) {
        return dp[n];
    }
    
    // Compute and store the result
    dp[n] = fib_memo(n - 1, dp) + fib_memo(n - 2, dp);
    return dp[n];
}

int main() {
    cout << "--- Fibonacci Series using DP (Memoization) ---" << endl;

    int n = 10;
    // Initialize a vector to store results, filled with -1 (indicating not computed)
    // Size is n + 1 because we need indices from 0 up to n
    vector<int> dp(n + 1, -1); 

    int result = fib_memo(n, dp);

    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    
    // Display the series (optional)
    cout << "Fibonacci Series up to " << n << ":" << endl;
    for(int i = 0; i <= n; ++i) {
        // The values are now stored in the dp array
        cout << dp[i] << (i == n ? "" : ", ");
    }
    cout << endl;

    return 0;
}

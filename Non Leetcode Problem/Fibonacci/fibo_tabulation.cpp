#include <iostream>
#include <vector>

using namespace std;

// Tabulation (Bottom-Up DP) approach for Fibonacci
int fib_tabulation(int n) {
    if (n <= 1) {
        return n;
    }

    // Create a vector (DP table) to store results
    vector<int> dp(n + 1);

    // Base cases
    dp[0] = 0;
    dp[1] = 1;

    // Fill the table starting from the base cases up to n
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    // Display the series (optional)
    cout << "Fibonacci Series up to " << n << ":" << endl;
    for(int i = 0; i <= n; ++i) {
        cout << dp[i] << (i == n ? "" : ", ");
    }
    cout << endl;

    // The result is the last element computed
    return dp[n];
}

int main() {
    cout << "--- Fibonacci Series using DP (Tabulation) ---" << endl;

    int n = 10;

    int result = fib_tabulation(n);

    cout << "The " << n << "th Fibonacci number is: " << result << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class DPAppl {
public:
    int LCS(string a, string b) {
        int n = a.size(); 
        int m = b.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
    
    int LIS(vector<int> arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);
        int ans = 1;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};

int main() {
    
    DPAppl dp;
    int ch;
    
    while(1) {
        cout << endl;
        cout << "1. DNA Sequence Matching (LCS)" << endl;
        cout << "2. Stock Market Analysis (LIS)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        
        if (!(cin >> ch)) {
            cout << "Invalid input. Exiting." << endl;
            break;
        }

        if(ch == 1) {
            string s1, s2;
            cout << "Enter first DNA sequence: ";
            cin >> s1;
            cout << "Enter second DNA sequence: ";
            cin >> s2;
            
            int l = dp.LCS(s1, s2);
            cout << "Length of Longest Common Subsequence: " << l << endl;
            cout << "---" << endl;
            cout << "Real-world application: Finding sequence similarities between two DNA strands (bioinformatics)." << endl;
        } 
        else if(ch == 2) {
            int n;
            cout << "Enter number of days: ";
            if (!(cin >> n) || n <= 0) {
                 cout << "Invalid number of days." << endl;
                 continue;
            }
            
            vector<int> prices(n);
            cout << "Enter " << n << " stock prices: ";
            for(int i = 0; i < n; i++) {
                cin >> prices[i];
            }
            
            int len = dp.LIS(prices);
            cout << "Longest period of increasing prices: " << len << " days/steps." << endl;
            cout << "---" << endl;
            cout << "Real-world application: Analyzing investment opportunities and trend duration in finance." << endl;
        } 
        else if(ch == 3) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }
    
    return 0;
}
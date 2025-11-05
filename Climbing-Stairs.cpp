// Top-Down Dynamic Programming (Memoization)
class Solution {
public:
    int dfs(int n, vector<int>& dp){
        if(n<=2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = dfs(n-1, dp) + dfs(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return dfs(n, dp);
    }
};



// Bottom-Up DP (Tabulation)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // Base cases: if there are 1 or 2 steps
        if (n <= 2) return n;

        // dp[i] = number of ways to reach step i
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;

        // Build the dp table from 3 → n
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // The result is the number of ways to reach step n
        return dp[n];
    }
};

// ---- Demo driver ----
int main() {
    Solution sol;

    int n1 = 2;
    cout << "Input: " << n1 << " → Output: " << sol.climbStairs(n1) << endl; // Expected: 2

    int n2 = 3;
    cout << "Input: " << n2 << " → Output: " << sol.climbStairs(n2) << endl; // Expected: 3

    int n3 = 5;
    cout << "Input: " << n3 << " → Output: " << sol.climbStairs(n3) << endl; // Expected: 8

    return 0;
}



// Space-Optimized
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1,-1);
        int prev1 = 1;
        int prev2 = 2;

        for(int i=3; i<=n; i++){
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};

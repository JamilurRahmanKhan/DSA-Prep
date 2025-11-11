// ? Brute Force
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPaths(int b, int r, int m, int n) {
        // Out of bounds
        if (b >= m || r >= n) return 0;
        // Reached destination
        if (b == m - 1 && r == n - 1) return 1;

        // Move right + Move down
        int right = countPaths(b, r + 1, m, n);
        int down  = countPaths(b + 1, r, m, n);

        return right + down;
    }

    int uniquePaths(int m, int n) {
        return countPaths(0, 0, m, n);
    }
};

int main() {
    Solution sol;
    cout << sol.uniquePaths(3, 6);  // Output: 21
}



// ? DP space-optimized
int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);                // row of counts; first row = all 1s
    for (int r = 1; r < m; ++r)
        for (int c = 1; c < n; ++c)
            dp[c] += dp[c-1];            // dp[c] (up) + dp[c-1] (left)
    return dp.back();
}

//? Brute Force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int>& cost, int i) {
        int n = cost.size();
        if (i >= n) return 0; // Base case: reached or passed top
        return cost[i] + min(solve(cost, i + 1), solve(cost, i + 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(cost, 0), solve(cost, 1));
    }
};

int main() {
    Solution sol;
    vector<int> cost = {1, 2, 1, 2, 1, 1, 1};
    cout << sol.minCostClimbingStairs(cost);
}



//?Top Down
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int>& cost, int i, vector<int>& dp) {
        int n = cost.size();
        if (i >= n) return 0;             // Base case
        if (dp[i] != -1) return dp[i];    // Already computed → reuse it

        // Store and return the min cost from this step onward
        return dp[i] = cost[i] + min(solve(cost, i + 1, dp),
                                     solve(cost, i + 2, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);            // Memoization array
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
};

int main() {
    Solution sol;
    vector<int> cost = {1, 2, 1, 2, 1, 1, 1};
    cout << sol.minCostClimbingStairs(cost);
}





//? Bottom-Up
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n <= 2) return min(cost[0], cost[1]);

        vector<int> dp(n + 1, 0); // +1 for the "top" beyond last step
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // The answer is the cheaper way to reach the top from last or second-last step
        return min(dp[n - 1], dp[n - 2]);
    }
};

int main() {
    Solution sol;
    vector<int> cost = {1, 2, 1, 2, 1, 1, 1};
    cout << sol.minCostClimbingStairs(cost);
}




//?Space Optimized
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)cost.size();
        if (n == 1) return cost[0];
        if (n == 2) return min(cost[0], cost[1]);

        // prev2 = dp[i-2], prev1 = dp[i-1]
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; ++i) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        // Jump to top from step n-1 or n-2
        return min(prev1, prev2);
    }
};

int main() {
    Solution sol;
    vector<int> cost = {1, 2, 1, 2, 1, 1, 1};
    cout << sol.minCostClimbingStairs(cost) << "\n"; // Expected: 4
    return 0;
}

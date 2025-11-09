// ? Brute Force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        int res = 1e9; 
        for (int coin : coins) {
            if (amount - coin >= 0) {
                res = min(res, 1 + dfs(coins, amount - coin));
            }
        }
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(coins, amount);
        return (minCoins >= 1e9) ? -1 : minCoins; 
    }
};

int main() {
    Solution sol;

    vector<int> coins1 = {1, 5, 10};
    int amount1 = 12;
    cout << "Minimum coins (Example 1): " << sol.coinChange(coins1, amount1) << endl;
    // Expected: 3 (10 + 1 + 1)

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Minimum coins (Example 2): " << sol.coinChange(coins2, amount2) << endl;
    // Expected: -1 (cannot make 3 using only 2s)

    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Minimum coins (Example 3): " << sol.coinChange(coins3, amount3) << endl;
    // Expected: 0 (no coins needed for 0)

    return 0;
}



// ? Dynamic Programming (Bottom-Up)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
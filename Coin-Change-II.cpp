// ? Brute Force
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dfs(int i, int amount, vector<int>& coins) {
        if (amount == 0) return 1;

        if (i == coins.size() || amount < 0) return 0;

        
        int take = dfs(i, amount - coins[i], coins);
        int skip = dfs(i + 1, amount, coins);

        return take + skip;
    }

    int change(int amount, vector<int>& coins) {
        return dfs(0, amount, coins);
    }
};

int main() {
    Solution sol;
    vector<int> coins1 = {1,2,3};
    cout << sol.change(4, coins1) << endl;  // Output: 4

    vector<int> coins2 = {2,4};
    cout << sol.change(7, coins2) << endl;  // Output: 0
}



// ? DP Optimal Solution
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        if (coins.empty()) return 0;

        int g = coins[0];
        for (int c : coins) {
            g = std::gcd(g, c);
        }
        if (amount % g != 0) return 0;

        const long long INF = (long long)4e18;   

        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;  

        for (int coin : coins) {
            for (int x = coin; x <= amount; ++x) {
                long long add = dp[x - coin];

                if (dp[x] >= INF - add) {
                    dp[x] = INF;
                } else {
                    dp[x] += add;
                }
            }
        }

        if (dp[amount] > INT_MAX) {
            return 0;
        }
        return (int)dp[amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 3};
    int amount = 4;

    cout << sol.change(amount, coins) << endl;  // Output: 4
}
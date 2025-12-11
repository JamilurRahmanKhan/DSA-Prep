// ? Brute Force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // -------------------------------------------------------------
    // Public entry point required by LeetCode
    // -------------------------------------------------------------
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        // memo[i][buy] = profit from day i when we are in state 'buy'
        // buy = 1 -> we may buy (no stock held)
        // buy = 0 -> we are holding a stock
        vector<vector<int>> memo(n, vector<int>(2, INT_MIN));
        return dfs(0, 1, prices, memo);
    }

private:
    // -------------------------------------------------------------
    // Recursive helper with memoisation
    // -------------------------------------------------------------
    /*
    Array:
    day:    0  1  2  3  4  5
    price: [7, 1, 5, 3, 6, 4]
    */
    int dfs(int i, int canBuy,
            const vector<int>& prices,
            vector<vector<int>>& memo) {
        if (i == (int)prices.size())          // past the last day
            return 0;

        if (memo[i][canBuy] != INT_MIN)       // already computed
            return memo[i][canBuy];

        int profit;
        if (canBuy) {
            // 1) Buy today  -> pay price[i] and move to holding state
            // 2) Skip today -> stay in canBuy state
            int buy  = -prices[i] + dfs(i + 1, 0, prices, memo);
            int skip =        dfs(i + 1, 1, prices, memo);
            profit = max(buy, skip);
        } else {
            // we are holding a stock
            // 1) Sell today -> gain price[i] and become free to buy
            // 2) Hold       -> stay in holding state
            int sell =  prices[i] + dfs(i + 1, 1, prices, memo);
            int hold =          dfs(i + 1, 0, prices, memo);
            profit = max(sell, hold);
        }

        memo[i][canBuy] = profit;   // store for future calls
        return profit;
    }
};

int main() {
    Solution sol;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit (Example 1): " << sol.maxProfit(prices1) << endl;

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Max Profit (Example 2): " << sol.maxProfit(prices2) << endl;

    return 0;
}


// Greedy approach
/*
Array:
day:    0  1  2  3  4  5
price: [7, 1, 5, 3, 6, 4]
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        for(int i=0; i<n-1; i++){
            if(prices[i+1] > prices[i]){
                profit += prices[i+1] - prices[i];
            }
        }
        return profit;
    }
};
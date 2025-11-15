// ? Brute Force
#include <iostream>      
#include <vector>        
#include <algorithm>     
using namespace std;

class Solution {
public:
    int dfs(int i, bool holding, vector<int>& prices) {
        int n = prices.size();
        if (i >= n) return 0; 

        int skip = dfs(i + 1, holding, prices);

        if (holding) {
            int sell = prices[i] + dfs(i + 2, false, prices); // cooldown → jump 2 days
            return max(skip, sell);
        } else {
            int buy = -prices[i] + dfs(i + 1, true, prices);
            return max(skip, buy);
        }
    }

    int maxProfit(vector<int>& prices) {
        return dfs(0, false, prices);  
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1,3,4,0,4};
    cout << sol.maxProfit(prices) << endl;
}
/*
prices = [1, 3, 4, 0, 4]
index:    0  1  2  3  4

dfs(0,F)
  ├─ skip → dfs(1,F) = 4
  │     ├─ skip → dfs(2,F) = 4
  │     │     ├─ skip → dfs(3,F) = 4
  │     │     │     ├─ skip → dfs(4,F) = 0
  │     │     │     └─ buy  → -0 + dfs(4,T)=4 → 4
  │     │     └─ buy  → -4 + dfs(3,T)=4 → 0   (max(4,0)=4)
  │     └─ buy  → -3 + dfs(2,T)=4 → 1         (max(4,1)=4)
  └─ buy  → -1 + dfs(1,T)=7 → 6
        ├─ skip → dfs(2,T)=4
        │     ├─ skip → dfs(3,T)=4
        │     │     ├─ skip → dfs(4,T)=4
        │     │     └─ sell → 0 + dfs(5,F)=0 → 0  (max(4,0)=4)
        │     └─ sell → 4 + dfs(4,F)=0 → 4        (max(4,4)=4)
        └─ sell → 3 + dfs(3,F)=4 → 7
*/




// ? DP
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  // for INT_MIN

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
    
        int dp_i0 = 0;          
        int dp_i1 = INT_MIN;     
        int dp_pre0 = 0;          

        for (int price : prices) {
            int temp = dp_i0;     
            dp_i0 = max(dp_i0, dp_i1 + price);
            dp_i1 = max(dp_i1, dp_pre0 - price);
            dp_pre0 = temp;
        }
        return dp_i0; 
    }
};


int main() {
    Solution sol;

    vector<int> prices1 = {1, 3, 4, 0, 4};
    cout << sol.maxProfit(prices1) << endl;  // Expected: 6

    vector<int> prices2 = {1};
    cout << sol.maxProfit(prices2) << endl;  // Expected: 0

    return 0;
}
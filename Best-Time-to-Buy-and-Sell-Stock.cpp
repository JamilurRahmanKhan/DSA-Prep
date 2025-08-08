// Brute Force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (i < j)
                {
                    profit = prices[j] - prices[i];
                    maxProfit = max(maxProfit, profit);
                }
            }
        }
        return maxProfit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {10, 1, 5, 6, 7, 1};
    int result = sol.maxProfit(prices);
    cout << "The maximum profit is: " << result << endl;
    return 0;
}


// // Dynamic Programming
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int minPrice = prices[0];
//         int maxProfit = 0;

//         for (int i = 1; i < prices.size(); i++)
//         {
//             maxProfit = max(maxProfit, prices[i] - minPrice);
//             minPrice = min(minPrice, prices[i]);
//         }
//         return maxProfit;
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<int> prices = {10, 1, 5, 6, 7, 1};
//     int result = sol.maxProfit(prices);
//     cout << "The maximum profit is: " << result << endl;
//     return 0;
// }



// // Two Pointers
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int l = 0, r = 1;
//         int maxP = 0;

//         while (r < prices.size()) {
//             if (prices[l] < prices[r]) {
//                 int profit = prices[r] - prices[l];
//                 maxP = max(maxP, profit);
//             } else {
//                 l = r;
//             }
//             r++;
//         }
//         return maxP;
//     }
// };
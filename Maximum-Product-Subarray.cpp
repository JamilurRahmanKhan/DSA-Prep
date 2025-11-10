// ? Brute Force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];

        for(int i=0; i<nums.size(); i++){
            int cur = nums[i];
            res = max(res,cur);
            for(int j=i+1; j<nums.size(); j++){
                cur *= nums[j];
                res = max(res,cur);
            }
        }
        return res;
    }
};

// ---- Demo ----
int main() {
    Solution sol;
    vector<int> a1 = {1, 2, -3, 4};         // expected 4
    vector<int> a2 = {-2, -1};              // expected 2
    vector<int> a3 = {2, 3, -2, 4};         // expected 6 (2*3)
    vector<int> a4 = {-2, 0, -1};           // expected 0
    vector<int> a5 = {-2, 3, -4};           // expected 24 (3 * -4 * -2 scenario handled)
    cout << sol.maxProduct(a1) << "\n";
    cout << sol.maxProduct(a2) << "\n";
    cout << sol.maxProduct(a3) << "\n";
    cout << sol.maxProduct(a4) << "\n";
    cout << sol.maxProduct(a5) << "\n";
    return 0;
}



// ? Kadane's Algorithm
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long curMax = nums[0];
        long long curMin = nums[0];
        long long best   = nums[0];

        for (int i = 1; i < (int)nums.size(); ++i) {
            long long x = nums[i];

            // If x is negative, max/min swap roles
            if (x < 0) swap(curMax, curMin);

            // Extend or start fresh at x
            curMax = max(x, curMax * x);
            curMin = min(x, curMin * x);

            best = max(best, curMax);
        }
        return (int)best;
    }
};
// ? Brute Force
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int n : nums) total += n;

        // If total is odd, can't split equally
        if (total % 2 != 0) return false;

        int target = total / 2;
        return canMake(nums, 0, target);
    }

    // Recursive helper
    bool canMake(vector<int>& nums, int i, int target) {
        // Base cases
        if (target == 0) return true;          // found subset
        if (i >= nums.size() || target < 0) return false;

        // Try two choices:
        // 1️⃣ Take the current number
        bool take = canMake(nums, i + 1, target - nums[i]);
        // 2️⃣ Skip the current number
        bool skip = canMake(nums, i + 1, target);

        return take || skip;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4};
    cout << boolalpha << sol.canPartition(nums1) << endl; // true

    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << boolalpha << sol.canPartition(nums2) << endl; // false

    return 0;
}



// ? DP Bottom-Up
#include <iostream>      // for input/output
#include <vector>        // for vector container
#include <numeric>       // for accumulate()
#include <algorithm>     // for max, min functions
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) return false;              
        int target = total / 2;

        vector<char> dp(target + 1, 0);
        dp[0] = 1;                               

        for (int x : nums) {
            for (int s = target; s >= x; --s) {
                if (dp[s - x]) {
                    dp[s] = 1;
                }
            }
        }
        return dp[target];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 2, 3, 4, 5};

    cout << boolalpha;
    cout << "Example 1: " << sol.canPartition(nums1) << endl; // true → {1,4} and {2,3}
    cout << "Example 2: " << sol.canPartition(nums2) << endl; // false
}
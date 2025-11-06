//? Brute Force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // return max money starting from index i
    int robFrom(int i, const vector<int>& nums) {
        int n = (int)nums.size();
        if (i >= n) return 0; // past last house -> no money

        // Choice 1: Rob this house, then skip next (i+2)
        int take = nums[i] + robFrom(i + 2, nums);

        // Choice 2: Skip this house, try next (i+1)
        int skip = robFrom(i + 1, nums);

        return max(take, skip);
    }

    int rob(vector<int>& nums) {
        return robFrom(0, nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,1,3,3};
    cout << sol.rob(nums1) << "\n"; // 4

    vector<int> nums2 = {2,9,8,3,6};
    cout << sol.rob(nums2) << "\n"; // 16
    return 0;
}


//? Top-Down DP
class Solution {
public:
    int robFrom(int i, const vector<int>& nums, vector<int>& dp) {
        int n = (int)nums.size();
        if (i >= n) return 0; 
        if(dp[i] != -1) return dp[i];

        int take = nums[i] + robFrom(i + 2, nums, dp);
        int skip = robFrom(i + 1, nums, dp);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return robFrom(0, nums, dp);
    }
};



//? Bottom-Up
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
};



//? Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(nums.size(), -1);
        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            int curr = max(nums[i]+prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};
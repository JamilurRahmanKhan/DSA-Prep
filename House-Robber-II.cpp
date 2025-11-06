//? Brute Force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Standard recursive function from House Robber I
    int robFrom(int i, const vector<int>& nums, int end) {
        if (i > end) return 0;
        int rob = nums[i] + robFrom(i + 2, nums, end);  // Rob this one
        int skip = robFrom(i + 1, nums, end);           // Skip it
        return max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Only one house

        // Case 1: Exclude last house (rob 0..n-2)
        int case1 = robFrom(0, nums, n - 2);

        // Case 2: Exclude first house (rob 1..n-1)
        int case2 = robFrom(1, nums, n - 1);

        return max(case1, case2);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 4, 3};
    cout << sol.rob(nums1) << endl;  // Output: 4

    vector<int> nums2 = {2, 9, 8, 3, 6};
    cout << sol.rob(nums2) << endl;  // Output: 15

    return 0;
}


//? Top-Down
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int robRange(int i, int end, const vector<int>& nums, vector<int>& dp) {
        if (i > end) return 0;                   
        if (dp[i] != -1) return dp[i];           

        int take = nums[i] + robRange(i + 2, end, nums, dp); 
        int skip = robRange(i + 1, end, nums, dp);           

        return dp[i] = max(take, skip);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];              

        // Case 1: rob in range [0 .. n-2] (exclude last)
        vector<int> dp1(n, -1);
        int case1 = robRange(0, n - 2, nums, dp1);

        // Case 2: rob in range [1 .. n-1] (exclude first)
        vector<int> dp2(n, -1);
        int case2 = robRange(1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};

// ---- Demo driver ----
int main() {
    Solution sol;

    vector<int> a = {3, 4, 3};
    cout << sol.rob(a) << "\n";                  // Output: 4

    vector<int> b = {2, 9, 8, 3, 6};
    cout << sol.rob(b) << "\n";                  // Output: 15

    return 0;
}



//? Bottom-Up
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int robLinear(const vector<int>& nums, int L, int R) {
        if (L > R) return 0;
        if (L == R) return nums[L];

        vector<int> dp(R - L + 1, 0);
        dp[0] = nums[L];
        dp[1] = max(nums[L], nums[L + 1]);

        for (int i = 2; i <= R - L; ++i) {
            dp[i] = max(nums[L + i] + dp[i - 2], dp[i - 1]);
        }
        return dp.back(); //t’s the same as dp[dp.size() - 1].
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];            

        int case1 = robLinear(nums, 0, n - 2);

        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};

// ---- Demo driver ----
int main() {
    Solution sol;

    vector<int> a = {3, 4, 3};
    cout << sol.rob(a) << "\n";                  // Output: 4

    vector<int> b = {2, 9, 8, 3, 6};
    cout << sol.rob(b) << "\n";                  // Output: 15

    return 0;
}



//? Space Optimized
class Solution {
public:
    int robLinear(int L, const vector<int>& nums, int R){
        if(L > R) return 0;
        if(L == R) return nums[L];

        int prev1 = nums[L];
        int prev2 = max(nums[L], nums[L+1]);

        for(int i=2; i<R-L+1; i++){
            int curr = max(nums[L+i]+prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int case1 = robLinear(0, nums, n-2);

        int case2 = robLinear(1, nums, n-1);

        return max(case1, case2);
    }
};

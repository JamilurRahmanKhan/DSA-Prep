// ? Brute Force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& nums, int i, int prev) {
        if (i == nums.size()) return 0; // reached end

        // Option 1: skip current number
        int skip = dfs(nums, i + 1, prev);

        // Option 2: take current number (only if it's increasing)
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + dfs(nums, i + 1, i);
        }

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        return dfs(nums, 0, -1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {9, 1, 4, 2, 3, 3, 7};
    cout << sol.lengthOfLIS(nums); // Output: 4
}



// ? Dynamic Programming (Bottom-Up)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 1);

        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }
        return *max_element(LIS.begin(), LIS.end());
    }
};

// * nums = [0,  1, 2, 3,  4]
// * nums = [3, 10, 2, 1, 20]

// *  LIS = [1,  1, 1, 1, 1]
// *  LIS = [1,  1, 1, 2, 1]
// *  LIS = [1,  1, 2, 2, 1]
// *  LIS = [1,  2, 2, 2, 1]
// *  LIS = [3,  2, 2, 2, 1]



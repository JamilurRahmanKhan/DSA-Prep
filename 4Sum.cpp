// ? Two Pointers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = (int)nums.size();
        if (n < 4) return result;

        // 1) Sort the array
        sort(nums.begin(), nums.end());

        // 2) First element i
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 3) Second element j
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // long long remaining = (long long)target - nums[i] - nums[j];
                int l = j + 1;
                int r = n - 1;

                // 4) Two-pointer search for the remaining two elements
                while (l < r) {
                    // long long twoSum = (long long)nums[l] + nums[r];
                    long long totalSum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                    if (totalSum == target) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});

                        // Skip duplicates for l
                        int lastL = nums[l];
                        while (l < r && nums[l] == lastL) l++;

                        // Skip duplicates for r
                        int lastR = nums[r];
                        while (l < r && nums[r] == lastR) r--;
                    } else if (totalSum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 3, -3, 1, 0};
    int target1 = 3;
    auto res1 = sol.fourSum(nums1, target1);

    cout << "Example 1 results:\n";
    for (auto &quad : res1) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i] << (i + 1 < quad.size() ? "," : "");
        }
        cout << "]\n";
    }

    vector<int> nums2 = {1, -1, 1, -1, 1, -1};
    int target2 = 2;
    auto res2 = sol.fourSum(nums2, target2);

    cout << "\nExample 2 results:\n";
    for (auto &quad : res2) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i] << (i + 1 < quad.size() ? "," : "");
        }
        cout << "]\n";
    }

    return 0;
}
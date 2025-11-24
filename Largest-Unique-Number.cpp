// ? Brute Force
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        for (int i = 0; i < n; i++) {
            int count = 0;

            // Count occurrences of nums[i]
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

            // If appears once, check if it's largest so far
            if (count == 1) {
                result = max(result, nums[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {5,7,3,9,4,9,8,3,1};
    cout << sol.largestUniqueNumber(nums1) << endl;   // 8

    vector<int> nums2 = {9,9,8,8};
    cout << sol.largestUniqueNumber(nums2) << endl;   // -1

    return 0;
}


// ? Optimal
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int freq[1001] = {0};

        for (int x : nums) {
            freq[x]++;
        }

        for (int val = 1000; val >= 0; val--) {
            if (freq[val] == 1) {
                return val;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {5,7,3,9,4,9,8,3,1};
    cout << sol.largestUniqueNumber(nums1) << endl;   // Output: 8

    vector<int> nums2 = {9,9,8,8};
    cout << sol.largestUniqueNumber(nums2) << endl;   // Output: -1

    return 0;
}
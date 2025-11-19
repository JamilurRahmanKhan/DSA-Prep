#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0;
        int maxLen = 0;

        for (int x : nums) {
            if (x == 1) {
                len++;
            } else {
                len = 0;
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 1, 0, 1, 1, 1};
    cout << "Output 1: " << sol.findMaxConsecutiveOnes(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {1, 0, 1, 1, 0, 1};
    cout << "Output 2: " << sol.findMaxConsecutiveOnes(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {0, 0, 0, 0};
    cout << "Output 3: " << sol.findMaxConsecutiveOnes(nums3) << endl;

    // Test Case 4
    vector<int> nums4 = {1, 1, 1, 1};
    cout << "Output 4: " << sol.findMaxConsecutiveOnes(nums4) << endl;

    return 0;
}
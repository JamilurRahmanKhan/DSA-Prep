// ? Brute Force
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for (int &x : nums) {
            freq[x]++;
        }

        int repeated = -1;
        int missing = -1;

        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) {
                repeated = i;
            } else if (freq[i] == 0) {
                missing = i;
            }
        }

        return {repeated, missing};
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 2, 4};
    vector<int> ans1 = sol.findErrorNums(nums1);
    cout << "Input: [1,2,2,4] -> Output: [" 
         << ans1[0] << "," << ans1[1] << "]" << endl;

    // Test case 2
    vector<int> nums2 = {1, 1};
    vector<int> ans2 = sol.findErrorNums(nums2);
    cout << "Input: [1,1] -> Output: [" 
         << ans2[0] << "," << ans2[1] << "]" << endl;

    return 0;
}



// ? Optimal
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int repeated = -1, missing = -1;

        // Step 1: Find repeated number using sign-marking
        for (int x : nums) {
            int idx = abs(x) - 1;
            if (nums[idx] < 0) {
                repeated = abs(x);
            } else {
                nums[idx] = -nums[idx];
            }
        }

        // Step 2: Find missing number (positive index)
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        return {repeated, missing};
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 4};
    vector<int> ans1 = sol.findErrorNums(nums1);
    cout << "Output: [" << ans1[0] << ", " << ans1[1] << "]\n";

    vector<int> nums2 = {1, 1};
    vector<int> ans2 = sol.findErrorNums(nums2);
    cout << "Output: [" << ans2[0] << ", " << ans2[1] << "]\n";

    return 0;
}
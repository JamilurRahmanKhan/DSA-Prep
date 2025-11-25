// ? Brute Force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;

        // Try every starting index i
        for (int i = 0; i < n; i++) {
            int currSum = nums[i];

            // Extend subarray from i to j
            for (int j = i + 1; j < n; j++) {
                // check if strictly increasing
                if (nums[j] > nums[j - 1]) {
                    currSum += nums[j];
                } else {
                    break; // not ascending anymore
                }
            }

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {10,20,30,5,10,50};
    cout << sol.maxAscendingSum(nums1) << endl; // Output: 65

    vector<int> nums2 = {10,20,30,40,50};
    cout << sol.maxAscendingSum(nums2) << endl; // Output: 150

    vector<int> nums3 = {12,17,15,13,10,11,12};
    cout << sol.maxAscendingSum(nums3) << endl; // Output: 33

    return 0;
}


// ? Optimal
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; 

        int currSum = nums[0];   
        int maxSum = nums[0];    

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                // still strictly increasing, extend the subarray
                currSum += nums[i];
            } else {
                // sequence broke, start new subarray from nums[i]
                currSum = nums[i];
            }
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {10, 20, 30, 5, 10, 50};
    cout << "Example 1: " << sol.maxAscendingSum(nums1) << endl; // 65

    vector<int> nums2 = {10, 20, 30, 40, 50};
    cout << "Example 2: " << sol.maxAscendingSum(nums2) << endl; // 150

    vector<int> nums3 = {12, 17, 15, 13, 10, 11, 12};
    cout << "Example 3: " << sol.maxAscendingSum(nums3) << endl; // 33

    vector<int> nums4 = {5};
    cout << "Single element: " << sol.maxAscendingSum(nums4) << endl; // 5

    return 0;
}
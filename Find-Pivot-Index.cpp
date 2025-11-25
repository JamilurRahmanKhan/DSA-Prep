// ? Prefix Suffix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        // Prefix 
        vector<int> prefix(n);
        int prefixSum = 0; 
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            prefix[i] = prefixSum;
        }

        // Suffix
        vector<int> suffix(n);
        int suffixSum = 0; 
        for (int i = n - 1; i >= 0; i--) {
            suffixSum += nums[i];
            suffix[i] = suffixSum;
        }

        // Find first index where prefix sum == suffix sum
        for (int i = 0; i < n; i++) {
            if (prefix[i] == suffix[i]) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    cout << "Pivot index of [1,7,3,6,5,6]: " 
         << sol.pivotIndex(nums1) << endl; // 3

    vector<int> nums2 = {3, 2, 1};
    cout << "Pivot index of [3,2,1]: " 
         << sol.pivotIndex(nums2) << endl; // -1

    vector<int> nums3 = {2, 1, -1};
    cout << "Pivot index of [2,1,-1]: " 
         << sol.pivotIndex(nums3) << endl; // 0

    return 0;
}
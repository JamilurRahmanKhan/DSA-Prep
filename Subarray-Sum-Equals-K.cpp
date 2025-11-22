// ? Brute Force
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;  
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, -1, 1, 2};
    int k1 = 2;
    cout << "nums = [2,-1,1,2], k = 2 -> "
         << sol.subarraySum(nums1, k1) << endl;

    // Test case 2
    vector<int> nums2 = {4, 4, 4, 4, 4, 4};
    int k2 = 4;
    cout << "nums = [4,4,4,4,4,4], k = 4 -> "
         << sol.subarraySum(nums2, k2) << endl;

    // You can add more test cases here if you want

    return 0;
}


// ? Optimal
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        int prefixSum = 0;
        int count = 0;

        freq[0] = 1;

        for (int x : nums) { //O(n)
            prefixSum += x;

            int need = prefixSum - k;
            if (freq.find(need) != freq.end()) { //O(1)
                count += freq[need];
            }
            freq[prefixSum]++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, -1, 1, 2};
    int k1 = 2;
    cout << "nums = [2,-1,1,2], k = 2 -> "
         << sol.subarraySum(nums1, k1) << endl;

    vector<int> nums2 = {4, 4, 4, 4, 4, 4};
    int k2 = 4;
    cout << "nums = [4,4,4,4,4,4], k = 4 -> "
         << sol.subarraySum(nums2, k2) << endl;

    return 0;
}
// ? Brute Force
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;

        for (int i = 0; i < n; i++) {
            int count = 0;
            int j = 0;

            while (j < n) {
                if (nums[i] == nums[j]) {
                    count++;
                }
                j++; 
            }

            if (count > m) {
                return nums[i];
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {5,5,1,1,1,5,5};
    cout << sol.majorityElement(nums1) << endl; // Expected 5

    vector<int> nums2 = {2,2,2};
    cout << sol.majorityElement(nums2) << endl; // Expected 2

    return 0;
}


// ? Optimal
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        int m = n/2;

        for(int x : nums){
            freq[x]++;
        }

        for(auto &p : freq){
            int num = p.first;
            int count = p.second;
            if(count > m){
                return num;
            }
        }
        return -1;
    }
};


// ? Boyer-Moore Voting Algorithm.  Example: nums = [5, 5, 1, 1, 1, 5, 5]
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, count = 0;

        for (int num : nums) {
            if (count == 0) {
                res = num;
            }
            count += (num == res) ? 1 : -1;
        }
        return res;
    }
};
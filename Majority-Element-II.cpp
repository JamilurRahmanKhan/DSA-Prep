//  ? Frequency
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m = n / 3;

        unordered_map<int,int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        vector<int> ans;

        // Collect all elements that appear more than n/3 times
        for (auto &p : freq) {
            int value = p.first;
            int count = p.second;

            if (count > m) {
                ans.push_back(value);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {5,2,3,2,2,2,2,5,5,5};
    vector<int> res1 = sol.majorityElement(nums1);
    cout << "Example 1 output: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    // Example 2
    vector<int> nums2 = {4,4,4,4,4};
    vector<int> res2 = sol.majorityElement(nums2);
    cout << "Example 2 output: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    // Example 3
    vector<int> nums3 = {1,2,3};
    vector<int> res3 = sol.majorityElement(nums3);
    cout << "Example 3 output: ";
    for (int x : res3) cout << x << " ";
    cout << endl;

    return 0;
}



// ? Boyer-Moore Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find up to two potential candidates
        int cand1 = 0, cand2 = 0;
        int count1 = 0, count2 = 0;

        for (int x : nums) {
            if (x == cand1) {
                count1++;
            }
            else if (x == cand2) {
                count2++;
            }
            else if (count1 == 0) {
                cand1 = x;
                count1 = 1;
            }
            else if (count2 == 0) {
                cand2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify the candidates
        count1 = 0;
        count2 = 0;
        for (int x : nums) {
            if (x == cand1) count1++;
            else if (x == cand2) count2++;
        }

        vector<int> ans;
        if (count1 > n / 3) ans.push_back(cand1);
        if (count2 > n / 3) ans.push_back(cand2);

        return ans;
    }
};
// ? Brute Force
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]==nums[j] && i<j){
                    count++;
                }
            }
        }
        return count;
    }
};


// ? Optimal
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int freq[101] = {0};  
        int pairs = 0;

        for (int x : nums) {
            pairs += freq[x];  
            freq[x]++;        
        }

        return pairs;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 1, 1, 3};
    cout << "Input: [1,2,3,1,1,3] -> Output: "
         << sol.numIdenticalPairs(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {1, 1, 1, 1};
    cout << "Input: [1,1,1,1] -> Output: "
         << sol.numIdenticalPairs(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {1, 2, 3};
    cout << "Input: [1,2,3] -> Output: "
         << sol.numIdenticalPairs(nums3) << endl;

    // Test Case 4
    vector<int> nums4 = {5, 5, 5, 5, 5};
    cout << "Input: [5,5,5,5,5] -> Output: "
         << sol.numIdenticalPairs(nums4) << endl;

    return 0;
}
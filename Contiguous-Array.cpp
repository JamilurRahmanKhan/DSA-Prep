// ? Brute Force
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int zero = 0, one = 0; 

            for (int j = i; j < n; j++) {
                if (nums[j] == 0) {
                    zero++;
                } else {
                    one++;
                }

                if (zero == one) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {0, 1};
    cout << "Input: [0,1] -> "
         << sol.findMaxLength(nums1) << endl; // Expected 2

    // Test case 2
    vector<int> nums2 = {0, 1, 0};
    cout << "Input: [0,1,0] -> "
         << sol.findMaxLength(nums2) << endl; // Expected 2

    // Test case 3
    vector<int> nums3 = {0,1,1,1,1,1,0,0,0};
    cout << "Input: [0,1,1,1,1,1,0,0,0] -> "
         << sol.findMaxLength(nums3) << endl; // Expected 6

    return 0;
}




// ? Optimized
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // for max
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; // sum -> earliest index

        int currSum = 0;
        int result = 0;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                currSum += -1;
            } else {
                currSum += 1;
            }

            if (mp.find(currSum) != mp.end()) {
                result = max(result, i-mp[currSum]);
            } else {
                mp[currSum] = i;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {0, 1};
    cout << "Input: [0,1] -> " << sol.findMaxLength(nums1) << endl; // Expected 2

    vector<int> nums2 = {0, 1, 0};
    cout << "Input: [0,1,0] -> " << sol.findMaxLength(nums2) << endl; // Expected 2

    vector<int> nums3 = {0,1,1,1,1,1,0,0,0};
    cout << "Input: [0,1,1,1,1,1,0,0,0] -> " << sol.findMaxLength(nums3) << endl; // Expected 6

    return 0;
}
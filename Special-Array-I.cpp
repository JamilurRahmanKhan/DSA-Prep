// ? Optimal
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1) return true;

        for (int i = 0; i < n - 1; i++) {
            if ((nums[i] % 2) == (nums[i + 1] % 2)) {
                return false;
            }
        }

        return true; 
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1};
    vector<int> nums2 = {2, 1, 4};
    vector<int> nums3 = {4, 3, 1, 6};

    cout << boolalpha;
    cout << "Example 1: " << sol.isArraySpecial(nums1) << endl; // true
    cout << "Example 2: " << sol.isArraySpecial(nums2) << endl; // true
    cout << "Example 3: " << sol.isArraySpecial(nums3) << endl; // false

    return 0;
}

// ? Alternative
class Solution {
public:
    bool isEven(int i){
        if (i % 2 == 0) {
            return true;
        }
        return false;
    }

    bool isOdd(int i){
        if (i % 2 != 0) {
            return true;
        }
        return false;
    }

    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;

        for(int i=0; i<n-1; i++){
            if((isEven(nums[i]) && isEven(nums[i+1])) || (isOdd(nums[i]) && isOdd(nums[i+1]))){
                return false;
            }
        }
        return true;
    }
};
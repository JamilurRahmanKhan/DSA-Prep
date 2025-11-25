// ? Brute Force
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool nonDecreasing = true;
        bool nonIncreasing = true;

        // Check every pair (i, j) with i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (nums[i] > nums[j]) {
                    nonDecreasing = false;
                }
                if (nums[i] < nums[j]) {
                    nonIncreasing = false;
                }
            }
        }

        return nonDecreasing || nonIncreasing;
    }
};


// ? Optimal
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return true; 

        bool isInc = true;
        bool isDec = true;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                isDec = false;        
            } else if (nums[i] > nums[i + 1]) {
                isInc = false;         
            }
        }

        return isInc || isDec;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,2,2,3};
    vector<int> b = {6,5,4,4};
    vector<int> c = {1,3,2};

    cout << boolalpha;
    cout << sol.isMonotonic(a) << endl; // true
    cout << sol.isMonotonic(b) << endl; // true
    cout << sol.isMonotonic(c) << endl; // false
    return 0;
}
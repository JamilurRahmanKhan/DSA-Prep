#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};

int main() {
    // Hard-coded input (change these values if you want)
    vector<int> nums = {1, 4, 1, 2};

    Solution sol;
    vector<int> result = sol.getConcatenation(nums);

    cout << "Concatenated array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
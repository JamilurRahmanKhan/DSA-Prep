#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;

        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped water for test 1: " << sol.trap(height1) << endl;  // Expected 6

    vector<int> height2 = {4,2,0,3,2,5};
    cout << "Trapped water for test 2: " << sol.trap(height2) << endl;  // Expected 9

    vector<int> height3 = {3,0,2,0,4};
    cout << "Trapped water for test 3: " << sol.trap(height3) << endl;  // Expected 7

    return 0;
}
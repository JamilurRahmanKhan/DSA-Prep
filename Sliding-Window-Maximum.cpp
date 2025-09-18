#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;   // stores indices of useful elements
        vector<int> result;

        for (int i = 0; i < n; i++) {
            // Remove indices out of current window
            while (!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }

            // Remove smaller elements from back
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }

            // Push current index
            deq.push_back(i);

            // Add result if window size >= k
            if (i >= k - 1) {
                result.push_back(nums[deq.front()]);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 0, 4, 2, 6};
    int k = 3;

    vector<int> ans = sol.maxSlidingWindow(nums, k);

    cout << "Output: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
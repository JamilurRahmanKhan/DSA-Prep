#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1; // target not found
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int result = sol.search(nums, target);

    cout << "Index of " << target << " is: " << result << endl;

    return 0;
}
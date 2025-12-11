// ?
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int l = 1; // next position to write a unique element

        for (int r = 1; r < (int)nums.size(); r++) {
            // if current element is different from previous, it's unique
            if (nums[r] != nums[r - 1]) {
                nums[l] = nums[r];
                l++; // move write pointer
            }
        }

        return l; // number of unique elements
    }
};
// ? nums  = [1, 1, 2, 3, 3, 4]
// ? index = [0, 1, 2, 3, 4, 5]

int main() {
    Solution sol;

    vector<int> nums1 = {1,1,2,3,4};
    int k1 = sol.removeDuplicates(nums1);
    cout << "k1 = " << k1 << "\nUnique elements: ";
    for (int i = 0; i < k1; i++) cout << nums1[i] << " ";
    cout << "\n\n";

    vector<int> nums2 = {2,10,10,30,30,30};
    int k2 = sol.removeDuplicates(nums2);
    cout << "k2 = " << k2 << "\nUnique elements: ";
    for (int i = 0; i < k2; i++) cout << nums2[i] << " ";
    cout << "\n";

    return 0;
}
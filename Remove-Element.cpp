//? Brute Force
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(); 

        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                for (int j = i; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                n--;   
                i--;   
            }
        }

        return n;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 2, 3, 4};
    int val1 = 1;
    int k1 = sol.removeElement(nums1, val1);

    cout << "k1 = " << k1 << "\nNew array (first k1 elements): ";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i] << " ";
    }
    cout << "\n";

    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int k2 = sol.removeElement(nums2, val2);

    cout << "k2 = " << k2 << "\nNew array (first k2 elements): ";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i] << " ";
    }
    cout << "\n";

    return 0;
}


// ? Two pointer
int removeElement(vector<int>& nums, int val) {
    int k = 0;

    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
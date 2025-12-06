// ? Counting / Frequency Pattern
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // count[i] = how many times color i appears (i = 0,1,2)
        vector<int> count(3, 0);

        // 1) Count frequencies of 0, 1, 2
        for (int num : nums) {
            count[num]++;
        }

        // 2) Overwrite nums in order: first 0s, then 1s, then 2s
        int index = 0;
        for (int color = 0; color < 3; color++) {
            while (count[color] > 0) {
                nums[index++] = color;
                count[color]--;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 0, 1, 2};
    sol.sortColors(nums1);

    cout << "Sorted nums1: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {2, 1, 0};
    sol.sortColors(nums2);

    cout << "Sorted nums2: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;

    return 0;
}



// ? Three Pointer - 1
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0;         
        int r = n - 1;     
        int i = 0;         

        while (i <= r) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
                i++; 
            } 
            else if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;     
            } 
            else { 
                i++;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,0,1,2};
    sol.sortColors(nums1);
    cout << "Sorted nums1: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {2,1,0};
    sol.sortColors(nums2);
    cout << "Sorted nums2: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;

    return 0;
}


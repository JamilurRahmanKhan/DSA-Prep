// ? reversal
#include <iostream>
#include <vector>
#include <algorithm> // for reverse

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        // In case k > n
        k = k % n;
        if (k == 0) return; // no change needed

        // Step 1: reverse whole array
        reverse(nums.begin(), nums.end());

        // Step 2: reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: reverse last n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,2,3,4,5,6,7,8};
    int k1 = 4;
    sol.rotate(nums1, k1);
    cout << "Example 1 rotated: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    // Example 2
    vector<int> nums2 = {1000,2,4,-3};
    int k2 = 2;
    sol.rotate(nums2, k2);
    cout << "Example 2 rotated: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;

    // Extra test: k larger than n
    vector<int> nums3 = {1,2,3};
    int k3 = 5; // same as rotating by 2
    sol.rotate(nums3, k3);
    cout << "Extra example rotated: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;

    return 0;
}


// ? Cyclic Traversal
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int count = 0;

        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int nextIdx = (current + k) % n;
                int temp = nums[nextIdx];
                nums[nextIdx] = prev;
                prev = temp;
                current = nextIdx;
                count++;
            } while (start != current);
        }
    }
};
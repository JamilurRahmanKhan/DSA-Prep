// Quick Select
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int partition_algo(vector<int>& nums, int L, int R) {
        int P = nums[L];   // choose pivot
        int i = L + 1;
        int j = R;

        while (i <= j) {
            if (nums[i] < P && nums[j] > P) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if (nums[i] >= P) {
                i++;
            }
            if (nums[j] <= P) {
                j--;
            }
        }
        swap(nums[L], nums[j]);
        return j;  // Pivot is now at correct index
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int L = 0, R = n - 1;
        int pivot_idx = 0;

        while (true) {
            pivot_idx = partition_algo(nums, L, R);

            if (pivot_idx == k - 1) {
                break;
            } else if (pivot_idx > k - 1) {
                R = pivot_idx - 1;
            } else {
                L = pivot_idx + 1;
            }
        }
        return nums[pivot_idx];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "The " << k << "th largest element is: " 
         << sol.findKthLargest(nums, k) << endl;

    return 0;
}



// Min Heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
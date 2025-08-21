// 287. Find the Duplicate Number

// Sorting
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         for(int i=0; i<nums.size()-1; i++)
//         {
//             if(nums[i] == nums[i+1])
//             {
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };

// int main() {
//     Solution sol;

//     // Example 1
//     vector<int> nums1 = {1, 2, 3, 2, 2};
//     cout << "Duplicate in nums1: " << sol.findDuplicate(nums1) << endl;

//     // Example 2
//     vector<int> nums2 = {1, 2, 3, 4, 4};
//     cout << "Duplicate in nums2: " << sol.findDuplicate(nums2) << endl;

//     return 0;
// }






// Hash Set
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_set<int> seen;
//         for(int num : nums)
//         {
//             if(seen.find(num) != seen.end())
//             {
//                 return num;
//             }
//             seen.insert(num);
//         }
//         return -1;
//     }
// };

// int main() {
//     Solution sol;

//     // Example 1
//     vector<int> nums1 = {1, 2, 3, 2, 2};
//     cout << "Duplicate in nums1: " << sol.findDuplicate(nums1) << endl;

//     // Example 2
//     vector<int> nums2 = {1, 2, 3, 4, 4};
//     cout << "Duplicate in nums2: " << sol.findDuplicate(nums2) << endl;

//     return 0;
// }




// Array
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         vector<int> seen(nums.size(), 0);
//         for(int num : nums)
//         {
//             if(seen[num-1] == 1)
//             {
//                 return num;
//             }
//             seen[num-1] = 1;
//         }
//         return -1;
//     }
// };

// int main() {
//     Solution sol;

//     // Example 1
//     vector<int> nums1 = {1, 2, 3, 2, 2};
//     cout << "Duplicate in nums1: " << sol.findDuplicate(nums1) << endl;

//     // Example 2
//     vector<int> nums2 = {1, 2, 3, 4, 4};
//     cout << "Duplicate in nums2: " << sol.findDuplicate(nums2) << endl;

//     return 0;
// }




// Negative Marking
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         for (int num : nums) {
//             int idx = abs(num) - 1;
//             if (nums[idx] < 0) {
//                 return abs(num);
//             }
//             nums[idx] *= -1;
//         }
//         return -1;
//     }
// };

// int main() {
//     Solution sol;

//     // Example 1
//     vector<int> nums1 = {1, 2, 3, 2, 2};
//     cout << "Duplicate in nums1: " << sol.findDuplicate(nums1) << endl;

//     // Example 2
//     vector<int> nums2 = {1, 2, 3, 4, 4};
//     cout << "Duplicate in nums2: " << sol.findDuplicate(nums2) << endl;

//     return 0;
// }






//Binary Search 
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int low = 1, high = n - 1;
//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             int lessOrEqual = 0;
//             for (int i = 0; i < n; i++) {
//                 if (nums[i] <= mid) {
//                     lessOrEqual++;
//                 }
//             }

//             if (lessOrEqual <= mid) {
//                 low = mid + 1;
//             } else {
//                 high = mid;
//             }
//         }

//         return low;
//     }
// };

// int main() {
//     Solution sol;

//     // Example 1
//     vector<int> nums1 = {1, 2, 3, 2, 2};
//     cout << "Duplicate in nums1: " << sol.findDuplicate(nums1) << endl;

//     // Example 2
//     vector<int> nums2 = {1, 2, 3, 4, 4};
//     cout << "Duplicate in nums2: " << sol.findDuplicate(nums2) << endl;

//     return 0;
// }




// Bit Manipulation
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int res = 0;
//         for (int b = 0; b < 32; b++) {
//             int x = 0, y = 0;
//             int mask = 1 << b;
//             for (int num : nums) {
//                 if (num & mask) {
//                     x++;
//                 }
//             }
//             for (int num = 1; num < n; num++) {
//                 if (num & mask) {
//                     y++;
//                 }
//             }
//             if (x > y) {
//                 res |= mask;
//             }
//         }
//         return res;
//     }
// };

// int main() {
//     Solution sol;

//     // Example 1
//     vector<int> nums1 = {1, 2, 3, 2, 2};
//     cout << "Duplicate in nums1: " << sol.findDuplicate(nums1) << endl;

//     // Example 2
//     vector<int> nums2 = {1, 2, 3, 4, 4};
//     cout << "Duplicate in nums2: " << sol.findDuplicate(nums2) << endl;

//     return 0;
// }



// Fast And Slow Pointers
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        int slow2 = 0;
        while (true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) {
                return slow;
            }
        }
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 3, 2, 2};
    cout << "Duplicate in nums1: " << sol.findDuplicate(nums1) << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4, 4};
    cout << "Duplicate in nums2: " << sol.findDuplicate(nums2) << endl;

    return 0;
}
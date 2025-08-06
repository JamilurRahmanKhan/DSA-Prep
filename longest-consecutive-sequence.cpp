#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int longest = 1;
        int current = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else if(nums[i]==nums[i-1]+1){
                current++;
            }
            else{
                longest = max(longest, current);
                current = 1;
            }
        }
        return max(longest, current);
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0,1,2,3,10,11,12};
    int result = solution.longestConsecutive(nums);
    cout << "The Longest Consecutive Sequence is: " << result << endl;
}


// Sorting
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int res = 0;
//         unordered_set<int> store(nums.begin(), nums.end());

//         for (int num : nums) {
//             int streak = 0, curr = num;
//             while (store.find(curr) != store.end()) {
//                 streak++;
//                 curr++;
//             }
//             res = max(res, streak);
//         }
//         return res;
//     }
// };


// Hash Set
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> numSet(nums.begin(), nums.end());
//         int longest = 0;

//         for (int num : numSet) {
//             if (numSet.find(num - 1) == numSet.end()) {
//                 int length = 1;
//                 while (numSet.find(num + length) != numSet.end()) {
//                     length++;
//                 }
//                 longest = max(longest, length);
//             }
//         }
//         return longest;
//     }
// };


// Hash Map
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         int res = 0;

//         for (int num : nums) {
//             if (!mp[num]) {
//                 mp[num] = mp[num - 1] + mp[num + 1] + 1;
//                 mp[num - mp[num - 1]] = mp[num];
//                 mp[num + mp[num + 1]] = mp[num];
//                 res = max(res, mp[num]);
//             }
//         }
//         return res;
//     }
// };
// Brute Force
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
    vector<vector<int>> treeSum(vector<int>& nums){
        set<vector<int>> res;  
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                for(int k=j+1; k<nums.size(); k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        res.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());  
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = sol.treeSum(nums);

    for(auto v : result){
        for(int num : v){
            cout << num << " ";
        }
        cout << endl;
    }
}






// Two Pointers
// #include <iostream>
// #include <vector>
// #include <set>
// using namespace std;

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> res;

//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] > 0) break;
//             if (i > 0 && nums[i] == nums[i - 1]) continue;

//             int l = i + 1, r = nums.size() - 1;
//             while (l < r) {
//                 int sum = nums[i] + nums[l] + nums[r];
//                 if (sum > 0) {
//                     r--;
//                 } else if (sum < 0) {
//                     l++;
//                 } else {
//                     res.push_back({nums[i], nums[l], nums[r]});
//                     l++;
//                     r--;
//                     while (l < r && nums[l] == nums[l - 1]) {
//                         l++;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };




// Hash Map
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         unordered_map<int, int> count;
//         for (int num : nums) {
//             count[num]++;
//         }

//         vector<vector<int>> res;
//         for (int i = 0; i < nums.size(); i++) {
//             count[nums[i]]--;
//             if (i > 0 && nums[i] == nums[i - 1]) continue;

//             for (int j = i + 1; j < nums.size(); j++) {
//                 count[nums[j]]--;
//                 if (j > i + 1 && nums[j] == nums[j - 1]) continue;

//                 int target = -(nums[i] + nums[j]);
//                 if (count[target] > 0) {
//                     res.push_back({nums[i], nums[j], target});
//                 }
//             }

//             for (int j = i + 1; j < nums.size(); j++) {
//                 count[nums[j]]++;
//             }
//         }

//         return res;
//     }
// };
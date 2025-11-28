// ? include / exclude style
// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution
// {
// public:
//     vector<vector<int>> result;
//     void backtrack(int i, vector<int> &nums, vector<int> &temp)
//     {
//         if (i >= nums.size())
//         {
//             result.push_back(temp);
//             return;
//         }

//         temp.push_back(nums[i]);
//         backtrack(i + 1, nums, temp);
//         temp.pop_back();
//         backtrack(i + 1, nums, temp);
//     }

//     vector<vector<int>> subsets(vector<int> &nums)
//     {
//         vector<int> temp;
//         backtrack(0, nums, temp);

//         return result;
//     }
// };

// int main()
// {
//     Solution sol;

//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> ans = sol.subsets(nums);

//     cout << "Subsets:\n";
//     for (auto &subset : ans)
//     {
//         cout << "[";
//         for (int i = 0; i < (int)subset.size(); i++)
//         {
//             cout << subset[i];
//             if (i + 1 < (int)subset.size())
//                 cout << ",";
//         }
//         cout << "]\n";
//     }

//     return 0;
// }




// ? for-loop
// ? nums = [1,2,3]
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& result) {
        result.push_back(curr); 

        for (int i = index; i < (int)nums.size(); i++) {
            curr.push_back(nums[i]); 

            backtrack(i + 1, nums, curr, result); 

            curr.pop_back(); 
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(0, nums, curr, result);
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.subsets(nums);

    cout << "Subsets:\n";
    for (auto &subset : ans) {
        cout << "[";
        for (int i = 0; i < (int)subset.size(); i++) {
            cout << subset[i];
            if (i + 1 < (int)subset.size()) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    nums = {3, 4, 5, 6};
    int target = 8;

    vector<int> result = solution.twoSum(nums, target);
    if (!result.empty())
    {
        cout << "Output is i = " << result[0] << " and j = " << result[1] << endl;
        cout << "They are " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    }
    else
    {
        cout << "No pair found that adds up to the target" << endl;
    }
    return 0;
}



// // Sorting
// #include <iostream>
// #include <vector>
// using namespace std;
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<pair<int, int>> A;
//         for (int i = 0; i < nums.size(); i++) {
//             A.push_back({nums[i], i});
//         }

//         sort(A.begin(), A.end());

//         int i = 0, j = nums.size() - 1;
//         while (i < j) {
//             int cur = A[i].first + A[j].first;
//             if (cur == target) {
//                 return {min(A[i].second, A[j].second),
//                         max(A[i].second, A[j].second)};
//             } else if (cur < target) {
//                 i++;
//             } else {
//                 j--;
//             }
//         }
//         return {};
//     }
// };


// //Hash Map (Two Pass)
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> indices;  // val -> index

//         for (int i = 0; i < nums.size(); i++) {
//             indices[nums[i]] = i;
//         }

//         for (int i = 0; i < nums.size(); i++) {
//             int diff = target - nums[i];
//             if (indices.count(diff) && indices[diff] != i) {
//                 cout << "indices[diff]: " << indices[diff] << ", i: " << i << endl;
//                 return {i, indices[diff]};
//             }
//         }

//         return {};
//     }
// };

// int main()
// {
//     Solution solution;
//     vector<int> nums;
//     nums = {3, 3, 5, 6};
//     int target = 6;

//     vector<int> result = solution.twoSum(nums, target);
//     if (!result.empty())
//     {
//         cout << "Output is i = " << result[0] << " and j = " << result[1] << endl;
//         cout << "They are " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
//     }
//     else
//     {
//         cout << "No pair found that adds up to the target" << endl;
//     }
//     return 0;
// }
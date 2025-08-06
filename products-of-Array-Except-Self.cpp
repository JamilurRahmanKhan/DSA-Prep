// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;

// class Solution
// {
// public:
//     vector<int> productExceptSelf(vector<int> &nums)
//     {
//         map<int, int> mapping;
//         vector<int> result;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int key = nums[i];
//             int product = 1;

//             for (int j = 0; j < nums.size(); j++)
//             {
//                 if (i != j)
//                 {
//                     product *= nums[j];
//                 }
//             }
//             result.push_back(product);
//         }
//         return result;
//     }
// };

// int main()
// {
//     Solution solution;
//     vector<int> nums = {1, 2, 4, 6};
//     vector<int> result = solution.productExceptSelf(nums);

//     cout << "Product except self for each element:" << endl;
//     for (int val : result)
//     {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }









#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);

        for(int i = 1; i<n; i++){
            res[i] = res[i-1] * nums[i-1];
        }

        int postfix = 1;
        for(int i = n-1; i>=0; i--){
            res[i] = res[i] * postfix;
            postfix = postfix * nums[i];
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 6, 8};
    vector<int> result = solution.productExceptSelf(nums);

    cout << "Product except self for each element:" << endl;
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
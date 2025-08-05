//Hash Set
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
        unordered_set<int> seen;

        for (int num : nums)
        {
            
            if (seen.count(num))
            {
                return true; 
            }
            seen.insert(num); 
        }

        return false; 
    }
};

int main()
{
    Solution solution;
    vector<int> input = {10, 20, 30, 10}; 

    if (solution.hasDuplicate(input))
    {
        cout << "Duplicate found" << endl;
    }
    else
    {
        cout << "Duplicate not found" << endl;
    }

    return 0;
}




// #include <iostream>
// using namespace std;

// bool hasDuplicate(int nums[], int n)
// {
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (nums[i] == nums[j])
//             {
//                 count++;
//             }
//             cout << "i and j: " << nums[i] << " " << nums[j] << endl;
//         }
//         if (count > 0)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// int main()
// {
//     int n = 4;
//     int nums[4] = {10, 20, 30, 31};
//     cout << "The values are: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << nums[i] << endl;
//     }

//     if (hasDuplicate(nums, n) == true)
//     {
//         cout << "Duplicate found" << endl;
//     }
//     else
//     {
//         cout << "Duplicate not found" << endl;
//     }

//     return 0;
// }


// //Brute Force
// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums)
//     {
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 if (nums[i] == nums[j])
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// int main()
// {
//     Solution solution;
//     vector<int> input = {10, 20, 30, 31};

//     if (solution.hasDuplicate(input))
//     {
//         cout << "Duplicate found" << endl;
//     }
//     else
//     {
//         cout << "Duplicate not found" << endl;
//     }

//     return 0;
// }


// // Sorting
// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] == nums[i - 1]) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };


// //Hash Set Length
// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
//         return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
//     }
// };




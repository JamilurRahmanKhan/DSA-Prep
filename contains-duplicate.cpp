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


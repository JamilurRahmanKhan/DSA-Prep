#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum > target) {
                r--;
            }
            else if (sum < target) {
                l++;
            }
            else {
                return {l + 1, r + 1}; 
            }
        }
        return {};
    }
};

int main() {
    Solution sol;

    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(numbers, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
// ? Brute Force
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n * n;

        vector<int> freq(m + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                freq[val]++;
            }
        }

        int repeated = -1;
        int missing = -1;

        for (int v = 1; v <= m; v++) {
            if (freq[v] == 2) {
                repeated = v;
            } 
            else if (freq[v] == 0) {
                missing = v;
            }
        }

        return {repeated, missing};
    }
};

int main() {
    Solution sol;

    // Example Test Case 1
    vector<vector<int>> grid1 = {
        {1, 3},
        {2, 2}
    };

    vector<int> ans1 = sol.findMissingAndRepeatedValues(grid1);
    cout << "Output: [" << ans1[0] << ", " << ans1[1] << "]" << endl;

    // Example Test Case 2
    vector<vector<int>> grid2 = {
        {9, 1, 7},
        {8, 9, 2},
        {3, 4, 6}
    };

    vector<int> ans2 = sol.findMissingAndRepeatedValues(grid2);
    cout << "Output: [" << ans2[0] << ", " << ans2[1] << "]" << endl;

    return 0;
}

// ? Optimal

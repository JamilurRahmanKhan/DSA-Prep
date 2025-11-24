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
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    long long N = 1LL * n * n;  // total numbers from 1 to n^2

    long long sumActual = 0;     // sum of all values in grid
    long long sumSqActual = 0;   // sum of squares of all values in grid

    // Compute actual sum and sum of squares
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long val = grid[i][j];
            sumActual += val;
            sumSqActual += val * val;
        }
    }

    // Expected sum and sum of squares for 1..N
    long long sumExpected = N * (N + 1) / 2;
    long long sumSqExpected = N * (N + 1) * (2 * N + 1) / 6;

    // diff1 = a - b, diff2 = a^2 - b^2 = (a - b)(a + b)
    long long diff1 = sumActual - sumExpected;
    long long diff2 = sumSqActual - sumSqExpected;

    long long sumAB = diff2 / diff1;  // a + b

    long long a = (diff1 + sumAB) / 2;  // repeated
    long long b = a - diff1;            // missing

    return { (int)a, (int)b };
}
#include <iostream>     // for cout, cin
#include <vector>       // for vector
#include <queue>        // for queue
#include <utility>      // for pair
#include <algorithm>    // for max
#include <climits>      // for INT_MAX

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        queue<pair<pair<int,int>, int>> q; 
        int fresh = 0;

        // Step 1: Find all rotten oranges and count fresh ones
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) 
                    q.push({{i, j}, 0});
                else if (grid[i][j] == 1) 
                    ++fresh;
            }
        }

        // Step 2: If no fresh oranges, no time needed
        if (fresh == 0) return 0;

        // Step 3: Prepare 4 directions (Up, Right, Down, Left)
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int ans = 0;

        // Step 4: BFS — Spread rot minute by minute
        while (!q.empty()) {
            auto [pos, t] = q.front(); 
            q.pop();
            auto [i, j] = pos;
            ans = max(ans, t);

            for (int d = 0; d < 4; ++d) {
                int x = i + dirs[d];
                int y = j + dirs[d + 1];

                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                    grid[x][y] = 2;      // rot this fresh orange
                    --fresh;             // decrease fresh count
                    q.push({{x, y}, t + 1});
                }
            }
        }

        // Step 5: Return time if all rotted, else -1
        return (fresh == 0) ? ans : -1;
    }
};

// Helper function to print grid
void printGrid(const vector<vector<int>>& grid) {
    for (auto& row : grid) {
        for (int cell : row)
            cout << cell << " ";
        cout << "\n";
    }
    cout << "----\n";
}

// Driver function
int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout << "Before:\n";
    printGrid(grid);

    Solution sol;
    int result = sol.orangesRotting(grid);

    cout << "After:\n";
    printGrid(grid);
    cout << "Minimum minutes to rot all fruits: " << result << endl;

    return 0;
}
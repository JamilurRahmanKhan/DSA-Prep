// DFS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int m, n;

    // Depth First Search helper function
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // Base case: Out of bounds, water, or already visited
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;

        // Mark current cell as visited
        grid[i][j] = 0;

        // Start area count for this cell
        int area = 1;

        // Explore all 4 directions
        area += dfs(grid, i + 1, j); // down
        area += dfs(grid, i - 1, j); // up
        area += dfs(grid, i, j + 1); // right
        area += dfs(grid, i, j - 1); // left

        return area;
    }

    // Main function to find the maximum area of an island
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;

        // Traverse the entire grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};

// ---------------- DRIVER CODE ----------------
int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0,1,1,0,1},
        {1,0,1,0,1},
        {0,1,1,0,1},
        {0,1,0,0,1}
    };

    int result = sol.maxAreaOfIsland(grid);
    cout << "Maximum Area of Island: " << result << endl;

    return 0;
}



// BFS
// 0 1 1 0 1
// 1 0 1 0 1
// 0 1 1 0 1
// 0 1 0 0 1
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = 0; // mark visited

        int area = 1; // count the starting cell

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                // check bounds and unvisited land
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    que.push({nx, ny});
                    grid[nx][ny] = 0; // mark visited
                    area++; // increase island area
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = bfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
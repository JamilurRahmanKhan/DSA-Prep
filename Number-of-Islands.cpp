// DFS
#include <iostream>
#include <vector>

using namespace std;

/*
    Problem: Number of Islands
    Idea: Use DFS to traverse the grid. Every time we find a '1' (land), 
          we perform DFS to mark all connected lands as visited. 
          Each DFS corresponds to one island.
*/

class Solution {
public:
    int m;  // number of rows
    int n;  // number of columns

    // DFS helper function
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Base cases: out of bounds or water cell
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
            return;
        }

        // Mark the cell as visited
        grid[i][j] = 's';

        // Explore all 4 directions
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }

    // Main function to count islands
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islandCount++; // Found one island
                }
            }
        }
        return islandCount;
    }
};

// ------------ DRIVER CODE ------------
int main() {
    // Example grid
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution sol;
    int result = sol.numIslands(grid);

    cout << "Number of islands: " << result << endl;

    return 0;
}









// BFS
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<char>>& grid, int i, int j){

        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = 's';

        while(!que.empty()){
            auto it = que.front();
            que.pop();

            for(auto &dir: directions){
                int i_ = it.first + dir[0];
                int j_ = it.second + dir[1];

                if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] != '1'){
                    continue;
                } else {
                    que.push({i_, j_});
                    grid[i_][j_] = 's';
                }
            }
        }
    }

    // Main function to count islands
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    islandCount++; // Found one island
                }
            }
        }
        return islandCount;
    }
};


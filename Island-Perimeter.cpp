// DFS
#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Island Perimeter
    Idea: Use DFS to count the total perimeter of an island in a binary grid.
          Each land cell contributes to the perimeter for every side that touches water or the boundary.
*/

class Solution {
public:
    int m;          // number of rows
    int n;          // number of columns
    int peri;       // stores total perimeter

    // Depth First Search helper
    void dfs(vector<vector<int>>& grid, int i, int j) {
        // Base case 1: Out of bounds → contributes 1 to perimeter
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            peri++;
            return;
        }

        // Base case 2: Already visited
        if (grid[i][j] == -1) return;

        // Mark current cell as visited
        grid[i][j] = -1;

        // Explore all 4 directions
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }

    // Main function to find island perimeter
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        peri = 0;

        // Find first land cell and start DFS
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return peri; // Return after finding one island
                }
            }
        }
        return 0; // No island
    }
};

// ------------ DRIVER CODE ------------
int main() {
    // Example test case
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    Solution sol;
    int result = sol.islandPerimeter(grid);

    cout << "Island Perimeter: " << result << endl;

    return 0;
}





// BFS
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int bfs(vector<vector<int>>& grid, int i, int j){
        int perim = 0;

        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = -1;

        while(!que.empty()){
            auto it = que.front();
            que.pop();

            for(auto &dir: directions){
                int i_ = it.first + dir[0];
                int j_ = it.second + dir[1];

                if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] == 0)
                    perim++;
                else if(grid[i_][j_] == -1) {
                    continue;
                } else {
                    que.push({i_, j_});
                    grid[i_][j_] = -1;
                }
            }
        }
        return perim;

    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    return bfs(grid, i, j);
                }
            }
        }
        return 0;
    }
};




// Iterative

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int perimeter = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0)
                    continue;
                
                if(i-1 < 0 || grid[i-1][j] == 0) //up
                    perimeter++;
                
                if(i+1 >= m || grid[i+1][j] == 0) //down
                    perimeter++;
                
                if(j-1 < 0 || grid[i][j-1] == 0) //left
                    perimeter++;
                
                if(j+1 >= n || grid[i][j+1] == 0) //right
                    perimeter++;
                
            }
        }
        
        return perimeter;
    }
};


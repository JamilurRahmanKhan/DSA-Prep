#include <iostream>
#include <vector>
#include <queue>
#include <climits>  // For INT_MAX

using namespace std;

class Solution {
public:
    // Multi-source BFS from all 0's (gates); fill each INT_MAX cell with min distance.
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return;
        int n = grid[0].size();
        queue<pair<int, int>> q;

        // Push all gates (0s)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }

        // BFS level by level
        int d = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1}; // 4-neighbors
        while (!q.empty()) {
            ++d;
            for (int k = q.size(); k > 0; --k) {
                auto p = q.front(); q.pop();
                for (int j = 0; j < 4; ++j) {
                    int x = p.first  + dirs[j];
                    int y = p.second + dirs[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == INT_MAX) {
                        grid[x][y] = d;
                        q.emplace(x, y);
                    }
                }
            }
        }
    }
};

// ---------- Helpers for demo ----------
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int v : row) {
            if (v == INT_MAX) cout << "INF ";
            else               cout << v << " ";
        }
        cout << "\n";
    }
    cout << "----\n";
}

int main() {
    // Convention:
    //  -1 = wall, 0 = gate, INT_MAX = empty room (INF)
    vector<vector<int>> grid = {
        {INT_MAX, -1,      0,      INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1     },
        {INT_MAX, -1,      INT_MAX, -1     },
        {0,       -1,      INT_MAX, INT_MAX}
    };

    cout << "Before:\n";
    printGrid(grid);

    Solution sol;
    sol.islandsAndTreasure(grid);

    cout << "After:\n";
    printGrid(grid);

    return 0;
}
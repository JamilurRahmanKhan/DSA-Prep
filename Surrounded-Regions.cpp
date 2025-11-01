#include <iostream>
#include <vector>
using namespace std;

// Class containing the solution
class Solution {
public:
    // Function that modifies the given board in-place
    void solve(vector<vector<char>>& board) {
        // Edge case: empty board
        if (board.empty()) return;

        // m = number of rows, n = number of columns
        int m = board.size(), n = board[0].size();

        // ------------------------------
        // STEP 1: MARK BORDER-CONNECTED 'O's
        // ------------------------------
        // Traverse the entire border of the grid.
        // If an 'O' is found on any border, run DFS from there.
        // That DFS will mark all connected 'O's (that can "reach" the border)
        // as safe ('T'), so they won't be flipped later.

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Check if the cell is on a border
                bool isBorder = (i == 0 || i == m - 1 || j == 0 || j == n - 1);
                // Start DFS only for border 'O's
                if (isBorder && board[i][j] == 'O') {
                    dfs(board, i, j); // mark all connected O's as safe
                }
            }
        }

        // ------------------------------
        // STEP 2: FLIP THE REGIONS
        // ------------------------------
        // Now, we have three types of cells:
        //  1. 'O' = trapped (not connected to border) → flip to 'X'
        //  2. 'T' = safe (connected to border) → restore to 'O'
        //  3. 'X' = already wall → no change

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    // These 'O's were not marked → they are surrounded → flip
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    // These were marked as safe → restore them
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    // ------------------------------
    // Depth-First Search helper
    // ------------------------------
    // Purpose: mark all connected 'O's (safe cells) with 'T'
    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size(), n = board[0].size();

        // Boundary check: stop if out of grid OR not an 'O'
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
            return;

        // Mark current cell as safe (temporary 'T')
        board[i][j] = 'T';

        // Recursively explore 4 neighboring directions
        dfs(board, i + 1, j); // Down
        dfs(board, i - 1, j); // Up
        dfs(board, i, j + 1); // Right
        dfs(board, i, j - 1); // Left
    }
};

// ---- Demo driver ----
int main() {
    // Input board
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    Solution sol;
    sol.solve(board); // process the board

    // Print final result
    cout << "Final board:\n";
    for (auto &row : board) {
        for (char c : row) cout << c << ' ';
        cout << endl;
    }

    return 0;
}
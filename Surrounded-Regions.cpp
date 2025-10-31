#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        int m = board.size(), n = board[0].size();

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                bool isBorder = (i == 0 || i == m-1 || j == 0 || j == n-1);
                if(isBorder && board[i][j] == 'O'){
                    dfs(board, i,j);
                }
            }
        }

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size(), n = board[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;

        board[i][j] = 'T';

        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};

// ---- Demo driver ----
int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    Solution sol;
    sol.solve(board);

    cout << "Final board:\n";
    for (auto &row : board) {
        for (char c : row) cout << c << ' ';
        cout << endl;
    }

    return 0;
}
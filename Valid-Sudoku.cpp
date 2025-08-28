#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // ✅ Check rows
        for (int i = 0; i < 9; i++) {
            vector<bool> seen(10, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (seen[num]) return false;
                    seen[num] = true;
                }
            }
        }

        // ✅ Check columns
        for (int j = 0; j < 9; j++) {
            vector<bool> seen(10, false);
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (seen[num]) return false;
                    seen[num] = true;
                }
            }
        }

        // ✅ Check 3x3 subgrids
        for (int blockRow = 0; blockRow < 9; blockRow += 3) {
            for (int blockCol = 0; blockCol < 9; blockCol += 3) {
                vector<bool> seen(10, false);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[blockRow + i][blockCol + j];
                        if (c != '.') {
                            int num = c - '0';
                            if (seen[num]) return false;
                            seen[num] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    // ✅ Example Sudoku board
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (sol.isValidSudoku(board)) {
        cout << "✅ The Sudoku board is valid!" << endl;
    } else {
        cout << "❌ The Sudoku board is invalid!" << endl;
    }

    return 0;
}







// Brute Force
// #include <iostream>
// #include <unordered_set>
// using namespace std;

// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         for (int row = 0; row < 9; row++) {
//             unordered_set<char> seen;
//             for (int i = 0; i < 9; i++) {
//                 if (board[row][i] == '.') continue;
//                 if (seen.count(board[row][i])) return false;
//                 seen.insert(board[row][i]);
//             }
//         }

//         for (int col = 0; col < 9; col++) {
//             unordered_set<char> seen;
//             for (int i = 0; i < 9; i++) {
//                 if (board[i][col] == '.') continue;
//                 if (seen.count(board[i][col])) return false;
//                 seen.insert(board[i][col]);
//             }
//         }

//         for (int square = 0; square < 9; square++) {
//             unordered_set<char> seen;
//             for (int i = 0; i < 3; i++) {
//                 for (int j = 0; j < 3; j++) {
//                     int row = (square / 3) * 3 + i;
//                     int col = (square % 3) * 3 + j;
//                     if (board[row][col] == '.') continue;
//                     if (seen.count(board[row][col])) return false;
//                     seen.insert(board[row][col]);
//                 }
//             }
//         }

//         return true;
//     }
// };

// int main() {
//     Solution sol;

//     // ✅ Example Sudoku board
//     vector<vector<char>> board = {
//         {'5','3','.','.','7','.','.','.','.'},
//         {'6','.','.','1','9','5','.','.','.'},
//         {'.','9','8','.','.','.','.','6','.'},
//         {'8','.','.','.','6','.','.','.','3'},
//         {'4','.','.','8','.','3','.','.','1'},
//         {'7','.','.','.','2','.','.','.','6'},
//         {'.','6','.','.','.','.','2','8','.'},
//         {'.','.','.','4','1','9','.','.','5'},
//         {'.','.','.','.','8','.','.','7','9'}
//     };

//     if (sol.isValidSudoku(board)) {
//         cout << "✅ The Sudoku board is valid!" << endl;
//     } else {
//         cout << "❌ The Sudoku board is invalid!" << endl;
//     }

//     return 0;
// }








// Hash Set (One Pass)
// #include <iostream>        // for input/output
// #include <vector>          // for vector
// #include <unordered_map>   // for unordered_map
// #include <unordered_set>   // for unordered_set
// #include <map>             // for map
// #include <utility>         // for pair
// using namespace std;

// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         unordered_map<int, unordered_set<char>> rows, cols;
//         map<pair<int, int>, unordered_set<char>> squares;

//         for (int r = 0; r < 9; r++) {
//             for (int c = 0; c < 9; c++) {
//                 if (board[r][c] == '.') continue;

//                 pair<int, int> squareKey = {r / 3, c / 3};

//                 if (rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || squares[squareKey].count(board[r][c])) {
//                     return false;
//                 }

//                 rows[r].insert(board[r][c]);
//                 cols[c].insert(board[r][c]);
//                 squares[squareKey].insert(board[r][c]);
//             }
//         }
//         return true;
//     }
// };

// int main() {
//     Solution sol;

//     // ✅ Example Sudoku board
//     vector<vector<char>> board = {
//         {'5','3','.','.','7','.','.','.','.'},
//         {'6','.','.','1','9','5','.','.','.'},
//         {'.','9','8','.','.','.','.','6','.'},
//         {'8','.','.','.','6','.','.','.','3'},
//         {'4','.','.','8','.','3','.','.','1'},
//         {'7','.','.','.','2','.','.','.','6'},
//         {'.','6','.','.','.','.','2','8','.'},
//         {'.','.','.','4','1','9','.','.','5'},
//         {'.','.','.','.','8','.','.','7','9'}
//     };

//     if (sol.isValidSudoku(board)) {
//         cout << "✅ The Sudoku board is valid!" << endl;
//     } else {
//         cout << "❌ The Sudoku board is invalid!" << endl;
//     }

//     return 0;
// }
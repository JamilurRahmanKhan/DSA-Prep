#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m * n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int row = mid / n;   // find row index
            int col = mid % n;   // find col index

            if (matrix[row][col] < target) {
                start = mid + 1;
            } else if (matrix[row][col] > target) {
                end = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Found " << target << " in matrix!" << endl;
    } else {
        cout << target << " not found in matrix." << endl;
    }

    return 0;
}









// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int i=0, j=n-1;
//         while(i<m && j>=0){
//             if(matrix[i][j] > target){
//                 j--;
//             }else if(matrix[i][j] < target){
//                 i++;
//             }else{
//                 return true;
//             }
//         }
//         return false;
//     }
// };

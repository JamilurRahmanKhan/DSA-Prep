#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {

                // Check if row j exists
                if (j >= n) return false;

                // Check if column i exists in row j
                if (i >= words[j].size()) return false;

                // Compare characters
                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<string> words1 = {"abcd", "bnrt", "crmy", "dtye"};
    cout << "Test Case 1: "
         << (sol.validWordSquare(words1) ? "true" : "false") << endl;

    // Test Case 2
    vector<string> words2 = {"abcd", "bnrt", "crm", "dt"};
    cout << "Test Case 2: "
         << (sol.validWordSquare(words2) ? "true" : "false") << endl;

    // Test Case 3
    vector<string> words3 = {"ball", "area", "read", "lady"};
    cout << "Test Case 3: "
         << (sol.validWordSquare(words3) ? "true" : "false") << endl;

    return 0;
}
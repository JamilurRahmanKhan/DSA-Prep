// Brute Force
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(string &t1, string &t2, int i, int j) {
        if (i == t1.size() || j == t2.size())
            return 0;

        if (t1[i] == t2[j])
            return 1 + solve(t1, t2, i + 1, j + 1);

        int skip1 = solve(t1, t2, i + 1, j);
        int skip2 = solve(t1, t2, i, j + 1);

        return max(skip1, skip2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, 0, 0);
    }
};

int main() {
    Solution sol;

    string text1 = "cat";
    string text2 = "crabt";

    cout << sol.longestCommonSubsequence(text1, text2) << endl; // Expected output: 3

    return 0;
}
/*
text1 = "axbc"
text2 = "abc"

solve(0,0)  [a vs a, match]
  → 1 + solve(1,1)
                 solve(1,1) [x vs b, mismatch]
                    ├─ solve(2,1)  // skip x
                    │      [b vs b, match]
                    │      → 1 + solve(3,2)
                    │               solve(3,2) [c vs c, match]
                    │                   → 1 + solve(4,3)
                    │                             solve(4,3) = 0 (base)
                    │               ⇒ solve(3,2) = 1
                    │      ⇒ solve(2,1) = 1 + 1 = 2
                    │
                    └─ solve(1,2)  // skip b
                           [x vs c, mismatch]
                           ├─ solve(2,2)  // skip x
                           │     [b vs c, mismatch]
                           │     ├─ solve(3,2) = 1  (from above)
                           │     └─ solve(2,3) = 0 (base)
                           │     ⇒ solve(2,2) = max(1,0) = 1
                           │
                           └─ solve(1,3) = 0 (base)
                           ⇒ solve(1,2) = max(1,0) = 1

                 ⇒ solve(1,1) = max(2,1) = 2

⇒ solve(0,0) = 1 + 2 = 3
*/



// Optimal DP Solution
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution sol;
    cout << sol.longestCommonSubsequence("axbc", "abc") << endl; // Output: 3
    cout << sol.longestCommonSubsequence("cat", "crabt") << endl; // Output: 3
}
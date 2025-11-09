//? Brute Force
#include <iostream>      // for input-output
#include <vector>        // for using std::vector
#include <string>        // for using std::string
#include <algorithm>     // for using std::min, std::max
using namespace std;

class Solution {
public:
    // Check if substring s[l...r] is palindrome
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    // Find the longest palindromic substring
    string longestPalindrome(string s) {
        int n = s.size();
        string best = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    string sub = s.substr(i, j - i + 1);
                    if (sub.size() > best.size())
                        best = sub;
                }
            }
        }
        return best;
    }
};

// ---- Demo driver ----
int main() {
    Solution sol;

    cout << sol.longestPalindrome("ababd") << endl; // Output: "aba" or "bab"
    cout << sol.longestPalindrome("abbc") << endl;  // Output: "bb"
    return 0;
}



//? DP
class Solution {
public:
    string longestPalindrome(string s) {
        int resIdx = 0, resLen = 0;
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || dp[i + 1][j - 1])) {

                    dp[i][j] = true;
                    if (resLen < (j - i + 1)) {
                        resIdx = i;
                        resLen = j - i + 1;
                    }
                }
            }
        }

        return s.substr(resIdx, resLen);
    }
};
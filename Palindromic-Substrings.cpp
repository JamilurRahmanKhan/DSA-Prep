// ? Brute Force
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l; 
        --r;
    }
    return true;
}

int countSubstrings(const string& s) {
    int n = (int)s.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {       
            if (isPalindrome(s, i, j)) ++count;
        }
    }
    return count;
}

// Demo
int main() {
    cout << countSubstrings("abc") << "\n"; // 3  -> "a","b","c"
    cout << countSubstrings("aaa") << "\n"; // 6  -> "a","a","a","aa","aa","aaa"
    cout << countSubstrings("ababd") << "\n"; // 7 -> singles + "aba","bab"
    return 0;
}




// ? DP
class Solution {
public:
    int countSubstrings(string s) {
        int n = (int)s.size();
        if (n == 0) return 0;

        // dp[i][j] = true if s[i..j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;

        // Fill by increasing substring length: i goes backward, j goes forward
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    // length 1 or 2 are easy; longer needs inner to be palindrome
                    if (j - i <= 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};

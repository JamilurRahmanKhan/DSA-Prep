// ? Brute Force
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int dfs(int i, string& s) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;

        int res = dfs(i + 1, s);
        if (i < s.size() - 1) {
            if (s[i] == '1' ||
               (s[i] == '2' && s[i + 1] < '7')) {
                res += dfs(i + 2, s);
            }
        }
        return res;
    }

    int numDecodings(string s) {
        return dfs(0, s);
    }
};

// ---- Demo ----
int main()
{
    Solution sol;
    cout << sol.numDecodings("12") << endl;   // Output: 2 → "AB", "L"
    cout << sol.numDecodings("226") << endl;  // Output: 3 → "BBF", "BZ", "VF"
    cout << sol.numDecodings("1012") << endl; // Output: 2 → "JAB", "JL"
    cout << sol.numDecodings("01") << endl;   // Output: 0 (invalid)
    return 0;
}


//? DP
class Solution {
public:
    int dfs(string& s, int i, unordered_map<int, int>& dp){
        if (dp.count(i)) {
            return dp[i];
        }
        if (s[i] == '0') {
            return 0;
        }

        int res = dfs(s, i + 1, dp);
        if (i + 1 < s.size() && (s[i] == '1' ||
            s[i] == '2' && s[i + 1] < '7')) {
            res += dfs(s, i + 2, dp);
        }
        dp[i] = res;
        return res;
    }
    int numDecodings(string s) {
        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        return dfs(s,0,dp);
    }
};

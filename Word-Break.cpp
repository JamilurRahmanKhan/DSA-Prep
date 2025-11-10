// ? Brute Force
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool solve(string s, unordered_set<string>& dict) {
        if (s.empty()) return true;  

        for (int i = 1; i <= s.size(); i++) {
            string prefix = s.substr(0, i);   
            string rest = s.substr(i);       

            if (dict.count(prefix) && solve(rest, dict)) {
                return true;
            }
        }
        return false;  
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(s, dict);
    }
};

int main() {
    Solution sol;
    vector<string> dict = {"neet", "code"};
    string s = "neetcode";
    cout << (sol.wordBreak(s, dict) ? "true" : "false");
}




// ? Dynamic Programming (Bottom-Up)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int maxLen = 0;
        for (auto &w : wordDict) maxLen = max(maxLen, (int)w.size());

        vector<bool> dp(n + 1, false);
        dp[0] = true; 

        for (int i = 1; i <= n; ++i) {
            for (int j = max(0, i - maxLen); j < i; ++j) {
                if (dp[j]) {
                    if (dict.count(s.substr(j, i - j))) {
                        dp[i] = true;
                        break; 
                    }
                }
            }
        }
        return dp[n];
    }
};
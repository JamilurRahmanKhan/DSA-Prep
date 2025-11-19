#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix;
        int n = strs.size();

        // Iterate over each character position of the first string
        for (int j = 0; j < (int)strs[0].size(); j++) {
            char c = strs[0][j];  // character to match in all strings

            // Compare this character with the same position in other strings
            for (int i = 1; i < n; i++) {
                // If this string is too short or character doesn't match
                if (j >= (int)strs[i].size() || strs[i][j] != c) {
                    return prefix; // current prefix is the answer
                }
            }

            // If all strings have the same character at position j, add it
            prefix.push_back(c);
        }

        return prefix; // first string is fully a common prefix
    }
};

int main() {
    Solution sol;

    vector<string> strs1 = {"bat", "bag", "bank", "band"};
    cout << "Input: [\"bat\",\"bag\",\"bank\",\"band\"] -> Output: \""
         << sol.longestCommonPrefix(strs1) << "\"" << endl;

    vector<string> strs2 = {"dance", "dag", "danger", "damage"};
    cout << "Input: [\"dance\",\"dag\",\"danger\",\"damage\"] -> Output: \""
         << sol.longestCommonPrefix(strs2) << "\"" << endl;

    vector<string> strs3 = {"neet", "feet"};
    cout << "Input: [\"neet\",\"feet\"] -> Output: \""
         << sol.longestCommonPrefix(strs3) << "\"" << endl;

    vector<string> strs4 = {"", "abc", "abd"};
    cout << "Input: [\"\",\"abc\",\"abd\"] -> Output: \""
         << sol.longestCommonPrefix(strs4) << "\"" << endl;

    return 0;
}
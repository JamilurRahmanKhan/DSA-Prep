#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        int diff = 0;

        for (auto& s : strings) {
            string key;

            if (s.size() == 1) {
                // All single letters form the same group ("a", "z", "d", ...)
                key = "single";
            } else {
                // Build difference pattern key
                for (int i = 1; i < s.size(); i++) {
                    diff = (s[i] - s[i - 1] + 26) % 26;
                    key += to_string(diff) + '#';
                }
            }

            // Group by pattern key
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (const auto& pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<string> input = {"abc","bcd","acef","xyz","az","ba","a","z","drwt"};
    
    vector<vector<string>> groups = sol.groupStrings(input);

    cout << "Grouped Shifted Strings:\n";
    for (const auto& group : groups) {
        cout << "[ ";
        for (const auto& s : group) {
            cout << s << " ";
        }
        cout << "]\n";
    }

    return 0;
}
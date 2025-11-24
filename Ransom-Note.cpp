// ? Brute Force
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Brute force: For every character in ransomNote,
        // search for it in magazine and mark it used.

        for (char r : ransomNote) {
            bool found = false;

            for (int j = 0; j < magazine.size(); j++) {
                if (magazine[j] == r) {
                    magazine[j] = '#'; // mark used
                    found = true;
                    break;
                }
            }

            if (!found) {
                return false; // letter not found
            }
        }

        return true; // all letters found
    }
};

int main() {
    Solution sol;

    cout << sol.canConstruct("aa", "aab") << endl;  // true
    cout << sol.canConstruct("aa", "ab") << endl;   // false
    cout << sol.canConstruct("abc", "cba") << endl; // true

    return 0;
}


// ? Optimal
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);

        // Count magazine letters
        for (char c : magazine) {
            freq[c - 'a']++;
        }

        // Consume ransomNote letters
        for (char c : ransomNote) {
            if (--freq[c - 'a'] < 0) {
                return false; // Not enough letters
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.canConstruct("aa", "aab") << endl;  // true
    cout << sol.canConstruct("aa", "ab") << endl;   // false

    return 0;
}
// ? Brute Force
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            bool isUnique = true;

            for (int j = 0; j < n; j++) {
                if (i != j && s[i] == s[j]) {
                    isUnique = false;
                    break;
                }
            }

            if (isUnique) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "neetcodeislove";
    string s2 = "neetcodeneet";
    string s3 = "baab";
    string s4 = "aabbccddee";
    string s5 = "leetcode";

    cout << "Input: " << s1 << " -> Output: " << sol.firstUniqChar(s1) << endl;
    cout << "Input: " << s2 << " -> Output: " << sol.firstUniqChar(s2) << endl;
    cout << "Input: " << s3 << " -> Output: " << sol.firstUniqChar(s3) << endl;
    cout << "Input: " << s4 << " -> Output: " << sol.firstUniqChar(s4) << endl;
    cout << "Input: " << s5 << " -> Output: " << sol.firstUniqChar(s5) << endl;

    return 0;
}

// ? Opmital
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        // First pass: count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Second pass: find the first index with frequency 1
        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
// ? Brute Force
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        string base = words[0];

        for (char c : base) {
            bool ok = true;

            for (int i = 1; i < (int)words.size(); i++) {
                size_t pos = words[i].find(c);
                if (pos == string::npos) {
                    ok = false;   
                    break;
                } else {
                    words[i].erase(pos, 1);
                }
            }

            if (ok) {
                result.push_back(string(1, c));
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> words1 = {"bella", "label", "roller"};
    vector<string> res1 = sol.commonChars(words1);
    cout << "Example 1 output: ";
    for (auto &s : res1) {
        cout << s << " ";
    }
    cout << endl;

    vector<string> words2 = {"cool", "lock", "cook"};
    vector<string> res2 = sol.commonChars(words2);
    cout << "Example 2 output: ";
    for (auto &s : res2) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}



// ? Optimized
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Step 1: freq of first word
        vector<int> commonFreq(26, 0);
        for (char c : words[0]) {
            commonFreq[c - 'a']++;
        }

        // Step 2: for each next word, intersect frequencies
        for (int w = 1; w < (int)words.size(); w++) {
            vector<int> currFreq(26, 0);
            for (char c : words[w]) {
                currFreq[c - 'a']++;
            }
            // keep minimum count across all words seen so far
            for (int i = 0; i < 26; i++) {
                commonFreq[i] = min(commonFreq[i], currFreq[i]);
            }
        }

        // Step 3: build result
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (commonFreq[i] > 0) {
                result.push_back(string(1, 'a' + i));
                commonFreq[i]--;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> words1 = {"bella","label","roller"};
    vector<string> res1 = sol.commonChars(words1);
    cout << "Example 1: ";
    for (auto &s : res1) cout << s << " ";
    cout << endl;

    vector<string> words2 = {"cool","lock","cook"};
    vector<string> res2 = sol.commonChars(words2);
    cout << "Example 2: ";
    for (auto &s : res2) cout << s << " ";
    cout << endl;

    return 0;
}
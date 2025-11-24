// ? Brute Force
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Split s into words
        vector<string> words;
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        words.push_back(temp); 

        // If size mismatch → impossible
        if (pattern.size() != words.size()) return false;

        int n = pattern.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (pattern[i] == pattern[j]) {
                    // same letter → words must match
                    if (words[i] != words[j]) return false;
                } else {
                    // different letters → words must NOT match
                    if (words[i] == words[j]) return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    cout << boolalpha;
    cout << sol.wordPattern("abba", "dog cat cat dog") << endl; // true
    cout << sol.wordPattern("abba", "dog cat cat fish") << endl; // false
    cout << sol.wordPattern("aaaa", "dog cat cat dog") << endl; // false

    return 0;
}


// ? Ompital
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Split s into words
        vector<string> words;
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        words.push_back(temp); 

        // If counts don't match, impossible
        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            // If c already mapped, must match same word
            if (charToWord.count(c)) {
                if (charToWord[c] != w) return false;
            } else {
                charToWord[c] = w;
            }

            // If word already mapped, must match same char
            if (wordToChar.count(w)) {
                if (wordToChar[w] != c) return false;
            } else {
                wordToChar[w] = c;
            }
        }

        return true;
    }
};
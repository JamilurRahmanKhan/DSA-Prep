// ? Brute Force
#include <iostream>
#include <string>
#include <cmath>    // for abs

using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int totalTime = 0;
        int prevIndex = 0; 

        for (char c : word) {
            int curIndex = 0;
            for (int i = 0; i < 26; i++) {
                if (keyboard[i] == c) {
                    curIndex = i;
                    break;
                }
            }
            totalTime += abs(curIndex - prevIndex);

            prevIndex = curIndex;
        }
        return totalTime;
    }
};

int main() {
    Solution sol;

    string keyboard1 = "abcdefghijklmnopqrstuvwxyz";
    string word1 = "cba";
    cout << sol.calculateTime(keyboard1, word1) << endl; // 4

    string keyboard2 = "pqrstuvwxyzabcdefghijklmno";
    string word2 = "neetcode";
    cout << sol.calculateTime(keyboard2, word2) << endl; // 77

    return 0;
}

// ? Optimal
int calculateTime(string keyboard, string word) {
    int pos[26];
    for (int i = 0; i < 26; i++) {
        char c = keyboard[i];
        pos[c - 'a'] = i;
    }

    int totalTime = 0;
    int prevIndex = 0;

    for (char c : word) {
        int curIndex = pos[c - 'a'];
        totalTime += abs(curIndex - prevIndex);
        prevIndex = curIndex;
    }

    return totalTime;
}
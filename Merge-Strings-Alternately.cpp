#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        string ans;

        int i = 0, j = 0;
        // Keep going while at least one string still has characters
        while (i < n || j < m) {
            if (i < n) {
                ans += word1[i];
                i++;
            }
            if (j < m) {
                ans += word2[j];
                j++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string w1 = "abc";
    string w2 = "xyz";
    cout << "mergeAlternately(\"" << w1 << "\", \"" << w2 << "\") = "
         << sol.mergeAlternately(w1, w2) << endl;  // axbycz

    string w3 = "ab";
    string w4 = "pqrs";
    cout << "mergeAlternately(\"" << w3 << "\", \"" << w4 << "\") = "
         << sol.mergeAlternately(w3, w4) << endl;  // apbqrs

    return 0;
}
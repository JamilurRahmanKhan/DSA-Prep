#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();

        int i = 0;  // pointer for s
        int j = 0;  // pointer for t

        // Match as many characters of t inside s as possible
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                j++;    // matched one character of t
            }
            i++;        // always move in s
        }

        // Remaining characters in t = characters we must append
        return m - j;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "coaching";
    string t1 = "coding";
    cout << "s = \"coaching\", t = \"coding\" -> "
         << sol.appendCharacters(s1, t1) << endl;

    // Test Case 2
    string s2 = "abcde";
    string t2 = "a";
    cout << "s = \"abcde\", t = \"a\" -> "
         << sol.appendCharacters(s2, t2) << endl;

    // Test Case 3
    string s3 = "z";
    string t3 = "abcde";
    cout << "s = \"z\", t = \"abcde\" -> "
         << sol.appendCharacters(s3, t3) << endl;

    return 0;
}
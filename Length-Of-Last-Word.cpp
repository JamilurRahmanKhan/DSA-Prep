#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        int len = 0;

        // Step 1: Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }

        return len;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "Hello World";
    cout << "Input: \"" << s1 << "\" -> Output: "
         << sol.lengthOfLastWord(s1) << endl;

    // Test case 2
    string s2 = "   fly me   to   the moon  ";
    cout << "Input: \"" << s2 << "\" -> Output: "
         << sol.lengthOfLastWord(s2) << endl;

    // Test case 3
    string s3 = "luffy is still joyboy";
    cout << "Input: \"" << s3 << "\" -> Output: "
         << sol.lengthOfLastWord(s3) << endl;

    return 0;
}


// Alternative
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                len++;
            } else if (len > 0) {
                break;
            }
        }

        return len;
    }
};
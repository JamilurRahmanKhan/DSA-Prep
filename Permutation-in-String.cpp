#include <iostream>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<int> f1_freq(26, 0);
        vector<int> f2_freq(26, 0);

        // Count frequency of s1
        for (char &ch : s1) {
            f1_freq[ch - 'a']++;
        }

        int i = 0, j = 0;
        while (j < m) {
            f2_freq[s2[j] - 'a']++;

            // Keep window size == n
            if (j - i + 1 > n) {
                f2_freq[s2[i] - 'a']--;
                i++;
            }

            // Compare both frequency arrays
            if (f1_freq == f2_freq) {
                return true;
            }

            j++;
        }
        return false;
    }
};

int main() {
    Solution sol;

    string s1 = "ab";
    string s2 = "eidbaooo";

    if (sol.checkInclusion(s1, s2)) {
        cout << "True: s2 contains a permutation of s1" << endl;
    } else {
        cout << "False: s2 does not contain a permutation of s1" << endl;
    }

    return 0;
}
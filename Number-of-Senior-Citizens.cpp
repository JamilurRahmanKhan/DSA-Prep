#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = 0;

        for (string& s : details) {
            // Extract the two-digit age
            int age = (s[11] - '0') * 10 + (s[12] - '0');

            // Check if age > 60
            if (age > 60) {
                result++;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<string> details1 = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    cout << "Output 1: " << sol.countSeniors(details1) << endl;

    // Test Case 2
    vector<string> details2 = {"1313579440F2036","2921522980M5644"};
    cout << "Output 2: " << sol.countSeniors(details2) << endl;

    // Test Case 3
    vector<string> details3 = {"0000000000M6111","0000000000F7011"};
    cout << "Output 3: " << sol.countSeniors(details3) << endl;

    return 0;
}
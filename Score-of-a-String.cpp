//? Iteration
#include <iostream>
#include <string>
#include <cmath>   // for abs()

using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            sum += abs(s[i] - s[i + 1]);
        }
        return sum;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.scoreOfString(s) << endl;

    return 0;
}

/*
Time:
O(n)    Loop runs (n−1) times, each O(1).
Space:
O(1)    Only a few integers; no memory grows with n.
*/
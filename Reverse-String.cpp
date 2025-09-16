#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

int main() {
    vector<char> s = {'n', 'e', 'e', 't'};

    Solution sol;
    sol.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
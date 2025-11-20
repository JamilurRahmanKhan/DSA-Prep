#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;

        for (int i = 0; i < n; i++) {              
            for (int j = 0; j < n; j++) {        
                if (i == j) continue;             

                if (words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break;                         
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> words1 = {"mass","as","hero","superhero"};
    vector<string> res1 = sol.stringMatching(words1);
    cout << "Result 1: ";
    for (string &w : res1) cout << w << " ";
    cout << endl;

    vector<string> words2 = {"leetcode","et","code"};
    vector<string> res2 = sol.stringMatching(words2);
    cout << "Result 2: ";
    for (string &w : res2) cout << w << " ";
    cout << endl;

    vector<string> words3 = {"blue","green","bu"};
    vector<string> res3 = sol.stringMatching(words3);
    cout << "Result 3: ";
    for (string &w : res3) cout << w << " ";
    cout << endl;

    return 0;
}
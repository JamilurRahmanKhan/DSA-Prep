#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;   // stack of scores
        int sum = 0;      // running total

        for (const string& op : operations) {
            if (op == "C") {
                sum -= st.back();
                st.pop_back();
            }
            else if (op == "D") {
                int val = 2 * st.back();
                st.push_back(val);
                sum += val;
            }
            else if (op == "+") {
                int val = st[st.size() - 1] + st[st.size() - 2];
                st.push_back(val);
                sum += val;
            }
            else {
                int val = stoi(op);
                st.push_back(val);
                sum += val;
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<string> ops1 = {"1","2","+","C","5","D"};
    cout << "Output 1: " << sol.calPoints(ops1) << endl; // 18

    vector<string> ops2 = {"5","D","+","C"};
    cout << "Output 2: " << sol.calPoints(ops2) << endl; // 15

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto &x : tokens) {
            if (x == "+") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b + a);
            }
            else if (x == "-") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b - a);
            }
            else if (x == "*") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b * a);
            }
            else if (x == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b / a); // integer division, truncates toward 0
            }
            else {
                st.push(stoi(x)); // convert string to int
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    
    // Example input: ["2","1","+","3","*"]
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    
    int result = sol.evalRPN(tokens);
    cout << "Result: " << result << endl; // Expected output: 9
    
    return 0;
}
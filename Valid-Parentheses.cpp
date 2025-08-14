#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;

        unordered_map<char, char> match = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                if (st.empty() || st.top() != match[c])
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution sol;
    cout << (sol.isValid("[]") ? "True" : "False") << endl;
    cout << (sol.isValid("([{}])") ? "True" : "False") << endl;
    cout << (sol.isValid("[(])") ? "True" : "False") << endl;
    cout << (sol.isValid("([)]") ? "True" : "False") << endl;
    return 0;
}
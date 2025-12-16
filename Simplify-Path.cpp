// ? Stack
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string token;
        stringstream ss(path);
        stack<string> st;

        // split by '/'
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;

            if (token == "..") {
                if (!st.empty()) st.pop();
            } else {
                st.push(token);
            }
        }

        // rebuild path from stack
        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        if (result.empty()) result = "/";
        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.simplifyPath("/home/") << "\n";                 // /home
    cout << sol.simplifyPath("/../") << "\n";                   // /
    cout << sol.simplifyPath("/home//foo/") << "\n";            // /home/foo
    cout << sol.simplifyPath("/a/./b/../../c/") << "\n";        // /c
    cout << sol.simplifyPath("/a/../../b/../c//.//") << "\n";   // /c

    return 0;
}


// ? Vector
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string token;
        stringstream ss(path);
        vector<string> st; // using vector as stack

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;

            if (token == "..") {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(token);
            }
        }

        string result = "";
        for (string &dir : st) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};

int main() {
    Solution sol;

    vector<string> tests = {
        "/home/",
        "/../",
        "/home//foo/",
        "/a/./b/../../c/",
        "/a/../../b/../c//.//"
    };

    for (auto &p : tests) {
        cout << "Input:  " << p << "\n";
        cout << "Output: " << sol.simplifyPath(p) << "\n\n";
    }

    return 0;
}
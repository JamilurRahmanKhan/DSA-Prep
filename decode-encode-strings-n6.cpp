//decode-encode-strings-n6.cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Encode function: converts a list of strings to a single string
    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        vector<int> sizes;
        string res = "";

        // Store lengths of all strings
        for (string& s : strs) {
            sizes.push_back(s.size());
        }

        // Encode lengths with comma separator
        for (int sz : sizes) {
            res += to_string(sz) + ',';
        }

        // Add separator to distinguish sizes from content
        res += '#';

        // Add all string contents one by one
        for (string& s : strs) {
            res += s;
        }

        return res;
    }

    // Decode function: converts the encoded string back to original list of strings
    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<int> sizes;
        vector<string> res;
        int i = 0;

        // Extract sizes from the beginning until we hit '#'
        while (s[i] != '#') {
            string cur = "";
            while (s[i] != ',') {
                cur += s[i];
                i++;
            }
            sizes.push_back(stoi(cur));
            i++; // skip the comma
        }

        i++; // skip the '#'

        // Extract substrings using the sizes
        for (int sz : sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }

        return res;
    }
};

// Main function to test encode and decode
int main() {
    Solution sol;

    vector<string> input = {"leet", "code", "is", "awesome"};
    
    // Encode the vector of strings
    string encoded = sol.encode(input);
    cout << "Encoded: " << encoded << endl;

    // Decode back to vector of strings
    vector<string> decoded = sol.decode(encoded);
    cout << "Decoded strings:" << endl;
    for (const string& s : decoded) {
        cout << s << endl;
    }

    return 0;
}
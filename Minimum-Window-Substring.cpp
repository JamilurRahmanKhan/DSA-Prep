#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;

        int required = need.size();
        int formed = 0;
        int l = 0, r = 0;
        int minLen = INT_MAX, start = 0;

        while(r < s.size()){
            char c = s[r];
            window[c]++;

            if (need.count(c) && window[c] == need[c])  
                formed++;                               
            

        while (l <= r && formed == required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }

            char leftChar = s[l];
            window[leftChar]--;
            if (need.count(leftChar) && window[leftChar] < need[leftChar])
                formed--;

            l++;
        }
        r++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main(){
    Solution sol;
    cout << sol.minWindow("OUZODYXAZV", "XYZ") << endl; // YXAZ
    cout << sol.minWindow("xyz", "xyz") << endl;        // xyz
    cout << sol.minWindow("x", "xy") << endl;           // ""
    return 0;
}




#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> need(128, 0);  // ASCII size
        for (char c : t) need[c]++;

        int required = t.size();  // total chars needed (including duplicates)
        int l = 0, minLen = INT_MAX, start = 0;

        for (int r = 0; r < s.size(); r++) {
            if (need[s[r]] > 0) required--; // Found a needed char
            need[s[r]]--; // Decrease count for current char

            while (required == 0) { // All chars matched
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                need[s[l]]++;
                if (need[s[l]] > 0) required++; // We lost a needed char
                l++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};

int main() {
    Solution sol;
    cout << sol.minWindow("OUZODYXAZV", "XYZ") << endl; // YXAZ
    cout << sol.minWindow("xyz", "xyz") << endl;        // xyz
    cout << sol.minWindow("x", "xy") << endl;           // ""
}
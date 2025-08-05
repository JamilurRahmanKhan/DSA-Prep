// Sorting
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string> &words)
{
    unordered_map<string, vector<string>> sortedMap;

    for (const string &word : words)
    {
        string sortedWord = word; 
        sort(sortedWord.begin(), sortedWord.end());
        sortedMap[sortedWord].push_back(word);
    }

    vector<vector<string>> result;
    for (auto &pair : sortedMap)
    {
        result.push_back(pair.second);
    }

    return result;
}

int main()
{
    vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};

    vector<vector<string>> grouped = groupAnagrams(strs);

    for (const auto &group : grouped)
    {
        if (group.size() > 1)
        {
            cout << "Anagram group: ";
            for (const string &word : group)
                cout << word << " ";
            cout << endl;
        }
    }

    return 0;
}




// // Hash Table
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> res;
//         for (const auto& s : strs) {
//             vector<int> count(26, 0);
//             for (char c : s) {
//                 count[c - 'a']++;
//             }
//             string key = to_string(count[0]);
//             for (int i = 1; i < 26; ++i) {
//                 key += ',' + to_string(count[i]);
//             }
//             res[key].push_back(s);
//         }
//         vector<vector<string>> result;
//         for (const auto& pair : res) {
//             result.push_back(pair.second);
//         }
//         return result;
//     }
// };
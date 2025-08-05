#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for(int i=0; i<s.size(); i++)
        {
            countS[s[i]]++;
            countT[t[i]]++;
        }
        if(countS == countT)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    string s = "racecar";
    string t = "carrace";

    if (solution.isAnagram(s, t) == true)
    {
        cout << "Valid Anagram" << endl;
    }
    else
    {
        cout << "In-Valid Anagram" << endl;
    }

    return 0;
}

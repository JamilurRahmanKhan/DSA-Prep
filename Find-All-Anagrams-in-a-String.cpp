// 438. Find All Anagrams in a String
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Function to check if all elements in counter are zero
    bool allZero(vector<int> &counter){
        for(int &i: counter){
            if(i != 0) return false;
        }
        return true;
    }

    // Function to find all starting indices of anagrams of p in s
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length();
        vector<int> counter(26, 0);

        // Count frequency of each character in p
        for(char &ch : p){
            counter[ch-'a']++;
        }

        int i = 0, j = 0;
        vector<int> result;

        while(j < n){
            counter[s[j]-'a']--;  // Include current character

            if(j - i + 1 == k){  // When window size matches p's length
                if(allZero(counter)){  // Check if window is an anagram
                    result.push_back(i);
                }

                counter[s[i]-'a']++;  // Remove leftmost character from window
                i++;
            }
            j++;
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s = "forxxorfxdofr";
    string p = "for";
    vector<int> result1 = sol.findAnagrams(s, p);
    cout << "Indices of anagrams in \"" << s << "\": ";
    for(int idx : result1) cout << idx << " ";
    cout << endl;

    // Test case 2
    s = "aabaabaa";
    p = "aaba";
    vector<int> result2 = sol.findAnagrams(s, p);
    cout << "Indices of anagrams in \"" << s << "\": ";
    for(int idx : result2) cout << idx << " ";
    cout << endl;

    return 0;
}

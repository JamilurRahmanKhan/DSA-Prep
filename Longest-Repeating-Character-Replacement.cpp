#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // vector<int> freq(26,0);
        // int l = 0, maxFreq = 0, maxLen = 0;
        // for(int r = 0; r<s.size(); r++){
        //     freq[s[r] - 'A']++;
        //     maxFreq = max(maxFreq, freq[s[r] - 'A']);

        //     while((r-l+1) - maxFreq > k){
        //         freq[s[l] - 'A']--;
        //         l++;
        //     }
        //     maxLen = max(maxLen, r-l+1);
        // } 
        // return maxLen;

        vector<int> freq(26, 0);
        int l = 0, maxFreq = 0, maxLen = 0;
        for (int r = 0; r < s.size(); r++)
        {
            int idx = s[r] - 'A';
            freq[idx]++;
            if (freq[idx] > maxFreq)
                maxFreq = freq[idx];

            while ((r - l + 1) - maxFreq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};


int main(){
    Solution sol;
    // cout << sol.characterReplacement("XYYX", 2) << endl;      // Output: 4
    cout << sol.characterReplacement("AAABABB", 1) << endl;  // Output: 5
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool allZero(vector<int>& counter) {
        for (int &i : counter) {
            if (i != 0) return false;
        }
        return true;
    }

    int countAnagrams(const string& pattern, const string& text) {
        int n = text.length();
        vector<int> counter(26, 0);

        // Count the freq of each char in pattern
        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern[i];
            counter[ch - 'a']++;
        }

        int i = 0, j = 0;
        int result = 0;
        int k = pattern.length();

        while (j < n) {
            // each time you add a new character, decrease its count
            counter[text[j] - 'a']--;

            // When the window size matches the pattern size
            if (j - i + 1 == k) {
                // If all counts are zero → it’s an anagram
                if (allZero(counter)) result++;

                // Then slide the window by removing the left character (increase its count back)
                counter[text[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};

int main() {
    Solution sol;

    string text = "forxxorfxdofr";
    string pattern = "for";
    cout << "Count of anagrams: " << sol.countAnagrams(pattern, text) << endl;

    text = "aabaabaa";
    pattern = "aaba";
    cout << "Count of anagrams: " << sol.countAnagrams(pattern, text) << endl;

    return 0;
}
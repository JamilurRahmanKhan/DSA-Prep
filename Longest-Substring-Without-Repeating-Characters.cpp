// Brute Force
// #include <iostream>
// #include <vector>
// #include <string>
// #include <unordered_set>
// using namespace std;

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int res = 0;
//         for(int i=0; i<s.size(); i++){
//             unordered_set<char> A;
//             for(int j=i; j<s.size(); j++){
//                 if(A.find(s[j]) != A.end()){
//                     break;
//                 }
//                 A.insert(s[j]);
//             }
//             res = max(res, (int)A.size());
//         }
//         return res;
//     }
// };

// int main()
// {
//     Solution sol;
//     // vector<string> s = {"aabjexabjebbxio"};
//     // vector<string> s = {"aabjexbjexio"};
//     vector<string> s = {"zxyzxyz"};
//     int result = sol.lengthOfLongestSubstring(s[0]);
//     cout << "The output is: " << result << endl;
//     return 0;
// }

// Sliding Window
// #include <iostream>
// #include <vector>
// #include <string>
// #include <unordered_set>
// using namespace std;

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         unordered_set<char> A;
//         int l = 0;
//         int maxL = 0;
//         for (int r = 0; r < s.size(); r++)
//         {
//             while (A.find(s[r]) != A.end())
//             {
//                 A.erase(s[l]);
//                 l++;
//             }
//             A.insert(s[r]);
//             maxL = max(maxL, r - l + 1);
//         }
//         return maxL;
//     }
// };

// int main()
// {
//     Solution sol;
//     // vector<string> s = {"aabjexabjebbxio"};
//     // vector<string> s = {"aabjexbjexio"};
//     vector<string> s = {"zxyzyxz"};
//     int result = sol.lengthOfLongestSubstring(s[0]);
//     cout << "The output is: " << result << endl;
//     return 0;
// }






// #include <iostream>
// #include <vector>
// #include <string>
// #include <unordered_map>
// using namespace std;

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         unordered_map<char,int> A;
//         int l=0;
//         int maxLen=0;
//         for(int r=0; r<s.size(); r++){
//             if(A.find(s[r]) != A.end()){
//                 l = max(A[s[r]]+1, l);
//             }
//             A[s[r]] = r;
//             maxLen = max(maxLen, r-l+1);
//         }
//         return maxLen;
//     }
// };

// int main()
// {
//     Solution sol;
//     // vector<string> s = {"aabjexabjebbxio"};
//     // vector<string> s = {"aabjexbjexio"};
//     vector<string> s = {"zxyzyxz"};
//     int result = sol.lengthOfLongestSubstring(s[0]);
//     cout << "The output is: " << result << endl;
//     return 0;
// }





#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> last(256, -1); 
        int l = 0, maxLen = 0;

        for (int r = 0; r < s.size(); r++)
        {
            if (last[s[r]] >= l)
            { 
                l = last[s[r]] + 1;
            }
            last[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

int main()
{
    Solution sol;
    // vector<string> s = {"aabjexabjebbxio"};
    // vector<string> s = {"aabjexbjexio"};
    vector<string> s = {"zxyzyxz"};
    int result = sol.lengthOfLongestSubstring(s[0]);
    cout << "The output is: " << result << endl;
    return 0;
}
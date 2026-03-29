#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s){
        int l = 0;
        int r = s.length();
        while(l<r){
            while(l<r && !alphaNum(s[l])){
                l++;
            }
            while(l<r && !alphaNum(s[r])){
                r--;
            }

            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    bool alphaNum(char c){
        return (c>= 'A' && c <= 'Z' ||
                c>= 'a' && c <= 'z' ||
                c>= '0' && c <= '9');
    }
};

int main()
{
    Solution solution;
    string s = "Was it a car or a cat I saw?";
    bool result = solution.isPalindrome(s);
    if (result)
    {
        cout << "This is a Palindrome" << endl;
    }
    else
    {
        cout << "This is not a Palindrome" << endl;
    }
    return 0;
}
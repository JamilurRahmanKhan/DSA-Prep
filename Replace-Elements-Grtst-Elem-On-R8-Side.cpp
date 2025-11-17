// ? Brute Force
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            int maxVal = arr[i + 1];           
            for (int j = i + 1; j < n; j++) {  
                if (arr[j] > maxVal) {
                    maxVal = arr[j];
                }
            }
            arr[i] = maxVal;                 
        }

        arr[n - 1] = -1;                       
        return arr;
    }
};

int main() {
    // Hardcoded example input; you can change this to test other cases
    vector<int> arr = {2, 4, 5, 3, 1, 2};

    Solution sol;
    vector<int> result = sol.replaceElements(arr);

    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}




// ? Suffix Max
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        int rightMax = -1;
        for(int i=n-1; i>=0; --i){
            ans[i] = rightMax;
            rightMax = max(rightMax, arr[i]);
        }
        return ans;
    }
};
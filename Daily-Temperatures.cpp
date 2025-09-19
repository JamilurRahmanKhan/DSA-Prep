// // Brute Force
// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int> result(n, 0); // initialize with 0

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) { // look for next warmer day
//                 if (temperatures[j] > temperatures[i]) {
//                     result[i] = j - i; // distance to next warmer day
//                     break; // stop at first warmer day
//                 }
//             }
//         }

//         return result;
//     }
// };

// int main() {
//     Solution sol;
//     vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

//     vector<int> result = sol.dailyTemperatures(temperatures);

//     cout << "Result: ";
//     for (int x : result) {
//         cout << x << " ";
//     }
//     cout << endl;

//     return 0;
// }


// Stack
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> result(n);
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }

            if(st.empty()){
                result[i] = 0;
            }else{
                result[i] = st.top() - i;
            }
            st.push(i);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> result = sol.dailyTemperatures(temperatures);

    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
// ? Stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {

            // Collision only when:
            // previous is moving right (positive) and current is moving left (negative)
            while (!st.empty() && a < 0 && st.top() > 0) {
                int sum = a + st.top(); // compares sizes because a is negative

                if (sum < 0) {
                    // |a| > st.top() => stack asteroid dies
                    st.pop();
                    // keep checking because 'a' might collide again with new top
                } 
                else if (sum > 0) {
                    // st.top() bigger => current asteroid dies
                    a = 0;
                    break;
                } 
                else {
                    // equal sizes => both die
                    st.pop();
                    a = 0;
                }
            }

            if (a != 0) st.push(a);
        }

        // Build result from stack (reverse order)
        vector<int> result(st.size());
        for (int i = (int)result.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> ast1 = {5, 10, -5};
    auto r1 = sol.asteroidCollision(ast1);
    cout << "Result 1: ";
    for (int x : r1) cout << x << " ";
    cout << endl;

    vector<int> ast2 = {8, -8};
    auto r2 = sol.asteroidCollision(ast2);
    cout << "Result 2: ";
    for (int x : r2) cout << x << " ";
    cout << endl;

    vector<int> ast3 = {10, 2, -5};
    auto r3 = sol.asteroidCollision(ast3);
    cout << "Result 3: ";
    for (int x : r3) cout << x << " ";
    cout << endl;

    return 0;
}



//Using vector<int> as stack - T.C (O(n))
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         vector<int> st;
        
//         for(int &a : asteroids) {
            
//             while(!st.empty() && a < 0 && st.back() > 0) {
//                 int sum = a + st.back();
//                 if(sum < 0) {
//                     st.pop_back();
//                 } else if(sum > 0) {
//                     a = 0;
//                     break;
//                 } else {
//                     st.pop_back();
//                     a = 0;
//                 }
//             }
            
//             if(a != 0)
//                 st.push_back(a);
            
//         }
        
        
//         return st;
//     }
// };
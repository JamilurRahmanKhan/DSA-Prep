#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

class MinStack {
    stack<int> st1, st2;
public:
    MinStack() {}

    void push(int val) {
        if(st2.empty() || val <= st2.top()){
            st2.push(val);
        }
        st1.push(val);
    }

    void pop() {
        if(st1.top() == st2.top()){
            st2.pop();
        }
        st1.pop();
    }

    int top() {
        return st1.top();
    }

    int getMin() {
        return st2.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(3);
    cout << "Min: " << minStack.getMin() << endl; // 3
    minStack.push(4);
    cout << "Min: " << minStack.getMin() << endl; // 3
    minStack.push(2);
    cout << "Min: " << minStack.getMin() << endl; // 2
    minStack.push(0);
    cout << "Min: " << minStack.getMin() << endl; // 0
    minStack.push(1);
    cout << "Min: " << minStack.getMin() << endl; // 0

    cout << "Top: " << minStack.top() << endl; // 1
    minStack.pop();
    cout << "Top after pop: " << minStack.top() << endl; // 0
    cout << "Min after pop: " << minStack.getMin() << endl; // 0

    minStack.pop();
    cout << "Top after pop: " << minStack.top() << endl; // 2
    cout << "Min after pop: " << minStack.getMin() << endl; // 2

    return 0;
}











// #include <iostream>
// #include <stack>
// #include <utility>
// #include <algorithm>
// using namespace std;

// class MinStack {
// private:
//     stack<pair<int,int>> st; // each element: {value, min-so-far}

// public:
//     MinStack() {}

//     void push(int val) {
//         if(st.empty()) {
//             st.push({val, val});
//         } else {
//             int currentMin = min(val, st.top().second);
//             st.push({val, currentMin});
//         }
//     }

//     void pop() {
//         if(!st.empty())
//             st.pop();
//     }

//     int top() {
//         return st.top().first;
//     }

//     int getMin() {
//         return st.top().second;
//     }
// };

// int main() {
//     MinStack minStack;

//     minStack.push(3);
//     cout << "Min: " << minStack.getMin() << endl; // 3
//     minStack.push(4);
//     cout << "Min: " << minStack.getMin() << endl; // 3
//     minStack.push(2);
//     cout << "Min: " << minStack.getMin() << endl; // 2
//     minStack.push(0);
//     cout << "Min: " << minStack.getMin() << endl; // 0
//     minStack.push(1);
//     cout << "Min: " << minStack.getMin() << endl; // 0

//     cout << "Top: " << minStack.top() << endl; // 1
//     minStack.pop();
//     cout << "Top after pop: " << minStack.top() << endl; // 0
//     cout << "Min after pop: " << minStack.getMin() << endl; // 0

//     minStack.pop();
//     cout << "Top after pop: " << minStack.top() << endl; // 2
//     cout << "Min after pop: " << minStack.getMin() << endl; // 2

//     return 0;
// }
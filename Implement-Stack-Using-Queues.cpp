#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    // Push element x onto stack.
    void push(int x) {
        int sz = (int)q.size();  // number of existing elements
        q.push(x);               // put new element at the back

        // rotate old elements behind the new one
        for (int i = 0; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack and returns it.
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Returns whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};

// ---------- Test in IDE ----------
int main() {
    MyStack st;

    st.push(1);
    st.push(2);
    cout << "Top: " << st.top() << "\n";    // 2
    cout << "Pop: " << st.pop() << "\n";    // 2
    cout << "Empty: " << (st.empty() ? "true" : "false") << "\n"; // false

    return 0;
}
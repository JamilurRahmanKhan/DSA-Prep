#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inSt;   // push goes here
    stack<int> outSt;  // pop/peek comes from here

    void moveInToOut() {
        while (!inSt.empty()) {
            outSt.push(inSt.top());
            inSt.pop();
        }
    }

public:
    void push(int x) {
        inSt.push(x);
    }

    int pop() {
        if (outSt.empty()) {
            moveInToOut();
        }
        int val = outSt.top();
        outSt.pop();
        return val;
    }

    int peek() {
        if (outSt.empty()) {
            moveInToOut();
        }
        return outSt.top();
    }

    bool empty() {
        return inSt.empty() && outSt.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    cout << "peek: " << q.peek() << endl; // 1
    cout << "pop: " << q.pop() << endl;   // 1
    cout << "empty: " << (q.empty() ? "true" : "false") << endl; // false

    q.push(3);
    cout << "peek: " << q.peek() << endl; // 2
    cout << "pop: " << q.pop() << endl;   // 2
    cout << "pop: " << q.pop() << endl;   // 3
    cout << "empty: " << (q.empty() ? "true" : "false") << endl; // true

    return 0;
}
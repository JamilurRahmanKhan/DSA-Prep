#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st; // {price, span}

    StockSpanner() {}

    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner sp;

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    cout << "Spans: ";
    for (int p : prices) {
        cout << sp.next(p) << " ";
    }
    cout << endl;
    // Expected: 1 1 1 2 1 4 6

    return 0;
}
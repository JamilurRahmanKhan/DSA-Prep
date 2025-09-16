#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> firstNegativeInWindow(vector<int>& arr, int k) {
    vector<int> result;
    deque<int> deq;
    int i = 0, j = 0;
    int n = arr.size();

    while (j < n)
    {
        // if current element is negative, push it into deque
        if (arr[j] < 0)
        {
            deq.push_back(arr[j]);
        }

        // check if window size is hit
        if (j - i + 1 == k)
        {
            // first negative = front of deque if exists
            if (!deq.empty())
            {
                result.push_back(deq.front());
            }
            else
            {
                result.push_back(0);
            }

            // remove outgoing element from deque if it was negative
            if (arr[i] < 0 && !deq.empty())
            {
                deq.pop_front();
            }

            // slide window forward
            i++;
        }

        // expand window
        j++;
    }
    return result;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> ans = firstNegativeInWindow(arr, k);

    cout << "First negatives in each window of size " << k << ": ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
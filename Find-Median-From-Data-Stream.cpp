// Brute force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
private:
    vector<int> arr;

public:
    // constructor
    MedianFinder() {}

    // Add number
    void addNum(int num) {
        arr.push_back(num);
    }

    // Find median
    double findMedian() {
        sort(arr.begin(), arr.end());  // brute force: sort every time
        int n = arr.size();
        if (n % 2 == 1) {
            return arr[n / 2];  // odd → middle element
        } else {
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;  // even → avg of two middle
        }
    }
};

// Input:
// ["MedianFinder", "addNum", "1", "findMedian", "addNum", "3" "findMedian", "addNum", "2", "findMedian"]

// Output:
// [null, null, 1.0, null, 2.0, null, 2.0]

// Explanation:
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.findMedian(); // return 1.0
// medianFinder.addNum(3);    // arr = [1, 3]
// medianFinder.findMedian(); // return 2.0
// medianFinder.addNum(2);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0

int main() {
    MedianFinder medianFinder;

    medianFinder.addNum(1);                     // arr = [1]
    cout << medianFinder.findMedian() << endl;  // Output: 1.0

    medianFinder.addNum(3);                     // arr = [1, 3]
    cout << medianFinder.findMedian() << endl;  // Output: 2.0

    medianFinder.addNum(2);                     // arr = [1, 3, 2] → [1, 2, 3]
    cout << medianFinder.findMedian() << endl;  // Output: 2.0

    return 0;
}




// Heap 
class MedianFinder {
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size() == largeHeap.size()){
            return (largeHeap.top() + smallHeap.top())/ 2.0;
        }else if(smallHeap.size() > largeHeap.size()){
            return smallHeap.top();
        }else{
            return largeHeap.top();
        }
    }
};

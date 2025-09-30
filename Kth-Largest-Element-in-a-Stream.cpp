// Sorting
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class KthLargest {
public:
    vector<int> arr;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->arr = nums;
        this->k = k;
    }

    int add(int val) {
        arr.push_back(val);
        sort(arr.begin(), arr.end());  // keep sorted
        return arr[arr.size() - k];    // kth largest
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    KthLargest kth(k, nums);

    cout << "add(3) → " << kth.add(3) << endl;   // returns 4
    cout << "add(5) → " << kth.add(5) << endl;   // returns 5
    cout << "add(10) → " << kth.add(10) << endl; // returns 5
    cout << "add(9) → " << kth.add(9) << endl;   // returns 8
    cout << "add(4) → " << kth.add(4) << endl;   // returns 8

    return 0;
}


// Min-Heap
// class KthLargest {
// public:
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     int k;
//     KthLargest(int k, vector<int>& nums) {
//         this->k = k;
//         for(int num : nums){
//             minHeap.push(num);
//             if(minHeap.size() > k){
//                 minHeap.pop();
//             }
//         }
//     }
    
//     int add(int val) {
//         minHeap.push(val);
//         if(minHeap.size() > k){
//             minHeap.pop();
//         }
//         return minHeap.top();
//     }
// };

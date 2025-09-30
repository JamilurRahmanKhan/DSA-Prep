// Heap
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // max-heap
        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int a = pq.top(); 
            pq.pop();

            int b = pq.top();
            pq.pop();

            if (a != b) { // push back the difference only if non-zero
                pq.push(abs(a - b));
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    Solution sol;
    int result = sol.lastStoneWeight(stones);

    cout << "Last stone weight: " << result << endl; // Expected output: 1

    return 0;
}



// Brute Force
// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         while(stones.size() > 1){
//             sort(stones.begin(), stones.end());

//             int a = stones.back(); 
//             stones.pop_back();

//             int b = stones.back();
//             stones.pop_back();

//             stones.push_back(abs(a-b));
//         }
//         return stones[0];
//     }
// };

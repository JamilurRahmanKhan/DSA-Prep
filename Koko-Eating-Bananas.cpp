#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canEatAll(vector<int> &piles, int mid, int h){
        int actualHour = 0;
        for(int x : piles){
            actualHour += x/mid;
            if(x%mid != 0){
                actualHour++;
            }
        }
        return actualHour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(begin(piles),end(piles));

        while(l < r){
            int mid = l + (r-l)/2;
            if(canEatAll(piles, mid, h)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};

int main() {
    Solution sol;
    int n, h;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);
    cout << "Enter pile sizes: ";
    for(int i = 0; i < n; i++){
        cin >> piles[i];
    }

    cout << "Enter total hours h: ";
    cin >> h;

    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}



// brute force
// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int speed = 1;
//         while (true) {
//             long long totalTime = 0;
//             for (int pile : piles) {
//                 totalTime += (pile + speed - 1) / speed;
//             }

//             if (totalTime <= h) {
//                 return speed;
//             }
//             speed++;
//         }
//     }
// };
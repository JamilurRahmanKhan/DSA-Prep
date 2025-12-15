// ? Sorting + Two Pointers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        // 1) Sort the people by weight
        sort(people.begin(), people.end());

        int i = 0;          // lightest remaining
        int j = n - 1;      // heaviest remaining
        int boats = 0;      // total boats used

        // 2) Two-pointer greedy pairing
        while (i <= j) {
            // If lightest + heaviest can share a boat, put them together
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
            } else {
                // Otherwise, heaviest goes alone
                j--;
            }
            boats++; // We used one boat in either case
        }
        return boats;
    }
};

int main() {
    Solution sol;

    vector<int> people1 = {5, 1, 4, 2};
    int limit1 = 6;
    cout << "Example 1 boats: " << sol.numRescueBoats(people1, limit1) << endl;
    // Expected: 2  ( [1,5], [2,4] )

    vector<int> people2 = {1, 3, 2, 3, 2};
    int limit2 = 3;
    cout << "Example 2 boats: " << sol.numRescueBoats(people2, limit2) << endl;
    // Expected: 4

    return 0;
}


// ? Counting Sort
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // 1) Find maximum weight
        int m = *max_element(people.begin(), people.end());

        // 2) Counting array: count[w] = how many people have weight = w
        vector<int> count(m + 1, 0);
        for (int p : people) {
            count[p]++;
        }

        // 3) Rebuild people[] in sorted order using the counts (counting sort)
        int idx = 0;
        int w = 1; // weights start from 1 in the constraints
        while (idx < (int)people.size()) {
            while (w <= m && count[w] == 0) {
                w++; // skip weights that have no people
            }
            people[idx++] = w;
            count[w]--;
        }

        // 4) Two-pointer greedy on the sorted array
        int res = 0;
        int l = 0;
        int r = (int)people.size() - 1;

        while (l <= r) {
            int remain = limit - people[r]; // put the heaviest person on a boat
            r--;
            res++;

            // Try to fit the lightest person with them
            if (l <= r && remain >= people[l]) {
                l++;
            }
        }
        return res;
    }
};
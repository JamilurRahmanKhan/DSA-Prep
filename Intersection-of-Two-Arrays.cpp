// ? Brute Force
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_set<int> res;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(nums1[i]==nums2[j]){
                    res.insert(nums1[i]);
                }
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> ans = sol.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}


// ? Optimal
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()); // elements of nums1
        unordered_set<int> res;                            // to store unique intersection

        for (int x : nums2) {
            if (s1.count(x)) {     // if x is also in nums1
                res.insert(x);     // add to result set (no duplicates)
            }
        }

        return vector<int>(res.begin(), res.end()); // convert set → vector
    }
};
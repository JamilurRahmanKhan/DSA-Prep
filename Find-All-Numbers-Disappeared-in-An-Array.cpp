// ? Brute Force
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for(int i=1; i<=n; i++){
            bool found = false;
            for(int x : nums){
                if(x == i){
                    found = true;
                    break;
                }
            }
            if(!found){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = sol.findDisappearedNumbers(nums);

    cout << "Missing numbers: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

// ? Hash Set
#include <unordered_set>
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> store;
        for (int i = 1; i <= n; i++) store.insert(i);

        for (int num : nums) {
            store.erase(num);
        }

        vector<int> result(store.begin(), store.end());
        return result;
    }
};


// ? Negative Marking
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        for(int x : nums){
            int idx = abs(x) - 1;
            if(nums[idx] > 0){
                nums[idx] = -nums[idx];
            }
        }

        vector<int> res;
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
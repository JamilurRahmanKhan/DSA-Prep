// k-frequent-element

// Bucket Sort
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        // define frequency
        unordered_map<int, int> freqMap;
        for (int num : nums)
        {
            freqMap[num]++;
        }

        vector<vector<int>> bucket(n+1);
        //index = freq;
        //value = elements;
        //bucket[i] = elements having i frequency
        for(auto &it : freqMap){
            int element = it.first;
            int freq = it.second;
            bucket[freq].push_back(element);
        }

        //result
        //pick elements from right to left from bucket to find max frequency element
        vector<int> result;
        for(int i=n; i>=0; i--){
            if(bucket[i].size() == 0){
                continue;
            }
            while(bucket[i].size() > 0 && k>0){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {10, 20, 20, 30, 30, 30};
    int k = 2;

    vector<int> result = solution.topKFrequent(nums, k);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}




// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <string>
// #include <algorithm>
// #include <queue>
// using namespace std;

// class Solution
// {
// public:
//     vector<int> topKFrequent(vector<int> &nums, int k)
//     {
//         unordered_map<int, int> freqMap;
//         for (int num : nums)
//         {
//             freqMap[num]++;
//         }

//         vector<pair<int, int>> freqGroups;
//         for (auto &entry : freqMap)
//         {
//             freqGroups.push_back({entry.second, entry.first});
//         }
//         sort(freqGroups.rbegin(), freqGroups.rend());

//         vector<int> res;
//         for (int i = 0; i < k; i++)
//         {
//             res.push_back(freqGroups[i].second);
//         }
//         return res;
//     }
// };



// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <string>
// #include <algorithm>
// #include <queue>
// using namespace std;
// class Solution
// {
// public:
//     vector<int> topKFrequent(vector<int> &nums, int k)
//     {
//         // define frequency
//         unordered_map<int, int> freqMap;
//         for (int num : nums)
//         {
//             freqMap[num]++;
//         }

//         // define min heap
//         typedef pair<int, int> P;
//         priority_queue<P, vector<P>, greater<P>> pq;

//         //push elements in min-heap
//         //maintains size of k only
//         for(auto &it: freqMap)
//         {
//             int value = it.first;
//             int freq = it.second;

//             pq.push({freq,value});

//             if(pq.size() > k){
//                 pq.pop();
//             }
//         }

//         // result
//         vector<int> result;
//         while(!pq.empty()){
//             result.push_back(pq.top().second);
//             pq.pop();
//         }
//         return result;
//     }
// };

// int main()
// {
//     Solution solution;
//     vector<int> nums = {10, 20, 20, 30, 30, 30};
//     int k = 2;

//     vector<int> result = solution.topKFrequent(nums, k);
//     for (int num : result)
//     {
//         cout << num << " ";
//     }
//     cout << endl;
//     return 0;
// }




// Two Pointers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int l = 0, r = heights.size() - 1;
        int res = 0;

        while (l < r)
        {
            int h = heights[l] < heights[r] ? heights[l++] : heights[r--];
            res = max(res, h * (r - l + 1));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> heights = {1, 7, 2, 5, 4, 7, 3, 6};
    int result = sol.maxArea(heights);
    cout << "Container With Most Water: " << result << endl;
}

// Brute Force
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Solution
// {
// public:
//     int maxArea(vector<int>& heights)
//     {
//         int maxarea=0;
//         for(int i=0; i<heights.size(); i++){
//             for(int j=i+1; j<heights.size(); j++){
//                 int area = min(heights[i],heights[j]) * (j-i);
//                 maxarea = max(maxarea, area);
//             }
//         }
//         return maxarea;
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<int> heights = {1,7,2,5,4,7,3,6};
//     int result = sol.maxArea(heights);
//     cout << "Container With Most Water: " << result << endl;
// }
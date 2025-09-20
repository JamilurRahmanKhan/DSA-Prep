// stack
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> s;

        // Find nearest smaller element to the right
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Clear stack
        while (!s.empty())
        {
            s.pop();
        }

        // Find nearest smaller element to the left
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Calculate maximum area
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}

// brute force
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <algorithm>
// using namespace std;

// class Solution
// {
// public:
//     int largestRectangleArea(vector<int> &heights)
//     {
//         class Solution
//         {
//         public:
//             int largestRectangleArea(vector<int> &heights)
//             {
//                 int n = heights.size();
//                 int maxArea = 0;

//                 for (int i = 0; i < n; i++)
//                 {
//                     int height = heights[i];

//                     int rightMost = i + 1;
//                     while (rightMost < n && heights[rightMost] >= height)
//                     {
//                         rightMost++;
//                     }

//                     int leftMost = i;
//                     while (leftMost >= 0 && heights[leftMost] >= height)
//                     {
//                         leftMost--;
//                     }

//                     rightMost--;
//                     leftMost++;
//                     maxArea = max(maxArea, height * (rightMost - leftMost + 1));
//                 }
//                 return maxArea;
//             }
//         };
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<int> heights = {2, 1, 5, 6, 2, 3};
//     cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
//     return 0;
// }
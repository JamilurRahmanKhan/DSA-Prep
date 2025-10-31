// // Brute Force
// #include <iostream>
// #include <vector>
// #include <utility> // pair
// using namespace std;

// class Solution
// {
// public:
//     // Brute-force: for each cell, run a DFS that only moves to lower-or-equal neighbors.
//     vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
//     {
//         int m = heights.size();
//         if (m == 0)
//             return {};
//         int n = heights[0].size();

//         vector<vector<int>> res;
//         vector<int> dirs = {-1, 0, 1, 0, -1}; // U, R, D, L

//         for (int r = 0; r < m; ++r)
//         {
//             for (int c = 0; c < n; ++c)
//             {
//                 vector<vector<bool>> vis(m, vector<bool>(n, false));
//                 bool reachesPac = false, reachesAtl = false;

//                 dfsBrute(r, c, heights, vis, dirs, reachesPac, reachesAtl, m, n);

//                 if (reachesPac && reachesAtl)
//                 {
//                     res.push_back({r, c});
//                 }
//             }
//         }
//         return res;
//     }

// private:
//     // DFS from (r,c): water can flow only to cells with height <= current height
//     void dfsBrute(int r, int c,
//                   const vector<vector<int>> &h,
//                   vector<vector<bool>> &vis,
//                   const vector<int> &dirs,
//                   bool &reachesPac,
//                   bool &reachesAtl,
//                   int m, int n)
//     {
//         if (reachesPac && reachesAtl)
//             return; // early stop if both oceans found
//         vis[r][c] = true;

//         // Touching borders => can reach that ocean
//         if (r == 0 || c == 0)
//             reachesPac = true;
//         if (r == m - 1 || c == n - 1)
//             reachesAtl = true;

//         // Explore 4 neighbors (downhill or flat)
//         for (int d = 0; d < 4; ++d)
//         {
//             int nr = r + dirs[d];
//             int nc = c + dirs[d + 1];
//             if (nr < 0 || nr >= m || nc < 0 || nc >= n)
//                 continue;
//             if (vis[nr][nc])
//                 continue;

//             if (h[nr][nc] <= h[r][c])
//             {
//                 dfsBrute(nr, nc, h, vis, dirs, reachesPac, reachesAtl, m, n);
//                 if (reachesPac && reachesAtl)
//                     return; // early exit if both found
//             }
//         }
//     }
// };

// // -------- Demo driver (edit as you like) --------
// int main()
// {
//     vector<vector<int>> heights = {
//         {1, 2, 2, 3, 5},
//         {3, 2, 3, 4, 4},
//         {2, 4, 5, 3, 1},
//         {6, 7, 1, 4, 5},
//         {5, 1, 1, 2, 4}};

//     Solution sol;
//     auto ans = sol.pacificAtlantic(heights);

//     cout << "Cells that can reach both oceans:\n";
//     for (auto &cell : ans)
//     {
//         cout << "[" << cell[0] << ", " << cell[1] << "] ";
//     }
//     cout << "\n";
//     return 0;
// }






/*
1  2  2  3
3  2  3  4
2  4  5  3
6  7  1  4
*/
// BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        if (m == 0)
            return {};
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        queue<pair<int, int>> qp, qa;

        // Pacific borders (top row + left column)
        for (int c = 0; c < n; ++c)
        {
            qp.emplace(0, c);
            pac[0][c] = true;
        }
        for (int r = 0; r < m; ++r)
        {
            qp.emplace(r, 0);
            pac[r][0] = true;
        }

        // Atlantic borders (bottom row + right column)
        for (int c = 0; c < n; ++c)
        {
            qa.emplace(m - 1, c);
            atl[m - 1][c] = true;
        }
        for (int r = 0; r < m; ++r)
        {
            qa.emplace(r, n - 1);
            atl[r][n - 1] = true;
        }

        bfs(heights, qp, pac);
        bfs(heights, qa, atl);

        vector<vector<int>> ans;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (pac[r][c] && atl[r][c])
                    ans.push_back({r, c});
        return ans;
    }

private:
    void bfs(const vector<vector<int>> &h,
             queue<pair<int, int>> q,
             vector<vector<bool>> &vis)
    {
        int m = h.size(), n = h[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1}; // 4 directions

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k)
            {
                int nr = r + dirs[k];
                int nc = c + dirs[k + 1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (!vis[nr][nc] && h[nr][nc] >= h[r][c])
                {
                    vis[nr][nc] = true;
                    q.emplace(nr, nc);
                }
            }
        }
    }
};

// ---- Demo driver ----
int main()
{
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}};

    Solution sol;
    auto ans = sol.pacificAtlantic(heights);

    cout << "Cells that can reach both oceans:\n";
    for (auto &cell : ans)
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    cout << "\n";
    return 0;
}
// Brute Force
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        // n = 4; edges = [[0,1],[1,2],[1,3]]
        // Necessary condition: a tree on n nodes has exactly n-1 edges
        if ((int)edges.size() != n - 1)
            return false;

        // Build undirected adjacency list
        vector<vector<int>> adj(n);
        for (const auto &e : edges)
        {
            int u = e[0], v = e[1]; // u = 0, v = 1
            adj[u].push_back(v);    // 0 → 1
            adj[v].push_back(u);    // 1 → 0
            // adj = [
            //     [1],
            //     [ 0, 2, 3 ],
            //     [1],
            //     [1]
            // ]
        }

        // Brute-force connectivity: run BFS from EVERY node
        for (int start = 0; start < n; ++start)
        {
            vector<bool> vis(n, false); // vis = [F, F, F, F]
            queue<int> q;
            q.push(start); // q = [0]
            vis[start] = true; // vis = [T, F, F, F]
            int seen = 1; // seen = how many distinct nodes we visited (including the starting one).

            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = true;
                        ++seen;
                        q.push(v);
                    }
                }
            }

            if (seen != n)
                return false; // this start cannot reach all nodes → disconnected
        }

        // Passed: exactly n-1 edges, and every node can reach every other node
        return true;
    }
};

// ---- Demo driver ----
int main()
{
    Solution sol;

    int n1 = 5;
    vector<vector<int>> e1 = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << (sol.validTree(n1, e1) ? "true" : "false") << "\n"; // true

    int n2 = 5;
    vector<vector<int>> e2 = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout << (sol.validTree(n2, e2) ? "true" : "false") << "\n"; // false

    return 0;
}





// BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // 1) Tree must have exactly n-1 edges
        if ((int)edges.size() != n - 1) return false;

        // 2) Build adjacency list
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 3) Single BFS from node 0 to check connectivity
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int seen = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    ++seen;
                    q.push(v);
                }
            }
        }

        // All nodes must be reachable
        return seen == n;
    }
};
//? Brute Force
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// edges = [[1,2], [1,3], [3,4], [2,4]]
// Expected output → [2,4]

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();  // Total number of edges (and nodes since graph is 1-indexed)

        // Try removing edges from last to first
        for (int skip = n - 1; skip >= 0; --skip) {
            // Step 1: Build adjacency list excluding the skipped edge
            vector<vector<int>> adj(n + 1);
            for (int i = 0; i < n; ++i) {
                if (i == skip) continue;
                int u = edges[i][0], v = edges[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            // Step 2: BFS to check if graph is connected without this edge
            vector<bool> vis(n + 1, false);
            queue<int> q;
            int start = edges[0][0]; // any node (since all nodes exist in 1..n)
            vis[start] = true;
            q.push(start);
            int seen = 1; // number of nodes we can reach

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

            // Step 3: If all n nodes are reachable, removing this edge fixes the cycle
            if (seen == n) {
                return edges[skip];
            }
        }

        return {}; // Should never reach here as per problem constraints
    }
};

// ---- Demo driver ----
int main() {
    Solution sol;

    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {3, 4}, {2, 4}};
    vector<int> result1 = sol.findRedundantConnection(edges1);
    cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;  // Expected: [2,4]

    vector<vector<int>> edges2 = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
    vector<int> result2 = sol.findRedundantConnection(edges2);
    cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;  // Expected: [3,4]

    return 0;
}




//? Disjoint Set Union (Union–Find)
#include <iostream>
#include <vector>
#include <numeric>   // iota
using namespace std;

struct DSU {
    vector<int> parent, rankv;
    DSU(int n) : parent(n), rankv(n, 0) { iota(parent.begin(), parent.end(), 0); }

    int find(int x) {                   // Path compression
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {          // Union by rank; returns false if already same set
        a = find(a); b = find(b);
        if (a == b) return false;       // adding this edge forms a cycle
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = (int)edges.size();      // nodes labeled 1..n
        DSU dsu(n + 1);                 // 1-based indexing

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (!dsu.unite(u, v)) {     // u and v already connected → e is redundant
                return e;
            }
        }
        return {}; // per problem constraints, we should always return earlier
    }
};

// ---- Demo driver ----
int main() {
    Solution sol;

    vector<vector<int>> edges1 = {{1,2},{1,3},{3,4},{2,4}};
    auto ans1 = sol.findRedundantConnection(edges1);
    cout << "[" << ans1[0] << ", " << ans1[1] << "]\n"; // Expected: [2,4]

    vector<vector<int>> edges2 = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    auto ans2 = sol.findRedundantConnection(edges2);
    cout << "[" << ans2[0] << ", " << ans2[1] << "]\n"; // Expected: [3,4]

    return 0;
}
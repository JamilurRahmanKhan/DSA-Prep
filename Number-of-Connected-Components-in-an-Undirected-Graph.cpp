#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int components = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                components++;
                queue<int> q;
                q.push(i);
                vis[i] = true;

                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : adj[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }

        return components;
    }
};

// Demo
int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {4,5}};
    cout << sol.countComponents(6, edges);  // Output: 2
}

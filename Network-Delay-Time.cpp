//?Brute Force
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(int u, int time, vector<vector<pair<int,int>>>& adj, vector<int>& dist){
        // Each node keeps the fastest time it’s been reached → dist[u].
        // If a new path is slower than the best known → skip (prune).
        if(time >= dist[u]) return;

        dist[u] = time;

        // Recurse deeper with dfs(v, time + w) to spread the signal.
        for(auto& [v,w] : adj[u]){
            dfs(v, time+w, adj, dist);
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build a directed weighted graph → adj[u] = [(v, time)].
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& e: times){
            adj[e[0]].push_back({e[1],e[2]});
        }

        //Use DFS to explore all paths:
        vector<int> dist(n+1, INT_MAX);
        dfs(k,0,adj,dist);

        // After DFS, take the maximum time in dist → the delay for all signals to arrive.
        int maxTime = 0;
        for(int i=1; i<=n; i++){
            // If any node has INF → unreachable → return -1.
            if(dist[i] == INT_MAX) return -1; 
            
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};

// ---- Demo ----
int main() {
    Solution sol;

    vector<vector<int>> t1 = {{2,1,1},{2,3,1},{3,4,1}};
    cout << sol.networkDelayTime(t1, 4, 2) << endl; // 2

    vector<vector<int>> t2 = {{1,2,1}};
    cout << sol.networkDelayTime(t2, 2, 1) << endl; // 1

    vector<vector<int>> t3 = {{1,2,1}};
    cout << sol.networkDelayTime(t3, 2, 2) << endl; // -1

    return 0;
}



//?Dijkstra’s Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // Step 2: Min-heap (priority queue) for Dijkstra
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);

        // Start from node k
        dist[k] = 0;
        pq.push({0, k}); // {time, node}

        // Step 3: Dijkstra’s relaxation process
        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            if (time > dist[u]) continue; // skip outdated entry

            for (auto &[v, w] : adj[u]) {
                if (time + w < dist[v]) {
                    dist[v] = time + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Step 4: Find the max time to reach all nodes
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1; // some node unreachable
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};

// ---- Demo driver ----
int main() {
    Solution sol;
    vector<vector<int>> times = {{1,2,1},{2,3,1},{1,4,4},{3,4,1}};
    int n = 4, k = 1;
    cout << sol.networkDelayTime(times, n, k); // Output: 3
}

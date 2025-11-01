//Approach-1 (Using BFS Topological Sort Concept)
#include <iostream>         // std::cout, std::endl
#include <vector>           // std::vector
#include <queue>            // std::queue
#include <unordered_map>    // std::unordered_map
using namespace std;

class Solution {
public:
    vector<int> topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree){
        queue<int> que;
        int count = 0;
        vector<int> result;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                result.push_back(i);
                count++;
                que.push(i);
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v: adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    result.push_back(v);
                    count++;
                    que.push(v);
                }
            }
        }

        if(count != n) return {};

        return result;
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            //b-->a
            adj[b].push_back(a);
            indegree[a]++;
        }
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};
// --------------------------------------------
// Demo Driver
// --------------------------------------------
int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    Solution sol;
    vector<int> order = sol.findOrder(numCourses, prerequisites);

    // Print result
    cout << "Course order: ";
    if (order.empty()) {
        cout << "No valid order (cycle detected)";
    } else {
        for (int c : order)
            cout << c << " ";
    }
    cout << endl;

    return 0;
}
// Course order: 0 1 2 3




//Approach-2 (Using DFS)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// --------------------------------------------
// Course Schedule II — DFS Topological Sort
// --------------------------------------------
class Solution {
public:
    bool hasCycle = false;

    // Depth-First Search to detect cycles and build topological order
    void DFS(unordered_map<int, vector<int>> &adj, int u,
             vector<bool>& visited, stack<int>& st, vector<bool>& inRecursion) {

        visited[u] = true;
        inRecursion[u] = true;

        // Explore all neighbors (courses dependent on u)
        for (int &v : adj[u]) {
            // If neighbor is in recursion → cycle detected
            if (inRecursion[v]) {
                hasCycle = true;
                return;
            }

            // If not yet visited → DFS deeper
            if (!visited[v])
                DFS(adj, v, visited, st, inRecursion);
        }

        // Push current course after exploring all dependencies
        st.push(u);

        // Backtrack → remove from current recursion path
        inRecursion[u] = false;
    }

    // Main function to find a valid course order
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        hasCycle = false;
        stack<int> st;

        // Step 1: Build adjacency list
        for (auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            // Edge: b → a (b must be done before a)
            adj[b].push_back(a);
        }

        // Step 2: DFS from every unvisited node
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i])
                DFS(adj, i, visited, st, inRecursion);
        }

        // Step 3: If cycle found → return empty vector
        if (hasCycle)
            return {};

        // Step 4: Pop from stack to get topological order
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

// --------------------------------------------
// Demo Driver
// --------------------------------------------
int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    Solution sol;
    vector<int> order = sol.findOrder(numCourses, prerequisites);

    cout << "Course order: ";
    if (order.empty()) {
        cout << "No valid order (cycle detected)";
    } else {
        for (int c : order)
            cout << c << " ";
    }
    cout << endl;

    return 0;
}
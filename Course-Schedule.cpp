#include <iostream>         // std::cout, std::endl
#include <vector>           // std::vector
#include <queue>            // std::queue
#include <unordered_map>    // std::unordered_map
using namespace std;

// /*
//     Problem: Course Schedule (can you finish all courses?)
//     Approach: Kahn's Algorithm (Topological Sort using BFS)
//     Idea:
//       - Build a directed graph from prerequisites: b -> a (to take 'a', you must finish 'b')
//       - indegree[a] = number of prerequisites of course 'a'
//       - Push all courses with indegree 0 into a queue (they can be taken first)
//       - Repeatedly pop from queue, "finish" that course, and reduce indegree of its dependents
//       - If a dependent's indegree becomes 0, push it into the queue
//       - Count how many courses we can "finish". If it's all courses, return true; else there's a cycle → false
// */
// class Solution {
// public:
//     // Runs Kahn's BFS topological sort and returns true if all nodes can be visited (no cycle)
//     bool topologicalSortCheck(unordered_map<int, vector<int>> &adj,
//                               int n,
//                               vector<int> &indegree) {
//         queue<int> que;  // courses that are currently available to take (indegree == 0)
//         int count = 0;   // how many courses we've "finished" (popped from queue or initially enqueued)

//         // 1) Initialize the queue with all courses having indegree 0 (no prerequisites)
//         for (int i = 0; i < n; i++) {
//             if (indegree[i] == 0) {
//                 que.push(i);
//                 count++;  // we can consider them "taken" in order (or at least "ready")
//             }
//         }

//         // 2) BFS: pop a course, reduce indegree of its neighbors (dependent courses)
//         while (!que.empty()) {
//             int u = que.front();
//             que.pop();

//             // For every course v that depends on u (edge u -> v)
//             for (int &v : adj[u]) {
//                 indegree[v]--;           // one prerequisite (u) is now satisfied
//                 if (indegree[v] == 0) {  // if v now has no remaining prerequisites
//                     que.push(v);         // it becomes available to take
//                     count++;             // count it as processed/ready
//                 }
//             }
//         }

//         // 3) If we processed all courses, there was no cycle; otherwise, a cycle exists
//         //    (A cycle would keep some courses with indegree > 0 forever.)
//         return (count == n);
//     }

//     // Main API: returns true if we can finish all courses, else false
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         // Adjacency list: for each course u, adj[u] contains courses v that depend on u (u -> v)
//         unordered_map<int, vector<int>> adj;

//         // indegree[i] = number of prerequisites of course i
//         vector<int> indegree(numCourses, 0);

//         // Build graph and indegree
//         // Each pair [a, b] means: b -> a (you must take b before a)
//         for (auto &vec : prerequisites) {
//             int a = vec[0];
//             int b = vec[1];
//             adj[b].push_back(a); // edge: b -> a
//             indegree[a]++;       // 'a' has one more prerequisite
//         }

//         // If there is a cycle, we can't finish all courses
//         return topologicalSortCheck(adj, numCourses, indegree);
//     }
// };
// numCourses (n) = 4
// prerequisites = [[1,0], [2,1], [3,1]]

class Solution {
public:
    
    bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> que;
        
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                count++;
                que.push(i);
            }
        }
        
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]) {
                
                indegree[v]--;
                
                if(indegree[v] == 0) {
                    count++;
                    que.push(v);
                }
                
            }
            
        }
        
        if(count == n) //I was able to visit all nodes (course)
            return true; //i.e. I was able to finish all courses
        
        return false; //means there was a cycle and I couldn't complete all courses
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;
        
        vector<int> indegree(numCourses, 0); //kahn's algo
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b ---> a
            adj[b].push_back(a);
            
            //arrow ja raha hai 'a' me
            indegree[a]++;
        }
        
        
        //if cycle is present, not possible
        
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};


// ---------------- Demo driver (you can edit freely) ----------------
int main() {
    Solution sol;

    // Test Case 1: Possible (no cycle)
    // 0 -> 1 -> 2 -> 3  (linear chain, all can be finished)
    {
        int numCourses = 4;
        vector<vector<int>> prerequisites = {{1,0}, {2,1}, {3,2}};
        bool ok = sol.canFinish(numCourses, prerequisites);
        cout << "Test 1 (should be TRUE): " << (ok ? "true" : "false") << endl;
    }

    // Test Case 2: Impossible (has a cycle)
    // 0 -> 1 -> 0
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{0,1}, {1,0}};
        bool ok = sol.canFinish(numCourses, prerequisites);
        cout << "Test 2 (should be FALSE): " << (ok ? "true" : "false") << endl;
    }

    // You can add more tests here

    return 0;
}









#include <iostream>         // std::cout, std::endl
#include <vector>           // std::vector
#include <unordered_map>    // std::unordered_map
using namespace std;

// /*
//   Course Schedule — Approach 2: DFS Cycle Check

//   Idea:
//     - Build a directed graph from prerequisites: edge b -> a (must take b before a).
//     - Use DFS with a recursion-stack tracker to detect cycles.
//     - If any cycle exists, we cannot finish all courses.

//   Key structures:
//     - adj[u] = list of neighbors v where u -> v (v depends on u)
//     - visited[i] = have we ever visited node i in ANY DFS?
//     - inRecursion[i] = is node i currently in the active recursion stack?

//   Cycle rule:
//     - If during DFS we reach a node that is already in the current recursion stack (inRecursion[v] == true),
//       there is a back-edge -> cycle detected.
// */

// class Solution {
// public:
//     // DFS returns true if a cycle is found starting from node u
//     bool isCycleDFS(unordered_map<int, vector<int>>& adj,
//                     int u,
//                     vector<bool>& visited,
//                     vector<bool>& inRecursion) {
//         // Mark current node as visited globally and put it into the current recursion stack
//         visited[u] = true;
//         inRecursion[u] = true;

//         // Explore all neighbors v (u -> v)
//         for (int v : adj[u]) {
//             // If v not visited, DFS on v
//             if (!visited[v]) {
//                 if (isCycleDFS(adj, v, visited, inRecursion)) {
//                     return true; // cycle found below
//                 }
//             }
//             // If v is currently in recursion stack, we found a back-edge -> cycle
//             else if (inRecursion[v]) {
//                 return true;
//             }
//         }

//         // Done exploring u: remove it from recursion stack
//         inRecursion[u] = false;
//         return false; // no cycle from this path
//     }

//     // Main API: return true if all courses can be finished (i.e., no cycle)
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         // Build adjacency list for graph: b -> a (must take b before a)
//         unordered_map<int, vector<int>> adj;
//         for (auto& vec : prerequisites) {
//             int a = vec[0];
//             int b = vec[1];
//             adj[b].push_back(a);  // edge b -> a
//         }

//         // visited: have we seen this node before in any DFS?
//         // inRecursion: is this node in the CURRENT DFS call stack?
//         vector<bool> visited(numCourses, false);
//         vector<bool> inRecursion(numCourses, false);

//         // Try starting a DFS from every node (handles disconnected graphs)
//         for (int i = 0; i < numCourses; i++) {
//             if (!visited[i]) {
//                 if (isCycleDFS(adj, i, visited, inRecursion)) {
//                     return false; // cycle detected -> cannot finish all courses
//                 }
//             }
//         }
//         return true; // no cycles anywhere -> can finish all courses
//     }
// };

class Solution {
public:
    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        
        for(int &v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if(inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b ---> a
            adj[b].push_back(a);
        }
        
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
                return false;
        }
        
        return true;
    }
};
// numCourses = 3
// prerequisites = [[1,0], [2,1], [0,2]]
// Meaning: 0 → 1 → 2 → 0 (cycle)

// ---------------- Demo driver (you can edit or remove for LeetCode) ----------------
int main() {
    Solution sol;

    // Test 1: No cycle (possible)
    // Graph: 0 -> 1 -> 2 -> 3
    {
        int numCourses = 4;
        vector<vector<int>> prerequisites = { {1,0}, {2,1}, {3,2} };
        bool ok = sol.canFinish(numCourses, prerequisites);
        cout << "Test 1 (should be TRUE): " << (ok ? "true" : "false") << endl;
    }

    // Test 2: Has a cycle (impossible)
    // Graph: 0 -> 1 -> 0
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = { {0,1}, {1,0} };
        bool ok = sol.canFinish(numCourses, prerequisites);
        cout << "Test 2 (should be FALSE): " << (ok ? "true" : "false") << endl;
    }

    // Test 3: Disconnected graph with a cycle in one component
    {
        int numCourses = 5;
        vector<vector<int>> prerequisites = {
            {1,0}, // 0->1
            {2,1}, // 1->2
            {0,2}, // 2->0 (cycle among 0,1,2)
            {4,3}  // 3->4 (separate acyclic chain)
        };
        bool ok = sol.canFinish(numCourses, prerequisites);
        cout << "Test 3 (should be FALSE): " << (ok ? "true" : "false") << endl;
    }

    // Test 4: Multiple independent chains, no cycles
    {
        int numCourses = 6;
        vector<vector<int>> prerequisites = {
            {2,1}, {1,0},   // 0->1->2
            {5,4}, {4,3}    // 3->4->5
        };
        bool ok = sol.canFinish(numCourses, prerequisites);
        cout << "Test 4 (should be TRUE): " << (ok ? "true" : "false") << endl;
    }

    return 0;
}
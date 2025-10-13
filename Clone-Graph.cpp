// DFS
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node in the graph
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    unordered_map<Node*, Node*> mp; // Maps original nodes to cloned nodes

    // DFS helper to clone graph
    void DFS(Node* node, Node* clone_node){
        for(Node* n : node->neighbors){
            if(mp.find(n) == mp.end()){ // If neighbor not cloned
                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);

                DFS(n, clone); // Recursively clone neighbor
            }
            else{ // Already cloned neighbor
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }

    // Function to clone the graph
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        mp.clear();

        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;

        DFS(node, clone_node);
        return clone_node;
    }
};

// Helper function to print a graph (BFS)
void printGraph(Node* node) {
    if(!node) return;
    unordered_map<Node*, bool> visited;
    vector<Node*> queue;
    queue.push_back(node);

    while(!queue.empty()) {
        Node* curr = queue.back();
        queue.pop_back();

        if(visited[curr]) continue;
        visited[curr] = true;

        cout << "Node " << curr->val << " -> ";
        for(Node* n : curr->neighbors) {
            cout << n->val << " ";
            if(!visited[n]) queue.push_back(n);
        }
        cout << endl;
    }
}

int main() {
    // Example graph:
    // Node 1 connected to 2 and 3
    // Node 2 connected to 3
    // Node 3 connected to 1

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1->neighbors = {node2, node3};
    node2->neighbors = {node3};
    node3->neighbors = {node1};

    Solution sol;
    Node* clonedGraph = sol.cloneGraph(node1);

    cout << "Original Graph:" << endl;
    printGraph(node1);

    cout << "\nCloned Graph:" << endl;
    printGraph(clonedGraph);

    return 0;
}




// BFS
class Solution
{
public:
    unordered_map<Node *, Node *> mp;

    void BFS(queue<Node *> &que)
    {
        while (!que.empty())
        {
            Node *node = que.front();
            Node *clone_node = mp[node];
            que.pop();
            for (Node *n : node->neighbors)
            {
                if (mp.find(n) == mp.end())
                {
                    Node *clone = new Node(n->val);
                    mp[n] = clone;
                    clone_node->neighbors.push_back(clone);

                    que.push(n);
                }
                else
                {
                    clone_node->neighbors.push_back(mp[n]);
                }
            }
        }
    }

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        mp.clear();

        Node *clone_node = new Node(node->val);
        mp[node] = clone_node;

        queue<Node *> que;
        que.push(node);
        BFS(que);
        return clone_node;
    }
};

// BFS
#include <iostream>
#include <queue>
#include <algorithm> // for max
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while (!q.empty()) {
            int n = q.size();  // number of nodes in current level
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;  // completed one level
        }
        
        return depth;
    }
};

// Driver code (to test)
int main() {
    /*
        Construct the following tree:
               3
              / \
             9  20
               /  \
              15   7
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Depth: " << sol.maxDepth(root) << endl;  // Expected: 3

    return 0;
}




//DFS
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root) return 0;
//         return 1 + max(maxDepth(root->left), maxDepth(root->right));
//     }
// };
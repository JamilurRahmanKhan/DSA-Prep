// BFS
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN}); // Start with root and lowest possible maxVal

        while (!q.empty()) {
            auto [node, maxVal] = q.front();
            q.pop();

            if (node->val >= maxVal) {
                res++;
            }

            if (node->left) {
                q.push({node->left, max(node->val, maxVal)});
            }
            if (node->right) {
                q.push({node->right, max(node->val, maxVal)});
            }
        }
        return res;
    }
};

// Helper function to build a sample tree
TreeNode* buildSampleTree() {
    /*
            3
           / \
          1   4
         /   / \
        3   1   5
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();

    Solution sol;
    int result = sol.goodNodes(root);

    cout << "Number of good nodes: " << result << endl; // Expected output: 4

    return 0;
}



// DFS

// class Solution {
// public:
//     int goodNodes(TreeNode* root) {
//         return dfs(root, root->val);
//     }
// private:
//     int dfs(TreeNode* node, int maxVal){
//         if(!node) return 0;

//         int res = (node->val >= maxVal) ? 1: 0;
//         maxVal = max(node->val, maxVal);
//         res += dfs(node->left, maxVal);
//         res += dfs(node->right, maxVal);
//         return res;
//     }
// };
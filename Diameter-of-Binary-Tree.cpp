#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int solve(TreeNode* root, int& result){
        if(!root) return 0;

        int left = solve(root->left, result);
        int right = solve(root->right, result);

        result = max(result, left + right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int result = INT_MIN;
        solve(root, result);

        return result;
    }
};

int main() {
    // Example tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter of the binary tree: " << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}
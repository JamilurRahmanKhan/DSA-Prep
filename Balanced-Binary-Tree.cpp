// brute force
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = height(root->left);
        int right = height(root->right);
        if(abs(left-right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};

// Example usage
int main() {
    // Creating the tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

//         1
//        / \
//       2   3
//      / \   \
//     4   5   6
//    /         \
//   7           8
//  /             \
// 9               10
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    if(sol.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}


//optimized way
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         int height = getHeight(root);

//         if(height == -1) return false;
//         return true;
//     }
//     int getHeight(TreeNode* root){
//         if(!root) return 0;
//         int left = getHeight(root->left);
//         int right = getHeight(root->right);
//         if(left == -1 || right == -1) return -1;
//         if(abs(left-right)>1) return -1;
//         return 1 + max(left, right);
//     }
// };
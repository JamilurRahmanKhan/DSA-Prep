// BFS
#include <iostream>
#include <queue>
#include <tuple>
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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        queue<tuple<TreeNode*, long, long>> q;
        q.push(make_tuple(root, LONG_MIN, LONG_MAX));

        while(!q.empty()){
            auto [node, left, right] = q.front();
            q.pop();

            if(!(left < node->val && node->val < right)) return false;

            if(node->left){
                q.push(make_tuple(node->left, left, node->val));
            }
            if(node->right){
                q.push(make_tuple(node->right, node->val, right));
            }
        }
        return true;
    }
};

// Helper function to build a sample tree
TreeNode* buildSampleBST() {
    /*
           5
          / \
         3   7
        / \   \
       2   4   8
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);
    return root;
}

int main() {
    TreeNode* root = buildSampleBST();
    Solution sol;

    if(sol.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    return 0;
}


// DFS

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         return valid(root, LONG_MIN, LONG_MAX);
//     }

//     bool valid(TreeNode* node, long left, long right){
//         if(!node) return true;

//         if((!(left < node->val && node->val < right))) return false;

//         return valid(node->left, left, node->val) && valid(node->right, node->val, right);
//     }
// };


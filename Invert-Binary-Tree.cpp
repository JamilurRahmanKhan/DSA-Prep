// BFS
#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            // Swap children
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;

            // Push children if they exist
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return root;
    }
};

// Helper function to print tree in level order
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if(node){
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << endl;
}

int main() {
    // Build test tree: [4,2,7,1,3,6,9]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original tree (level order): ";
    printLevelOrder(root);

    Solution sol;
    TreeNode* inverted = sol.invertTree(root);

    cout << "Inverted tree (level order): ";
    printLevelOrder(inverted);

    return 0;
}



// Recursive
// #include <iostream>
// using namespace std;

// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == NULL) {
//             return NULL;
//         }

//         TreeNode* left = invertTree(root->left);
//         TreeNode* right = invertTree(root->right);

//         root->left = right;
//         root->right = left;

//         return root;
//     }
// };
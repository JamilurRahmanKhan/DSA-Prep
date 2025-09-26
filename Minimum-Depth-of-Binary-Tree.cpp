// DFS 111
#include <iostream>
#include <queue>
#include <climits>  // for INT_MAX
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int left = root->left ? minDepth(root->left) : INT_MAX;
        int right = root->right ? minDepth(root->right) : INT_MAX;
        return 1 + min(left, right);
    }
};

// Helper function to build a small test tree
TreeNode* buildTestTree() {
    // Example: 
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTestTree();
    cout << "Minimum depth of tree = " << sol.minDepth(root) << endl;
    return 0;
}






// BFS
// #include <iostream>
// #include <queue>
// #include <climits>  // for INT_MAX
// using namespace std;

// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if(root==NULL) return 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         int depth = 1;
//         while(!q.empty()){
//             int n = q.size();
//             while(n--){
//                 TreeNode* temp = q.front();
//                 q.pop();
//                 if(temp->left == NULL && temp->right == NULL){
//                     return depth;
//                 }
//                 if(temp->left != NULL) q.push(temp->left);
//                 if(temp->right != NULL) q.push(temp->right);
//             }
//             depth++;
//         }
//         return -1;
//     }
// };

// // Helper function to build a small test tree
// TreeNode* buildTestTree() {
//     // Example: 
//     //       1
//     //      / \
//     //     2   3
//     //    /
//     //   4
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     return root;
// }

// int main() {
//     Solution sol;
//     TreeNode* root = buildTestTree();
//     cout << "Minimum depth of tree = " << sol.minDepth(root) << endl;
//     return 0;
// }
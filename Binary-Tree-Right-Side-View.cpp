// DFS
#include <iostream>
#include <vector>
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
    vector<int> res;

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if (!node) return;

        // If visiting this depth for the first time, record the node
        if (res.size() == depth) {
            res.push_back(node->val);
        }

        // First go right (rightmost visible), then left
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Build example tree:
    //        1
    //       / \
    //      2   3
    //       \    \
    //        5    4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right side view: ";
    printVector(result);

    return 0;
}



// BFS

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        vector<int> result;

        q.push(root);

        while(!q.empty()){
            int n = q.size();
            TreeNode* rightNode = NULL;
            while(n--){
                rightNode = q.front();
                q.pop();

                if(rightNode->left){
                    q.push(rightNode->left);
                }
                if(rightNode->right){
                    q.push(rightNode->right);
                }
                
            }
            result.push_back(rightNode->val);
        }
        return result;
    }
};
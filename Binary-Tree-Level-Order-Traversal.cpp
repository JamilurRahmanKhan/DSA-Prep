// DFS
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if (!node) return;

        if (res.size() == depth) {
            res.push_back(vector<int>());
        }

        res[depth].push_back(node->val);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};

// Helper function to print the result
void printResult(const vector<vector<int>>& levels) {
    for (int i = 0; i < levels.size(); i++) {
        cout << "Level " << i << ": ";
        for (int val : levels[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Build a test tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Print result
    printResult(result);

    // Cleanup (free memory)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}



// BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int size = q.size();

            while(size--){
                TreeNode * node = q.front();
                q.pop();

                if(node){
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(!level.empty()){
                res.push_back(level);
            }
        }
        return res;
    }
};
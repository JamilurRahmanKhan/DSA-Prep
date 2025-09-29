// Brute Force
#include <iostream>
#include <vector>
#include <algorithm>
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        dfs(root, arr);
        sort(arr.begin(), arr.end()); // sort values
        return arr[k - 1]; // return k-th smallest (1-based index)
    }

    void dfs(TreeNode* node, vector<int>& arr) {
        if (!node) return;
        arr.push_back(node->val);
        dfs(node->left, arr);
        dfs(node->right, arr);
    }
};

// Helper function to build a sample BST
TreeNode* buildSampleBST() {
    /*
           5
          / \
         3   6
        / \
       2   4
      /
     1
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    return root;
}

int main() {
    TreeNode* root = buildSampleBST();
    Solution sol;

    int k = 3; // Example: find the 3rd smallest element
    cout << "The " << k << "rd smallest element is: " 
         << sol.kthSmallest(root, k) << endl;

    return 0;
}



// in order traversal dfs
class Solution {
public:
    int pos = 0;
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = inOrder(root, k);
        if(!root) return -1;
        return node->val;
    }

    TreeNode* inOrder(TreeNode* node, int k){
        if(!node) return NULL;

        TreeNode* left = inOrder(node->left, k);
        if(left) return left;

        pos++;
        if(pos == k) return node;
        return inOrder(node->right, k);
    }
};




// Morris Traversal
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                k--;
                if (k == 0) return curr->val;
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    k--;
                    if (k == 0) return curr->val;
                    curr = curr->right;
                }
            }
        }
        return -1;
    }
};
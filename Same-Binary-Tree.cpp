// DFS
#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;          // Both empty
        if(!p || !q) return false;         // One empty, other not
        if(p->val != q->val) return false; // Different values
        // Recurse for left & right
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Helper function to print results
void printResult(bool result) {
    cout << (result ? "True (Trees are same)" : "False (Trees are different)") << endl;
}

// Build your first example trees (expected FALSE)
pair<TreeNode*, TreeNode*> buildExample1() {
    // Tree p
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);
    p->right->right = new TreeNode(6);
    p->left->left->left = new TreeNode(7);

    // Tree q
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    q->left->left = new TreeNode(4);
    q->left->right = new TreeNode(5);
    q->right->left = new TreeNode(6);
    q->left->left->left = new TreeNode(7);

    return {p, q};
}

// Build a second example (identical trees → expected TRUE)
pair<TreeNode*, TreeNode*> buildExample2() {
    // Tree p
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree q (exact copy)
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    return {p, q};
}

int main() {
    Solution sol;

    cout << "Example 1:" << endl;
    pair<TreeNode*, TreeNode*> ex1 = buildExample1();
    printResult(sol.isSameTree(ex1.first, ex1.second)); // Expected: False

    cout << "\nExample 2:" << endl;
    pair<TreeNode*, TreeNode*> ex2 = buildExample2();
    printResult(sol.isSameTree(ex2.first, ex2.second)); // Expected: True

    return 0;
}




// BFS
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()) {
            TreeNode* first = q1.front();
            TreeNode* second = q2.front();
            q1.pop();
            q2.pop();
            if(first->val != second->val)
                return false;
          
            if(first->left && second->left) {
                q1.push(first->left);
                q2.push(second->left);
            } else if(first->left || second->left)
                return false;
          
            if(first->right && second->right) {
                q1.push(first->right);
                q2.push(second->right);
            } else if(first->right || second->right)
                return false;
        }
        return true; 
    }
};

// Tree p:   1     Tree q: 1
//          / \           / \
//         2   3         2   3

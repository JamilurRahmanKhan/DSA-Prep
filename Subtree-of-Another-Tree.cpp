#include <iostream>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    string preOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return "null";
        }

        string result = "^" + to_string(node->val);
        result += preOrderTraversal(node->left);
        result += preOrderTraversal(node->right);

        return result;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string fullTree = preOrderTraversal(root);
        string subTree = preOrderTraversal(subRoot);

        return fullTree.find(subTree) != string::npos; // check if subTree string is inside fullTree string
    }
};
// Root tree:    3         Subtree:   4
//              / \                  / \
//             4   5                1   2
//            / \
//           1   2

// Example usage:
int main() {
    // Create root tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // Create subRoot tree
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;
    if (sol.isSubtree(root, subRoot)) {
        cout << "subRoot is a subtree of root" << endl;
    } else {
        cout << "subRoot is NOT a subtree of root" << endl;
    }

    return 0;
}



/*
Intuition #2 - Serialization
Another way to check if one tree is a subtree of another is to convert each tree into a unique string representation (serialization). If the serialized form of the smaller tree appears as a substring in the larger tree's serialization, then the smaller tree is indeed a subtree.

Approach #2
Serialize Both Trees: Perform a preorder-like traversal and create a string that includes each node’s value and markers for null nodes.
Substring Check: Check if the serialized string of the subRoot is contained in the serialized string of the main root.
Example Walkthrough #2
For:

root = [3,4,5,1,2]
subRoot = [4,1,2]
Serialization might produce something like:

root: (3,(4,(1,N,N),(2,N,N)),(5,N,N))
subRoot: (4,(1,N,N),(2,N,N))
Since subRoot's serialization is a substring of root's serialization, return true.

Complexity #2
Time complexity: O(n+m) to scan both trees.
Space complexity: O(n+m) for storing the serialized strings.
*/

// Serialization And Pattern Matching
class Solution {
private:
    string serialize(TreeNode* node) {
        if (!node) return "N";
        return "(" + to_string(node->val) + "," + serialize(node->left) + "," + serialize(node->right) + ")";
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootSerialized = serialize(root);
        string subRootSerialized = serialize(subRoot);
        return rootSerialized.find(subRootSerialized) != string::npos;
    }
};
#include <iostream>
#include <vector>
#include <bits/stdc++.h> // for common STL usage
using namespace std;
// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Solution class
class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (t1 == nullptr || t2 == nullptr)
            return false;
        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isMirror(root->left, root->right);
    }
};
// Helper function to create test trees manually
TreeNode* createSymmetricTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    return root;
}
TreeNode* createAsymmetricTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);
    return root;
}
int main() {
    Solution sol;
    vector<TreeNode*> testCases = {
        createSymmetricTree(),
        createAsymmetricTree(),
        nullptr  // Edge case: empty tree (symmetric)
    };
    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ": ";
        bool result = sol.isSymmetric(testCases[i]);
        cout << (result ? "Symmetric" : "Not Symmetric") << endl;
    }
    return 0;
}
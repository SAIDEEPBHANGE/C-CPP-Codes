#include <bits/stdc++.h>
using namespace std;
// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Solution class
class Solution {
public:
    int LastDepth(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int left = LastDepth(node->left);
        int right = LastDepth(node->right);
        int depth = max(left, right) + 1;
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return LastDepth(root);
    }
};
// Helper functions to create test trees
TreeNode* createTree1() {
    // Tree:
    //      1
    //     / \
    //    2   3
    //   /
    //  4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), nullptr);
    root->right = new TreeNode(3);
    return root;
}
TreeNode* createTree2() {
    // Tree:
    //      1
    //     /
    //    2
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    return root;
}
TreeNode* createTree3() {
    // Empty tree
    return nullptr;
}
int main() {
    Solution sol;
    vector<TreeNode*> testCases = {
        createTree1(),
        createTree2(),
        createTree3()
    };
    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << " → Max Depth: " << sol.maxDepth(testCases[i]) << endl;
    }
    return 0;
}
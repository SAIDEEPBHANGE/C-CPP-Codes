#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
#define pairint pair<TreeNode*, int>
    pairint FindLCA(TreeNode* c) {
        if (!c)
            return make_pair(nullptr, 0);
        pairint left = FindLCA(c->left);
        pairint right = FindLCA(c->right);
        if (left.second == right.second)
            return make_pair(c, 1 + left.second);
        else if (left.second > right.second)
            return make_pair(left.first, 1 + left.second);
        return make_pair(right.first, 1 + right.second);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pairint result = FindLCA(root);
        return result.first;
    }
    // Helper function to build the tree from a level-order array input
    TreeNode* buildTree(const vector<int>& values) {
        if (values.empty()) return nullptr;
        TreeNode* root = new TreeNode(values[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < values.size()) {
            TreeNode* node = q.front();
            q.pop();
            if (i < values.size() && values[i] != NULL) {
                node->left = new TreeNode(values[i]);
                q.push(node->left);
            }
            i++;
            if (i < values.size() && values[i] != NULL) {
                node->right = new TreeNode(values[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
    // Helper function to print tree in level order for easy verification
    void printTree(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    }
};
int main() {
    Solution sol;
    // Test case 1
    vector<int> test1 = {3, 5, 1, 6, 2, 0, 8, NULL, NULL, 7, 4};
    TreeNode* root1 = sol.buildTree(test1);
    TreeNode* result1 = sol.lcaDeepestLeaves(root1);
    cout << "LCA of deepest leaves (Test 1): " << result1->val << endl;
    // Test case 2
    vector<int> test2 = {1};
    TreeNode* root2 = sol.buildTree(test2);
    TreeNode* result2 = sol.lcaDeepestLeaves(root2);
    cout << "LCA of deepest leaves (Test 2): " << result2->val << endl;
    // Test case 3
    vector<int> test3 = {0, 1, 3, NULL, 2};
    TreeNode* root3 = sol.buildTree(test3);
    TreeNode* result3 = sol.lcaDeepestLeaves(root3);
    cout << "LCA of deepest leaves (Test 3): " << result3->val << endl;
    return 0;
}
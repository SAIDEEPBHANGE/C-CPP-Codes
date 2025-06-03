#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
    bool getAllNode(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return getAllNode(p->left, q->left) && getAllNode(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return getAllNode(p, q);
    }
};
// Helper function to print result
void testCaseResult(int index, bool result) {
    cout << "Test Case " << index << ": " << (result ? "Same Tree" : "Different Tree") << endl;
}
// Main function with test cases
int main() {
    Solution solution;
    vector<pair<TreeNode*, TreeNode*>> testCases;
    // Test Case 1: Identical trees
    TreeNode* a1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* b1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    testCases.push_back({a1, b1});
    // Test Case 2: Different structure
    TreeNode* a2 = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode* b2 = new TreeNode(1, nullptr, new TreeNode(2));
    testCases.push_back({a2, b2});
    // Test Case 3: Different values
    TreeNode* a3 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* b3 = new TreeNode(1, new TreeNode(2), new TreeNode(4));
    testCases.push_back({a3, b3});
    // Test Case 4: Both null
    testCases.push_back({nullptr, nullptr});
    // Run all test cases
    for (int i = 0; i < testCases.size(); ++i) {
        bool result = solution.isSameTree(testCases[i].first, testCases[i].second);
        testCaseResult(i + 1, result);
    }
    return 0;
}
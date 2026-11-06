#include <bits/stdc++.h>
using namespace std;
/*
    Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};
class Solution {
private:
    /* -------- Approach 1: DFS (Recursive) -------- */
    void dfs(TreeNode* root, int level, vector<int>& sums) {
        if (!root) return;
        if (level == (int)sums.size())
            sums.push_back(0);
        sums[level] += root->val;
        dfs(root->left, level + 1, sums);
        dfs(root->right, level + 1, sums);
    }
public:
    // DFS-based solution
    int maxLevelSumDFS(TreeNode* root) {
        vector<int> sums;
        dfs(root, 0, sums);
        int maxLevel = 0;
        for (int i = 1; i < (int)sums.size(); i++) {
            if (sums[i] > sums[maxLevel])
                maxLevel = i;
        }
        return maxLevel + 1; // 1-based indexing
    }
    /* -------- Approach 2: BFS (Level Order Traversal) -------- */
    int maxLevelSumBFS(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int bestLevel = 1;
        int maxSum = INT_MIN;
        while (!q.empty()) {
            int sz = q.size();
            int sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                bestLevel = level;
            }
            level++;
        }
        return bestLevel;
    }
};
/* -------- Helper function to build test trees -------- */
TreeNode* buildTreeExample1() {
    // Tree:
    //        1
    //       / \
    //      7   0
    //     / \
    //    7  -8
    return new TreeNode(1,
            new TreeNode(7,
                new TreeNode(7),
                new TreeNode(-8)),
            new TreeNode(0));
}
TreeNode* buildTreeExample2() {
    // Tree:
    //        5
    //       / \
    //      2   3
    return new TreeNode(5, new TreeNode(2), new TreeNode(3));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<TreeNode*> testCases;
    testCases.push_back(buildTreeExample1());
    testCases.push_back(buildTreeExample2());
    for (int i = 0; i < (int)testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "  DFS Approach  -> Max Level: "
             << sol.maxLevelSumDFS(testCases[i]) << "\n";
        cout << "  BFS Approach  -> Max Level: "
             << sol.maxLevelSumBFS(testCases[i]) << "\n";
        cout << "-----------------------------\n";
    }
    return 0;
}

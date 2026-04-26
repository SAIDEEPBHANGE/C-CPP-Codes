#include <bits/stdc++.h>
using namespace std;
/*
    Problem: Sum of Root To Leaf Binary Numbers (LeetCode 1022)
    Each root-to-leaf path represents a binary number.
    Return the sum of these numbers.
*/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    /*
    ============================================================
    Approach 1: Recursive DFS (Bit Manipulation)
    Time Complexity: O(N)
    Space Complexity: O(H) (recursion stack)
    ============================================================
    */
    int dfsRecursive(TreeNode* root, int sum) {
        if (!root) return 0;
        sum = (sum << 1) | root->val;
        // If leaf node, return computed binary value
        if (!root->left && !root->right) {
            return sum;
        }
        return dfsRecursive(root->left, sum) +
               dfsRecursive(root->right, sum);
    }
    int sumRootToLeaf_Recursive(TreeNode* root) {
        return dfsRecursive(root, 0);
    }
    /*
    ============================================================
    Approach 2: Iterative DFS using Stack
    Time Complexity: O(N)
    Space Complexity: O(H)
    ============================================================
    */
    int sumRootToLeaf_IterativeDFS(TreeNode* root) {
        if (!root) return 0;
        int totalSum = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        while (!st.empty()) {
            auto [node, currSum] = st.top();
            st.pop();
            currSum = (currSum << 1) | node->val;
            if (!node->left && !node->right) {
                totalSum += currSum;
            }
            if (node->right) {
                st.push({node->right, currSum});
            }
            if (node->left) {
                st.push({node->left, currSum});
            }
        }
        return totalSum;
    }
    /*
    ============================================================
    Approach 3: BFS using Queue
    Time Complexity: O(N)
    Space Complexity: O(N)
    ============================================================
    */
    int sumRootToLeaf_BFS(TreeNode* root) {
        if (!root) return 0;
        int totalSum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, currSum] = q.front();
            q.pop();
            currSum = (currSum << 1) | node->val;
            if (!node->left && !node->right) {
                totalSum += currSum;
            }
            if (node->left) {
                q.push({node->left, currSum});
            }
            if (node->right) {
                q.push({node->right, currSum});
            }
        }
        return totalSum;
    }
};
/*
Helper function to build test trees manually
*/
TreeNode* buildTree1() {
    // Tree:
    //        1
    //       / \
    //      0   1
    //     / \   \
    //    0   1    1
    //
    // Paths:
    // 100 = 4
    // 101 = 5
    // 111 = 7
    // Sum = 16
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);
    return root;
}
TreeNode* buildTree2() {
    // Single node tree
    // 1
    // Output = 1
    return new TreeNode(1);
}
TreeNode* buildTree3() {
    // Tree:
    //     0
    //    / \
    //   1   1
    //  /
    // 0
    //
    // Paths:
    // 010 = 2
    // 01  = 1
    // Sum = 3
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    return root;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<TreeNode*> testCases;
    testCases.push_back(buildTree1());
    testCases.push_back(buildTree2());
    testCases.push_back(buildTree3());
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        int ans1 = sol.sumRootToLeaf_Recursive(testCases[i]);
        int ans2 = sol.sumRootToLeaf_IterativeDFS(testCases[i]);
        int ans3 = sol.sumRootToLeaf_BFS(testCases[i]);
        cout << "Recursive DFS Result     : " << ans1 << "\n";
        cout << "Iterative DFS Result     : " << ans2 << "\n";
        cout << "BFS Result               : " << ans3 << "\n";
        cout << "-----------------------------------\n";
    }
    return 0;
}
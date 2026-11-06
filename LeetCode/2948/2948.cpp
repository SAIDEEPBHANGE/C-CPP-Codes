#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        // Union-Find setup
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) parent[b] = a;
        };
        // Build swappable groups based on value differences and limit
        vector<pair<int, int>> pos_val;
        for (int i = 0; i < n; ++i)
            pos_val.push_back({nums[i], i});
        sort(pos_val.begin(), pos_val.end());
        for (int i = 1; i < n; ++i) {
            int prev_idx = pos_val[i - 1].second;
            int curr_idx = pos_val[i].second;
            if (abs(pos_val[i].first - pos_val[i - 1].first) <= limit) {
                unite(prev_idx, curr_idx);
            }
        }
        // Group indices and values by component
        unordered_map<int, vector<int>> group_indices, group_values;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            group_indices[root].push_back(i);
            group_values[root].push_back(nums[i]);
        }
        // Reassign values within each group in sorted order
        for (auto& [root, indices] : group_indices) {
            auto& values = group_values[root];
            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());
            for (int i = 0; i < indices.size(); ++i) {
                nums[indices[i]] = values[i];
            }
        }
        return nums;
    }
};
int main() {
    Solution sol;
    // Define test cases: each is a pair of (nums vector, limit)
    vector<pair<vector<int>, int>> testcases = {
        {{4, 2, 1, 3}, 2},
        {{1, 5, 3, 4, 2}, 3},
        {{10, 100, 20, 90, 30}, 15},
        {{7, 6, 5, 4}, 1}
    };
    for (int i = 0; i < testcases.size(); ++i) {
        vector<int> nums = testcases[i].first;
        int limit = testcases[i].second;
        vector<int> result = sol.lexicographicallySmallestArray(nums, limit);
        cout << "Test Case " << i + 1 << ": ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
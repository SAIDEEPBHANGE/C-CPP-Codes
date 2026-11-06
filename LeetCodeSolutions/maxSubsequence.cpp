#include <bits/stdc++.h>
using namespace std;
vector<int> maxSubsequence(vector<int>& nums, int k) {
    int n = nums.size();
    // Pair each number with its index
    vector<pair<int, int>> indexed;
    for (int i = 0; i < n; ++i) {
        indexed.push_back({nums[i], i});
    }
    // Sort by value descending to get k largest
    sort(indexed.begin(), indexed.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });
    // Take top-k elements
    vector<pair<int, int>> topK(indexed.begin(), indexed.begin() + k);
    // Sort top-k by index to maintain original order
    sort(topK.begin(), topK.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    // Extract the values
    vector<int> result;
    for (auto& p : topK) {
        result.push_back(p.first);
    }
    return result;
}
// Helper function to print vector
void printVector(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    // Define test cases as pairs of input vector and k
    vector<pair<vector<int>, int>> testCases = {
        {{3, 4, 3, 3}, 2},
        {{50, -20, 30, 10, -10, 40}, 3},
        {{1, 2, 3, 4, 5}, 3},
        {{5, 4, 3, 2, 1}, 2},
        {{-1, -2, -3, -4}, 2}
    };
    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].first;
        int k = testCases[i].second;
        vector<int> result = maxSubsequence(nums, k);
        cout << "Test Case " << i + 1 << ": ";
        printVector(result);
    }
    return 0;
}
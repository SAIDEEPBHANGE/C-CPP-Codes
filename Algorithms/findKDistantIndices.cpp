#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> Result;
        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int start = max(j - k, 0);
                int end = min(j + k, n - 1);
                if (!Result.empty() && Result.back() >= start) {
                    start = Result.bac#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // --- Method 1 ---
    vector<int> findKDistantIndices_v1(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> Result;
        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int start = max(j - k, 0);
                int end = min(j + k, n - 1);
                if (!Result.empty() && Result.back() >= start) {
                    start = Result.back() + 1;
                }
                for (int i = start; i <= end; i++) {
                    Result.push_back(i);
                }
            }
        }
        return Result;
    }
    // --- Method 2 ---
    vector<int> findKDistantIndices_v2(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> keyPos;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key)
                keyPos.push_back(i);
        }
        vector<int> result;
        if (keyPos.empty())
            return result;
        int start = max(0, keyPos[0] - k);
        int end   = min(n - 1, keyPos[0] + k);
        for (int i = 1; i < keyPos.size(); i++) {
            int newStart = max(0, keyPos[i] - k);
            int newEnd   = min(n - 1, keyPos[i] + k);
            if (newStart <= end) {
                end = max(end, newEnd);
            } else {
                for (int x = start; x <= end; x++)
                    result.push_back(x);
                start = newStart;
                end   = newEnd;
            }
        }
        for (int x = start; x <= end; x++)
            result.push_back(x);
        return result;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Vector of test cases : {nums vector, key, k}
    vector<tuple<vector<int>, int, int>> tests = {
        {{3,4,9,1,3,9,5}, 9, 1},
        {{2,2,2,2},        2, 2},
        {{1,2,3,4,5},      0, 1}
    };
    Solution sol;
    cout << "Testing Method 1:\n";
    for (auto& t : tests) {
        vector<int> nums; 
        int key, k;
        tie(nums, key, k) = t;
        vector<int> res = sol.findKDistantIndices_v1(nums, key, k);
        cout << "key=" << key << ", k=" << k << " -> ";
        for (int x : res) cout << x << " ";
        cout << "\n";
    }
    cout << "\nTesting Method 2:\n";
    for (auto& t : tests) {
        vector<int> nums; 
        int key, k;
        tie(nums, key, k) = t;
        vector<int> res = sol.findKDistantIndices_v2(nums, key, k);
        cout << "key=" << key << ", k=" << k << " -> ";
        for (int x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}k() + 1;
                }
                for (int i = start; i <= end; i++) {
                    Result.push_back(i);
                }
            }
        }
        return Result;
    }
};
// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int v : vec) cout << v << " ";
    cout << endl;
}
int main() {
    Solution sol;
    // Define test cases: {nums, key, k}
    vector<tuple<vector<int>, int, int>> testCases = {
        {{3, 4, 9, 1, 3, 9, 5}, 9, 1},
        {{2, 2, 2, 2}, 2, 2},
        {{1, 2, 3, 4, 5}, 3, 2},
        {{1, 3, 1, 3, 1}, 3, 0},
        {{1}, 1, 0},
        {{1}, 2, 0}
    };
    // Run test cases
    for (int i = 0; i < testCases.size(); ++i) {
        auto [nums, key, k] = testCases[i];
        cout << "Test Case " << i + 1 << ": nums = [";
        for (int n : nums) cout << n << " ";
        cout << "], key = " << key << ", k = " << k << "\nResult: ";
        vector<int> result = sol.findKDistantIndices(nums, key, k);
        printVector(result);
        cout << "--------------------------\n";
    }
    return 0;
}
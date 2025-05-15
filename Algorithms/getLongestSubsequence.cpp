#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> getLongestSubsequence(const vector<string>& words,
                                         const vector<int>& groups) {
        vector<string> result;
        int n = words.size();
        if (n == 0) return result;
        result.reserve(n);  // Reserve space to avoid reallocations
        result.push_back(words[0]);
        int lastGroup = groups[0];
        for (int i = 1; i < n; ++i) {
            if (groups[i] != lastGroup) {
                result.push_back(words[i]);
                lastGroup = groups[i];
            }
        }
        return result;
    }
};
void printVector(const vector<string>& vec) {
    for (const auto& word : vec) {
        cout << word << " ";
    }
    cout << endl;
}
int main() {
    Solution sol;
    // Test Case 1
    vector<string> words1 = {"a", "b", "c", "d", "e"};
    vector<int> groups1 = {1, 1, 2, 2, 3};
    printVector(sol.getLongestSubsequence(words1, groups1));  // Output: a c e
    // Test Case 2
    vector<string> words2 = {"hello", "world", "foo", "bar", "baz"};
    vector<int> groups2 = {1, 2, 2, 3, 3};
    printVector(sol.getLongestSubsequence(words2, groups2));  // Output: hello world bar
    // Test Case 3
    vector<string> words3 = {"one"};
    vector<int> groups3 = {5};
    printVector(sol.getLongestSubsequence(words3, groups3));  // Output: one
    // Test Case 4
    vector<string> words4 = {};
    vector<int> groups4 = {};
    printVector(sol.getLongestSubsequence(words4, groups4));  // Output: (empty)
    // Test Case 5
    vector<string> words5 = {"a", "b", "c", "d", "e"};
    vector<int> groups5 = {1, 2, 1, 2, 1};
    printVector(sol.getLongestSubsequence(words5, groups5));  // Output: a b c d e
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// Original function using sorting
class Solution {
public:
    bool divideArraySorting(vector<int>& ns) {
        sort(ns.begin(), ns.end());  // Sort the array (O(n log n) time complexity)
        for (int i = 0; i < ns.size(); i += 2) {
            if (ns[i] != ns[i + 1]) {
                return false;
            }
        }
        return true;
    }
    // Optimized function using frequency counting
    bool divideArrayFrequency(vector<int>& ns) {
        unordered_map<int, int> freq;
        // Count frequency of each number (O(n) time complexity)
        for (int num : ns) {
            freq[num]++;
        }
        // Check if every number appears an even number of times
        for (const auto& entry : freq) {
            if (entry.second % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution solution;
    // Test case
    vector<int> nums1 = {1, 2, 3, 4, 2, 1, 4, 3};  // Can be divided into pairs (1,1), (2,2), (3,3), (4,4)
    vector<int> nums2 = {1, 2, 3, 3, 2, 1, 4};    // Cannot be divided into pairs
    // Test the sorting-based function
    cout << "Using sorting-based method:" << endl;
    cout << (solution.divideArraySorting(nums1) ? "True" : "False") << endl; // Expected: True
    cout << (solution.divideArraySorting(nums2) ? "True" : "False") << endl; // Expected: False
    // Test the frequency-counting-based function
    cout << "\nUsing frequency-counting method:" << endl;
    cout << (solution.divideArrayFrequency(nums1) ? "True" : "False") << endl; // Expected: True
    cout << (solution.divideArrayFrequency(nums2) ? "True" : "False") << endl; // Expected: False
    return 0;
}
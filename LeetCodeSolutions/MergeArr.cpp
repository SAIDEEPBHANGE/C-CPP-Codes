#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1, vector<vector<int>>& n2) {
        // Using map to keep keys sorted and sum values
        map<int, int> m;
        // Processing the first array n1 and adding values to the map
        for (const auto& pair : n1) {
            m[pair[0]] += pair[1];  // Add the value corresponding to the key
        }
        // Processing the second array n2 and adding values to the map
        for (const auto& pair : n2) {
            m[pair[0]] += pair[1];  // Add the value corresponding to the key
        }
        // Prepare the result vector, reserving space to avoid reallocation
        vector<vector<int>> ans;
        ans.reserve(m.size());
        // Add the merged results to the answer
        for (const auto& entry : m) {
            ans.push_back({entry.first, entry.second});
        }
        return ans;
    }
};
int main() {
    // Test cases
    Solution solution;
    // First test case
    vector<vector<int>> n1 = {{1, 2}, {2, 4}, {3, 5}};
    vector<vector<int>> n2 = {{2, 3}, {3, 1}, {4, 7}};
    vector<vector<int>> result = solution.mergeArrays(n1, n2);
    // Print the result
    cout << "Merged Arrays:" << endl;
    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;
    return 0;
}
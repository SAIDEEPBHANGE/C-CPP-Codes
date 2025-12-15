#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& n) {
        sort(n.begin(), n.end());
        vector<int> ans;
        int i = 0;
        while (i < n.size() - 1) { 
            if (n[i] == n[i + 1]) {
                ans.push_back(n[i]);
                i++;
            }
            i++;
        }
        return ans;
    }
};
int main() {
    Solution sol;
    // Vector of test cases
    vector<vector<int>> testCases = {
        {1, 2, 3, 2, 4, 5, 1},     // duplicates: 1, 2
        {10, 20, 30, 10, 10, 20},  // duplicates: 10, 20
        {5, 5, 5, 5},               // duplicate: 5
        {1, 2, 3, 4, 5},            // no duplicates
        {7, 8, 8, 9, 10, 10, 10}    // duplicates: 8, 10
    };
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ": ";
        vector<int> result = sol.getSneakyNumbers(testCases[i]);
        if (result.empty()) {
            cout << "No duplicates";
        } else {
            for (int num : result)
                cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

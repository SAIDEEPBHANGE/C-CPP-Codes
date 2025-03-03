#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& n, int p) {
        vector<int> ans;
        // First, append all elements less than p
        for (int num : n) {
            if (num < p) {
                ans.push_back(num);
            }
        }
        // Then, append all elements equal to p
        for (int num : n) {
            if (num == p) {
                ans.push_back(num);
            }
        }
        // Finally, append all elements greater than p
        for (int num : n) {
            if (num > p) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    // Example test case
    vector<int> n = {3, 1, 2, 4, 5};
    int p = 3;
    vector<int> result = sol.pivotArray(n, p);
    // Output the result
    cout << "Pivoted Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
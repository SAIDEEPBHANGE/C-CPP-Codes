#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);
        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
        // Right to left pass
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }
        return accumulate(candy.begin(), candy.end(), 0);
    }
};
int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {1, 0, 2},
        {1, 2, 2},
        {1, 3, 4, 5, 2},
        {5, 3, 1},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {1, 2, 1, 2, 1}
    };
    for (int i = 0; i < testCases.size(); ++i) {
        vector<int>& ratings = testCases[i];
        cout << "Test Case " << i + 1 << ": ";
        for (int r : ratings) cout << r << " ";
        cout << "\nMinimum candies required: " << sol.candy(ratings) << "\n\n";
    }
    return 0;
}
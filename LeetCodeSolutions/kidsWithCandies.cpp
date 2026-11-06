#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> result;
        result.reserve(candies.size()); // Reserve space to avoid reallocations
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }
        return result;
    }
};
int main() {
    vector<vector<int>> testCases = {
        {2, 3, 5, 1, 3},
        {4, 2, 1, 1, 2},
        {12, 1, 12},
    };
    int extraCandies = 3;
    Solution sol;
    for (auto& candies : testCases) {
        vector<bool> result = sol.kidsWithCandies(candies, extraCandies);
        cout << "Candies: ";
        for (int c : candies) cout << c << " ";
        cout << "\nResult: ";
        for (bool val : result) cout << (val ? "true " : "false ");
        cout << "\n\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Flatten the 2D vector into a 1D vector
    vector<int> Flatten(vector<vector<int>>& g) {
        vector<int> a;
        for (auto& i : g) {
            for (int& j : i) {
                a.push_back(j);
            }
        }
        return a;
    }
public:
    // Function to calculate the minimum operations required
    int minOperations(vector<vector<int>>& g, int x) {
        vector<int> fg = Flatten(g);
        // Check if all elements can be made divisible by x
        int possibleCheck = fg[0] % x;
        for (int& i : fg) {
            if (possibleCheck != i % x) {
                return -1; // Not possible to make them divisible by x
            }
        }
        // Sort the array to find the median element
        int mid = fg.size() / 2;
        sort(fg.begin(), fg.end());
        int steps = 0;
        // Calculate the total number of steps required to make all numbers equal to the median
        for (int i = 0; i < fg.size(); i++) {
            steps += abs(fg[i] - fg[mid]) / x;
        }
        return steps;
    }
};
int main() {
    Solution solution;
    // Example input
    vector<vector<int>> g = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int x = 1;
    // Call the minOperations function
    int result = solution.minOperations(g, x);
    // Output the result
    if (result == -1) {
        cout << "It is not possible to make all elements divisible by " << x << endl;
    } else {
        cout << "The minimum number of operations required is: " << result << endl;
    }
    return 0;
}
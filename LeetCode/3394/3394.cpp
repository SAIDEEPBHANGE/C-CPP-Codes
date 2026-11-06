#include <bits/stdc++.h>
using namespace std;
class Solution {
#define lii pair<int, int>
    // Function to check if there are at least 3 valid intersections
    bool intersection(vector<lii>& c) {
        int l = 0, o = 0;
        cout << "Checking intersections..." << endl;
        for (int i = 0; i < c.size(); ++i) {
            cout << "Event: " << c[i].first << ", Type: " << (c[i].second == 1 ? "Start" : "End") << endl;
            if (c[i].second == 0) // 0 represents closing event
                o--;
            else // 1 represents opening event
                o++;
            cout << "Open count: " << o << endl;
            if (o == 0)
                l++;
        }
        cout << "Intersections found: " << l << endl;
        return l >= 3;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& r) {
        vector<lii> x, y;
        cout << "Processing rectangles..." << endl;
        // Processing each rectangle
        for (auto& rect : r) {
            cout << "Processing rectangle: [" << rect[0] << ", " << rect[1] << ", " << rect[2] << ", " << rect[3] << "]" << endl;
            // For the y-coordinate events
            y.push_back(make_pair(rect[1], 1)); // 1 for starting event (bottom)
            y.push_back(make_pair(rect[3], 0)); // 0 for ending event (top)
            // For the x-coordinate events
            x.push_back(make_pair(rect[0], 1)); // 1 for starting event (left)
            x.push_back(make_pair(rect[2], 0)); // 0 for ending event (right)
        }
        // Sorting x and y events
        cout << "Sorting events..." << endl;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        cout << "Sorted x events: ";
        for (auto& p : x) cout << "(" << p.first << ", " << (p.second == 1 ? "Start" : "End") << ") ";
        cout << endl;
        cout << "Sorted y events: ";
        for (auto& p : y) cout << "(" << p.first << ", " << (p.second == 1 ? "Start" : "End") << ") ";
        cout << endl;
        // Check for valid cuts in both x and y directions
        return intersection(y) || intersection(x);
    }
};
int main() {
    Solution sol;
    // Example 1
    int n1 = 5;
    vector<vector<int>> rectangles1 = {{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
    cout << "Result for first set of rectangles: " << sol.checkValidCuts(n1, rectangles1) << endl;
    // Example 2
    int n2 = 4;
    vector<vector<int>> rectangles2 = {{0, 0, 1, 1}, {2, 0, 3, 4}, {0, 2, 2, 3}, {3, 0, 4, 3}};
    cout << "Result for second set of rectangles: " << sol.checkValidCuts(n2, rectangles2) << endl;
    return 0;
}
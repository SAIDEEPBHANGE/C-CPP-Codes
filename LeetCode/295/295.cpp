#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Approach 1: Brute Force - Sorting
    vector<int> arr;
    // Approach 2: Optimized - Two Heaps
    priority_queue<int> topMax; 
    // Smaller half: largest element stays on top
    priority_queue<int, vector<int>, greater<int>> topMin;
    // Larger half: smallest element stays on top
public:
    // Approach 1: Add number to vector
    void addNumBrute(int num) {
        arr.push_back(num);
    }
    // Approach 1: Sort and find median
    double findMedianBrute() {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        int n = temp.size();
        if (n % 2 != 0) {
            return temp[n / 2];
        }
        return ((double)temp[n / 2 - 1] + temp[n / 2]) / 2.0;
    }
    // Approach 2: Add number using two heaps
    void addNumHeap(int num) {
        topMax.push(num);
        // Move the largest element of smaller half to larger half
        topMin.push(topMax.top());
        topMax.pop();
        // Balance both heaps
        if (topMin.size() > topMax.size()) {
            topMax.push(topMin.top());
            topMin.pop();
        }
    }
    // Approach 2: Find median in O(1)
    double findMedianHeap() {
        if (topMax.size() > topMin.size()) {
            return topMax.top();
        }
        return ((double)topMax.top() + topMin.top()) / 2.0;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {5, 2, 8, 10},
        {1, 3, 2},
        {6, 4, 9, 1, 7},
        {10, 20, 30, 40, 50}
    };
    int testCaseNumber = 1;
    for (const auto& test : testCases) {
        Solution sol;
        cout << "\nTest Case " << testCaseNumber++ << ":\n";
        cout << "Numbers: ";
        for (int num : test) {
            cout << num << " ";
        }
        cout << "\n\n";
        cout << left << setw(12) << "Inserted"
             << setw(20) << "Brute Force"
             << setw(20) << "Two Heaps" << "\n";
        cout << string(52, '-') << "\n";
        for (int num : test) {
            sol.addNumBrute(num);
            sol.addNumHeap(num);
            double bruteMedian = sol.findMedianBrute();
            double heapMedian = sol.findMedianHeap();
            cout << left << setw(12) << num
                 << setw(20) << bruteMedian
                 << setw(20) << heapMedian << "\n";
        }
        cout << string(52, '-') << "\n";
    }
    return 0;
}
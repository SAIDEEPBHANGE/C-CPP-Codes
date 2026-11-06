#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
private:
    int ak, bk, ck;
    int recursiveResult = 0;
    // Recursive helper function
    void RecursionAns(vector<int>& arr, int index, vector<int>& selected) {
        if (selected.size() == 3) {
            int i = selected[0];
            int j = selected[1];
            int k = selected[2];
            if (abs(arr[i] - arr[j]) <= ak &&
                abs(arr[j] - arr[k]) <= bk &&
                abs(arr[i] - arr[k]) <= ck) {
                recursiveResult++;
            }
            return;
        }
        int n = arr.size();
        for (int i = index; i < n; ++i) {
            selected.push_back(i);
            RecursionAns(arr, i + 1, selected);
            selected.pop_back();  // backtrack
        }
    }
public:
    // Iterative Greedy Version
    int countGoodTripletsIterative(vector<int>& arr, int a, int b, int c) {
        int result = 0;
        int n = arr.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (abs(arr[i] - arr[j]) > a)
                    continue;
                for (int k = j + 1; k < n; k++) {
                    if (abs(arr[j] - arr[k]) > b)
                        continue;
                    if (abs(arr[i] - arr[k]) > c)
                        continue;
                    result++;
                }
            }
        }
        return result;
    }
    // Recursive Version
    int countGoodTripletsRecursive(vector<int>& arr, int a, int b, int c) {
        ak = a;
        bk = b;
        ck = c;
        recursiveResult = 0;
        vector<int> selected;
        RecursionAns(arr, 0, selected);
        return recursiveResult;
    }
};
// ------------------- Main Function with Test Cases -------------------
int main() {
    Solution solution;
    vector<vector<int>> testArrays = {
        {3, 0, 1, 1, 9, 7},
        {1, 1, 2, 2, 3},
        {1, 2, 3, 4, 5},
        {1, 2, 3}
    };
    vector<tuple<int, int, int>> testParams = {
        {7, 2, 3},
        {0, 0, 1},
        {3, 3, 3},
        {10, 10, 10}
    };
    for (int i = 0; i < testArrays.size(); ++i) {
        auto arr = testArrays[i];
        auto [a, b, c] = testParams[i];
        cout << "Test case " << i + 1 << ":\n";
        cout << "Iterative result: " << solution.countGoodTripletsIterative(arr, a, b, c) << endl;
        cout << "Recursive result: " << solution.countGoodTripletsRecursive(arr, a, b, c) << endl;
        cout << "----------------------------------\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
    ------------------------------------------------------------
    Approach 1: Using __builtin_popcount with custom comparator
    Time Complexity: O(n log n)
    ------------------------------------------------------------
    */
    vector<int> sortByBits_Builtin(vector<int> arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            if (countA == countB)
                return a < b;
            return countA < countB;
        });
        return arr;
    }
    /*
    ------------------------------------------------------------
    Approach 2: Manual bit counting function
    Time Complexity: O(n log n)
    ------------------------------------------------------------
    */
    int countBits(int x) {
        int count = 0;
        while (x) {
            count += (x & 1);
            x >>= 1;
        }
        return count;
    }
    vector<int> sortByBits_Manual(vector<int> arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int countA = countBits(a);
            int countB = countBits(b);
            if (countA == countB)
                return a < b;
            return countA < countB;
        });
        return arr;
    }
    /*
    ------------------------------------------------------------
    Approach 3: Precompute bit counts (Optimization)
    Time Complexity: O(n log n)
    ------------------------------------------------------------
    */
    vector<int> sortByBits_Precompute(vector<int> arr) {
        unordered_map<int, int> bitCount;
        for (int num : arr)
            bitCount[num] = __builtin_popcount(num);
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (bitCount[a] == bitCount[b])
                return a < b;
            return bitCount[a] < bitCount[b];
        });
        return arr;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {0,1,2,3,4,5,6,7,8},
        {1024,512,256,128,64,32,16,8,4,2,1},
        {10,100,1000,10000},
        {5,3,7,10,14}
    };
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Original: ";
        for (int num : testCases[i]) cout << num << " ";
        cout << "\n";
        vector<int> res1 = sol.sortByBits_Builtin(testCases[i]);
        vector<int> res2 = sol.sortByBits_Manual(testCases[i]);
        vector<int> res3 = sol.sortByBits_Precompute(testCases[i]);
        cout << "Approach 1 (Builtin):   ";
        for (int num : res1) cout << num << " ";
        cout << "\n";
        cout << "Approach 2 (Manual):    ";
        for (int num : res2) cout << num << " ";
        cout << "\n";
        cout << "Approach 3 (Precompute):";
        for (int num : res3) cout << num << " ";
        cout << "\n";
        cout << "----------------------------------------\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Binary Search (Manual)
    char nextGreatestLetter_BinarySearch(vector<char>& letters, char target) {
        int left = 0, right = (int)letters.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return letters[left % letters.size()];
    }

    // Approach 2: Linear Scan
    char nextGreatestLetter_Linear(vector<char>& letters, char target) {
        for (char c : letters) {
            if (c > target) return c;
        }
        // Wrap around case
        return letters[0];
    }

    // Approach 3: Using STL upper_bound
    char nextGreatestLetter_STL(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        if (it == letters.end()) return letters[0];
        return *it;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<vector<char>> testLetters = {
        {'c', 'f', 'j'},
        {'a', 'b', 'c'},
        {'x', 'x', 'y', 'y'},
        {'a'}
    };
    vector<char> testTargets = {'a', 'c', 'z', 'a'};

    for (size_t i = 0; i < testLetters.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Letters: ";
        for (char c : testLetters[i]) cout << c << " ";
        cout << "\nTarget: " << testTargets[i] << "\n";

        cout << "Binary Search Approach: "
             << sol.nextGreatestLetter_BinarySearch(testLetters[i], testTargets[i]) << "\n";

        cout << "Linear Scan Approach: "
             << sol.nextGreatestLetter_Linear(testLetters[i], testTargets[i]) << "\n";

        cout << "STL upper_bound Approach: "
             << sol.nextGreatestLetter_STL(testLetters[i], testTargets[i]) << "\n";

        cout << "-----------------------------\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]);
        for (int i = 1; i < words.size(); ++i) {
            string prev = result.back();
            string current = words[i];
            sort(prev.begin(), prev.end());
            sort(current.begin(), current.end());
            if (prev == current) {
                continue;
            } else {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};

// Helper function to print a vector of strings
void printVector(const vector<string>& vec) {
    for (const string& word : vec) {
        cout << word << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test Case 1
    vector<string> test1 = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> result1 = solution.removeAnagrams(test1);
    cout << "Test Case 1: ";
    printVector(result1);  // Expected: ["abba", "cd"]

    // Test Case 2
    vector<string> test2 = {"a", "b", "c", "d", "e"};
    vector<string> result2 = solution.removeAnagrams(test2);
    cout << "Test Case 2: ";
    printVector(result2);  // Expected: ["a", "b", "c", "d", "e"]

    // Test Case 3
    vector<string> test3 = {"listen", "silent", "enlist", "google", "gooogle", "elgoog"};
    vector<string> result3 = solution.removeAnagrams(test3);
    cout << "Test Case 3: ";
    printVector(result3);  // Expected: ["listen", "google", "gooogle"]

    // Test Case 4
    vector<string> test4 = {"abc", "acb", "bac", "xyz", "yxz", "zxy", "mnop"};
    vector<string> result4 = solution.removeAnagrams(test4);
    cout << "Test Case 4: ";
    printVector(result4);  // Expected: ["abc", "xyz", "mnop"]

    return 0;
}

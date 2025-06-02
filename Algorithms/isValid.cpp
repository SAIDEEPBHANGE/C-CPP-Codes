#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Original version (translated from Java)
    bool isValidOriginal(string str) {
        stack<char> stack;
        for (char c : str) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' && !stack.empty() && stack.top() == '(') {
                stack.pop();
            } else if (c == '}' && !stack.empty() && stack.top() == '{') {
                stack.pop();
            } else if (c == ']' && !stack.empty() && stack.top() == '[') {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
    // Optimized version using a map
    bool isValidOptimized(string str) {
        stack<char> stack;
        unordered_map<char, char> matching = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (char c : str) {
            if (matching.count(c)) {
                if (stack.empty() || stack.top() != matching[c]) return false;
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
    // Test both implementations
    void run_test_cases() {
        vector<string> testCases = {
            "()",
            "()[]{}",
            "(]",
            "([)]",
            "{[]}",
            "",
            "(",
            "((()))",
            "{[()]}",
            "({[)]}"
        };
        for (int i = 0; i < testCases.size(); ++i) {
            string input = testCases[i];
            bool result1 = isValidOriginal(input);
            bool result2 = isValidOptimized(input);
            cout << "Test Case #" << i + 1 << ": \"" << input << "\"\n";
            cout << "Original Output: " << (result1 ? "true" : "false") << "\n";
            cout << "Optimized Output: " << (result2 ? "true" : "false") << "\n";
            cout << "Match: " << (result1 == result2 ? "Yes" : "No") << "\n\n";
        }
    }
};
int main() {
    Solution s;
    s.run_test_cases();
    return 0;
}
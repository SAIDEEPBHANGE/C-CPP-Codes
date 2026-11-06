#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        // Lambda to calculate digit sum
        auto digitSum = [](string::iterator begin, string::iterator end) {
            return accumulate(begin, end, 0, [](int sum, char ch) {
                return sum + (ch - '0');
            });
        };
        for (int i = low; i <= high; i++) {
            string NoStr = to_string(i);
            if (NoStr.size() % 2 == 0 &&
                digitSum(NoStr.begin(), NoStr.begin() + NoStr.size() / 2) ==
                digitSum(NoStr.begin() + NoStr.size() / 2, NoStr.end())) {
                cnt++;
            }
        }
        return cnt;
    }
};
int main() {
    int low, high;
    cout << "Enter the lower bound: ";
    cin >> low;
    cout << "Enter the upper bound: ";
    cin >> high;
    Solution solution;
    int result = solution.countSymmetricIntegers(low, high);
    cout << "Number of symmetric integers between " << low << " and " << high << " is: " << result << endl;
    return 0;
}
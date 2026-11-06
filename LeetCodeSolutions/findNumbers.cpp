#include <bits/stdc++.h>
using namespace std;
// First approach: Counting digits using division
class SolutionDigitCount {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (int i : nums) {
            int NumberofDigit = 1;
            while (i / 10 > 0) {
                i /= 10;
                NumberofDigit++;
            }
            if (!(NumberofDigit % 2))
                result++;
        }
        return result;
    }
};
// Second approach: Converting to string
class SolutionStringCount {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (int i : nums) {
            string StringI = to_string(i);
            if (!(StringI.size() % 2))
                result++;
        }
        return result;
    }
};
int main() {
    // Define test cases
    vector<vector<int>> test_cases = {
        {12, 345, 2, 6, 7896},
        {555, 901, 482, 1771},
        {1, 22, 333, 4444, 55555}
    };
    SolutionDigitCount solDigit;
    SolutionStringCount solString;
    // Run both solutions
    for (size_t i = 0; i < test_cases.size(); ++i) {
        cout << "Test case " << i + 1 << ": ";
        for (int num : test_cases[i]) cout << num << " ";
        cout << "\nUsing digit count: " << solDigit.findNumbers(test_cases[i]) << endl;
        cout << "Using string conversion: " << solString.findNumbers(test_cases[i]) << endl;
        cout << "------------------------\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
class Solution {
public:
    char kthCharacter(int k) {
        string Result = "a";
        while (Result.size() <= k) {
            string Temp = "";
            for (char i : Result) {
                Temp += (char)((i + 1) % 122);
            }
            Result += Temp;
        }
        return Result[k - 1];
    }
};
int main() {
    Solution solution;
    vector<int> testCases = {1, 5, 10, 50, 100};
    for (int k : testCases) {
        cout << "k = " << k << " -> " << "k-th character: " << solution.kthCharacter(k) << endl;
    }
    bitset<8> bits(15);
    cout << "Bitset of 15: " << bits << endl;
    return 0;
}
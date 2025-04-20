#include <bits/stdc++.h>
using namespace std;
// Solution class that contains the numRabbits method
class Solution {
public:
    /*
     * This function calculates the minimum number of rabbits in the forest 
     * based on their answers.
     * Each rabbit reports how many other rabbits have the same color as itself.
     */
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> AnswerFreq;
        // Count the frequency of each answer
        for (int& i : answers) {
            AnswerFreq[i]++;
        }
        int Result = 0;
        // Process each unique answer
        for (auto& it : AnswerFreq) {
            int Answer = it.first;        // The number each rabbit says
            int Freq = it.second;         // Number of times this answer appears
            int ColorGroupSize = Answer + 1; // Group size of same-colored rabbits
            // Calculate number of groups needed
            int GroupsCount = ceil((double)Freq / ColorGroupSize);
            // Total rabbits for this group
            Result += GroupsCount * ColorGroupSize;
        }
        return Result;
    }
};
// Main function to run all test cases
int main() {
    Solution solution;
    // Vector of test cases
    vector<vector<int>> testCases = {
        {1, 1, 2},            // Expected output: 5
        {10, 10, 10},         // Expected output: 11
        {},                   // Expected output: 0
        {0, 0, 1, 1, 1}       // Expected output: 6
    };
    // Run and display each test case
    for (int i = 0; i < testCases.size(); ++i) {
        int result = solution.numRabbits(testCases[i]);
        cout << "Test Case " << i + 1 << ": Output = " << result << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class SolutionSort {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int Result = 1;
        int MinVal = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] - MinVal > k) {
                MinVal = nums[i];
                Result++;
            }
        }
        return Result;
    }
};
class SolutionCounting {
public:
    int partitionArray(vector<int>& nums, int k) {
        const int MAX = 100001;
        vector<int> freq(MAX, 0);
        for (int num : nums) {
            ++freq[num];
        }
        int count = 0;
        for (int i = 0; i < MAX;) {
            if (freq[i] == 0) {
                ++i;
                continue;
            }
            ++count;
            int j = i;
            while (j < MAX && j - i <= k) {
                freq[j] = 0;
                ++j;
            }
            i = j;
        }
        return count;
    }
};
void runTestCases() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 4, 5},
        {1, 5, 9, 13},
        {3, 6, 9, 12},
        {1, 2, 2, 2, 2, 3},
        {100, 200, 300},
        {5},
        {}
    };
    int k = 2;
    SolutionSort solSort;
    SolutionCounting solCount;
    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> test = testCases[i];
        cout << "Test case " << i + 1 << ": ";
        for (int num : test) cout << num << " ";
        cout << "\n";
        int resSort = solSort.partitionArray(test, k);
        int resCount = solCount.partitionArray(test, k);
        cout << "Sort-based result: " << resSort << "\n";
        cout << "Counting-sort result: " << resCount << "\n";
        cout << "----------------------\n";
    }
}
int main() {
    runTestCases();
    return 0;
}
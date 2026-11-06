#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 1. Bubble Sort (Inefficient)
    void sortColorsBubble(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
    // 2. Counting Sort (Efficient for known range)
    void sortColorsCounting(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int i : nums) {
            if (i == 0) cnt0++;
            else if (i == 1) cnt1++;
            else cnt2++;
        }
        int i = 0;
        while (cnt0--) nums[i++] = 0;
        while (cnt1--) nums[i++] = 1;
        while (cnt2--) nums[i++] = 2;
    }
    // 3. Dutch National Flag (Slightly modified version)
    void sortColorsDutchFlag1(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (nums[mid] != 1) {
                if (nums[mid] == 0) {
                    swap(nums[low], nums[mid]);
                    low++;
                } else if (nums[mid] == 2) {
                    swap(nums[mid], nums[high]);
                    high--;
                    mid--; // recheck swapped-in value
                }
            }
            mid++;
        }
    }
    // 4. Dutch National Flag (Cleanest version)
    void sortColorsDutchFlag2(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};
void printVector(const vector<int>& v) {
    for (int num : v) cout << num << ' ';
    cout << '\n';
}
int main() {
    vector<vector<int>> testcases = {
        {2, 0, 2, 1, 1, 0},
        {2, 0, 1},
        {0},
        {1},
        {2, 2, 2, 1, 1, 0, 0},
        {},
        {1, 0, 1, 2, 1, 0}
    };
    Solution sol;
    cout << "Using Bubble Sort:\n";
    for (auto test : testcases) {
        sol.sortColorsBubble(test);
        printVector(test);
    }
    cout << "\nUsing Counting Sort:\n";
    for (auto test : testcases) {
        sol.sortColorsCounting(test);
        printVector(test);
    }
    cout << "\nUsing Dutch National Flag 1:\n";
    for (auto test : testcases) {
        sol.sortColorsDutchFlag1(test);
        printVector(test);
    }
    cout << "\nUsing Dutch National Flag 2:\n";
    for (auto test : testcases) {
        sol.sortColorsDutchFlag2(test);
        printVector(test);
    }
    return 0;
}
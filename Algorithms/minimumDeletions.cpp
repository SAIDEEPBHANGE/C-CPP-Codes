#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    // -------- Version 1: Naive Double Loop --------
    int minDel_V1(const string& word, int k) {
        unordered_map<char, int> freq;
        for (char i : word) freq[i]++;
        vector<int> listFreq;
        for (auto i : freq) listFreq.push_back(i.second);
        sort(listFreq.begin(), listFreq.end());
        int minDelete = INT_MAX, n = listFreq.size();
        for (int i = 0; i < n; i++) {
            int base = listFreq[i], TotalDeletion = 0;
            for (int j = 0; j < i; j++) TotalDeletion += listFreq[j];
            for (int j = i; j < n; j++)
                if (listFreq[j] > base + k)
                    TotalDeletion += listFreq[j] - (base + k);
            minDelete = min(minDelete, TotalDeletion);
        }
        return minDelete;
    }
    // -------- Version 2: Prefix Sum Optimization --------
    int minDel_V2(const string& word, int k) {
        unordered_map<char, int> freq;
        for (char c : word) freq[c]++;
        vector<int> listFreq;
        for (auto& entry : freq) listFreq.push_back(entry.second);
        sort(listFreq.begin(), listFreq.end());
        int n = listFreq.size(), minDelete = INT_MAX;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + listFreq[i];
        for (int i = 0; i < n; ++i) {
            int base = listFreq[i], TotalDeletion = prefix[i];
            for (int j = i; j < n; ++j)
                if (listFreq[j] > base + k)
                    TotalDeletion += listFreq[j] - (base + k);
            minDelete = min(minDelete, TotalDeletion);
        }
        return minDelete;
    }
    // -------- Version 3: Binary Search + Prefix Sum --------
    int minDel_V3(const string& word, int k) {
        unordered_map<char, int> freq;
        for (char c : word) freq[c]++;
        vector<int> listFreq;
        for (auto& entry : freq) listFreq.push_back(entry.second);
        sort(listFreq.begin(), listFreq.end());
        int n = listFreq.size(), minDelete = INT_MAX;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + listFreq[i];
        for (int i = 0; i < n; ++i) {
            int base = listFreq[i], TotalDeletion = prefix[i];
            int upper = upper_bound(listFreq.begin(), listFreq.end(), base + k) - listFreq.begin();
            if (upper < n) {
                int extraDeletion = prefix[n] - prefix[upper] - (n - upper) * (base + k);
                TotalDeletion += extraDeletion;
            }
            minDelete = min(minDelete, TotalDeletion);
        }
        return minDelete;
    }
    // -------- Version 4: Brute Base Selection (Using 26 Letters) --------
    int minDel_V4(const string& word, int k) {
        int freq[26] = {0};
        for (char c : word) freq[c - 'a']++;
        vector<int> freqs;
        for (int f : freq)
            if (f > 0) freqs.push_back(f);
        int minDelete = INT_MAX;
        for (int base : freqs) {
            int deleteCount = 0;
            for (int f : freqs) {
                if (f > base + k) deleteCount += f - (base + k);
                else if (f < base) deleteCount += f;
            }
            minDelete = min(minDelete, deleteCount);
        }
        return minDelete;
    }
    // -------- Version 5: Fastest Greedy (Optimal Practical) --------
    int minDel_V5(const string& word, int k) {
        vector<int> freq(26, 0);
        for (char c : word) freq[c - 'a']++;
        sort(freq.begin(), freq.end());
        int deleted = 0, ans = word.size();
        for (int i = 0; i < 26; ++i) {
            int res = deleted, minFreq = freq[i];
            for (int j = 25; j > i; --j) {
                if (freq[j] - minFreq <= k) break;
                res += freq[j] - minFreq - k;
            }
            ans = min(ans, res);
            deleted += freq[i];
        }
        return ans;
    }
    // -------- Dispatcher to Select Version --------
    int minimumDeletions(string word, int k, int version = 5) {
        switch (version) {
            case 1: return minDel_V1(word, k);
            case 2: return minDel_V2(word, k);
            case 3: return minDel_V3(word, k);
            case 4: return minDel_V4(word, k);
            case 5: default: return minDel_V5(word, k);
        }
    }
};
// -------- Test Runner --------
int main() {
    vector<pair<string, int>> testCases = {
        {"aabbcc", 1},
        {"aabbcc", 0},
        {"abcde", 2},
        {"aaaaaaaabbbbcccdde", 1},
        {"xyzxyzxyzxyz", 2},
        {"zzzzzz", 0},
        {"ababababababab", 1}
    };
    Solution sol;
    for (int i = 0; i < testCases.size(); ++i) {
        string word = testCases[i].first;
        int k = testCases[i].second;
        cout << "Test Case " << i + 1 << ": \"" << word << "\", k = " << k << endl;
        for (int v = 1; v <= 5; ++v) {
            cout << "  Version " << v << ": " << sol.minimumDeletions(word, k, v) << endl;
        }
        cout << "--------------------------------------------------\n";
    }
    return 0;
}
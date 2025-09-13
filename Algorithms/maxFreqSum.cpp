#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Approach 1
    int approach1(string s) {
        vector<int> Vowels(26, 0);
        vector<int> Consonents(26, 0);
        string VowelSTR = "aeiou";
        for (char i : s) {
            if (VowelSTR.find(i) != string::npos) {
                Vowels[i % 26]++;
            } else {
                Consonents[i % 26]++;
            }
        }
        sort(Vowels.begin(), Vowels.end());
        sort(Consonents.begin(), Consonents.end());
        return Vowels[25] + Consonents[25];
    }

    // Approach 2
    int approach2(string s) {
        vector<int> letters(26, 0);
        vector<int> VowelsPosition = {1, 5, 9, 15, 21}; // 1-based positions: b, f, j, p, v?
        int maxFreqVow = 0, maxFreqCons = 0;
        for (char i : s) {
            letters[i - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (find(VowelsPosition.begin(), VowelsPosition.end(), i + 1) != VowelsPosition.end()) {
                maxFreqVow = max(maxFreqVow, letters[i]);
            } else {
                maxFreqCons = max(maxFreqCons, letters[i]);
            }
        }
        return maxFreqVow + maxFreqCons;
    }

    // Approach 3
    bool isVowel(int i) {
        return i == 0 || i == 4 || i == 8 || i == 14 || i == 20; // a, e, i, o, u
    }

    int approach3(string s) {
        vector<int> letters(26, 0);
        int maxFreqVow = 0, maxFreqCons = 0;
        for (char i : s) {
            letters[i - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (isVowel(i)) {
                maxFreqVow = max(maxFreqVow, letters[i]);
            } else {
                maxFreqCons = max(maxFreqCons, letters[i]);
            }
        }
        return maxFreqVow + maxFreqCons;
    }

    // Approach 4
    int approach4(string s) {
        vector<int> freq(26, 0);
        int maxVowelFreq = 0, maxConsFreq = 0;
        for (char ch : s) {
            int idx = ch - 'a';
            freq[idx]++;
            if (idx == 0 || idx == 4 || idx == 8 || idx == 14 || idx == 20) {
                maxVowelFreq = max(maxVowelFreq, freq[idx]);
            } else {
                maxConsFreq = max(maxConsFreq, freq[idx]);
            }
        }
        return maxVowelFreq + maxConsFreq;
    }

public:
    void testCases() {
        vector<string> testCases = {
            "abcdeeeiouu",     // contains all vowels
            "zzzqqqbbb",       // only consonants
            "aabbccddeeff",    // mixed with duplicates
            "aeiouaeiou",      // only vowels repeated
            "bcdfghjklmnpqrstvwxyz", // only consonants once
            "a",               // single vowel
            "b",               // single consonant
            ""                 // empty string
        };

        for (string s : testCases) {
            cout << "Input: \"" << s << "\"\n";
            cout << "Approach 1 Result: " << approach1(s) << endl;
            cout << "Approach 2 Result: " << approach2(s) << endl;
            cout << "Approach 3 Result: " << approach3(s) << endl;
            cout << "Approach 4 Result: " << approach4(s) << endl;
            cout << "-----------------------------------\n";
        }
    }
};

int main() {
    Solution sol;
    sol.testCases();
    return 0;
}

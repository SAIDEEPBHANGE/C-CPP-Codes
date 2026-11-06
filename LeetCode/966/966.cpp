#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
private:
    string toLower(const string& word) {
        string res;
        for (char ch : word) {
            res += tolower(ch);
        }
        return res;
    }
    string devowel(const string& word) {
        string res;
        for (char ch : word) {
            if (isVowel(ch)) {
                res += '*';
            } else {
                res += ch;
            }
        }
        return res;
    }
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exactWords;
        unordered_map<string, string> caseInsensitiveMap;
        unordered_map<string, string> vowelErrorMap;
        for (const string& word : wordlist) {
            exactWords.insert(word);
            string lower = toLower(word);
            if (caseInsensitiveMap.find(lower) == caseInsensitiveMap.end()) {
                caseInsensitiveMap[lower] = word;
            }
            string devowelWord = devowel(lower);
            if (vowelErrorMap.find(devowelWord) == vowelErrorMap.end()) {
                vowelErrorMap[devowelWord] = word;
            }
        }
        vector<string> result;
        for (const string& query : queries) {
            if (exactWords.find(query) != exactWords.end()) {
                result.push_back(query);
            } else {
                string lowerQuery = toLower(query);
                if (caseInsensitiveMap.find(lowerQuery) !=
                    caseInsensitiveMap.end()) {
                    result.push_back(caseInsensitiveMap[lowerQuery]);
                } else {
                    string devowelQuery = devowel(lowerQuery);
                    if (vowelErrorMap.find(devowelQuery) !=
                        vowelErrorMap.end()) {
                        result.push_back(vowelErrorMap[devowelQuery]);
                    } else {
                        result.push_back("");
                    }
                }
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    // Test Case 1
    vector<string> wordlist1 = {"KiTe", "kite", "hare", "Hare"};
    vector<string> queries1 = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
    vector<string> result1 = sol.spellchecker(wordlist1, queries1);
    cout << "Test Case 1 Results:\n";
    for (const string& word : result1) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;
    // Test Case 2
    vector<string> wordlist2 = {"yellow", "Red", "BLUE"};
    vector<string> queries2 = {"YELLOW", "red", "blue", "Green", "r*d"};
    vector<string> result2 = sol.spellchecker(wordlist2, queries2);
    cout << "Test Case 2 Results:\n";
    for (const string& word : result2) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;
    return 0;
}

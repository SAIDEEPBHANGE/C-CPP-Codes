#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    // Iterative version (your original implementation)
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    // Recursive version
    ListNode* reverseListRecursive(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    // Helper: Convert vector to linked list
    ListNode* vectorToList(const vector<int>& vals) {
        ListNode dummy;
        ListNode* tail = &dummy;
        for (int val : vals) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        return dummy.next;
    }
    // Helper: Convert linked list to vector
    vector<int> listToVector(ListNode* head) {
        vector<int> vals;
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
        return vals;
    }
    // Test both implementations
    void linked_list_test_cases() {
        vector<vector<int>> testCases = {
            {},
            {1},
            {1, 2},
            {1, 2, 3, 4, 5},
            {10, 20, 30}
        };
        for (int i = 0; i < testCases.size(); ++i) {
            cout << "Test Case #" << i + 1 << ":\n";
            ListNode* inputList = vectorToList(testCases[i]);
            ListNode* reversedIter = reverseListIterative(vectorToList(testCases[i]));
            ListNode* reversedRec = reverseListRecursive(vectorToList(testCases[i]));
            vector<int> iterResult = listToVector(reversedIter);
            vector<int> recResult = listToVector(reversedRec);
            cout << "Original: ";
            for (int val : testCases[i]) cout << val << " ";
            cout << "\n";
            cout << "Iterative Reversed: ";
            for (int val : iterResult) cout << val << " ";
            cout << "\n";
            cout << "Recursive Reversed: ";
            for (int val : recResult) cout << val << " ";
            cout << "\n";
            cout << "Match: " << (iterResult == recResult ? "Yes" : "No") << "\n\n";
        }
    }
};
int main() {
    Solution s;
    s.linked_list_test_cases();
    return 0;
}
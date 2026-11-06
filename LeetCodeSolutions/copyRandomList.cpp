#include <bits/stdc++.h>
using namespace std;

/*
Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    /*
        Approach 1: Hash Map
        Time Complexity : O(n)
        Space Complexity: O(n)
    */
    Node* copyRandomListHashMap(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;
        Node* newHead = nullptr;
        Node* prev = nullptr;

        // Create copied nodes and next pointers
        while (curr) {
            Node* temp = new Node(curr->val);
            mp[curr] = temp;

            if (!newHead) {
                newHead = temp;
                prev = temp;
            } else {
                prev->next = temp;
                prev = temp;
            }

            curr = curr->next;
        }

        // Assign random pointers
        curr = head;
        Node* copyCurr = newHead;

        while (curr) {
            copyCurr->random = (curr->random ? mp[curr->random] : nullptr);
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return newHead;
    }

    /*
        Approach 2: Interleaving Nodes (Optimal)
        Time Complexity : O(n)
        Space Complexity: O(1)
    */
    Node* copyRandomListOptimal(Node* head) {
        if (head == nullptr) return nullptr;

        Node* curr = head;

        // Step 1: Insert copied nodes between original nodes
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Set random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Separate original and copied lists
        curr = head;
        Node* copyHead = head->next;

        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            curr = curr->next;
        }

        return copyHead;
    }
};

//------------------------------------------------------------
// Utility Functions
//------------------------------------------------------------

// Build linked list from values and random indices.
// randomIndex[i] = index of random node, -1 means nullptr.
Node* buildList(const vector<int>& values, const vector<int>& randomIndex) {
    if (values.empty()) return nullptr;

    vector<Node*> nodes;

    for (int val : values)
        nodes.push_back(new Node(val));

    for (int i = 0; i < (int)values.size() - 1; i++)
        nodes[i]->next = nodes[i + 1];

    for (int i = 0; i < (int)values.size(); i++) {
        if (randomIndex[i] != -1)
            nodes[i]->random = nodes[randomIndex[i]];
    }

    return nodes[0];
}

// Print list as (Value, RandomValue)
void printList(Node* head) {
    while (head) {
        cout << "(" << head->val << ", ";
        if (head->random)
            cout << head->random->val;
        else
            cout << "NULL";
        cout << ") ";

        head = head->next;
    }
    cout << "\n";
}

// Free memory
void deleteList(Node* head) {
    while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
}

//------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<pair<vector<int>, vector<int>>> testCases = {
        {{7, 13, 11, 10, 1}, {-1, 0, 4, 2, 0}},
        {{1, 2}, {1, 1}},
        {{3, 3, 3}, {-1, 0, -1}},
        {{1}, {-1}},
        {{}, {}}
    };

    for (int tc = 0; tc < (int)testCases.size(); tc++) {
        cout << "==============================\n";
        cout << "Test Case " << tc + 1 << "\n";

        Node* original1 = buildList(testCases[tc].first, testCases[tc].second);
        Node* original2 = buildList(testCases[tc].first, testCases[tc].second);

        cout << "Original List:\n";
        printList(original1);

        cout << "\nApproach 1 (Hash Map):\n";
        Node* copy1 = sol.copyRandomListHashMap(original1);
        printList(copy1);

        cout << "\nApproach 2 (Optimal O(1) Space):\n";
        Node* copy2 = sol.copyRandomListOptimal(original2);
        printList(copy2);

        deleteList(original1);
        deleteList(original2);
        deleteList(copy1);
        deleteList(copy2);

        cout << "\n";
    }

    return 0;
}
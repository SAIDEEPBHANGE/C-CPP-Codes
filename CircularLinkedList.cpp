#include <iostream>
using namespace std;
// Node structure for a singly circular linked list
struct Node {
    int data;      // Data of the node
    Node* next;    // Pointer to the next node
    Node(int val) : data(val), next(nullptr) {}  // Constructor to initialize node
};
// CircularLinkedList class
class CircularLinkedList {
private:
    Node* head;    // Pointer to the head of the list
public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}
    // Destructor to free up memory
    ~CircularLinkedList() {
        if (head == nullptr) return; // If list is empty, nothing to delete
        Node* temp = head;
        do {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
    }
    // Function to insert a new node at the end of the list
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;  // Point the new node to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;  // Set last node's next to the new node
            newNode->next = head;  // Point new node back to the head
        }
    }
    // Function to insert a new node at the beginning
    void prepend(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;  // Point the new node to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;  // Last node's next should now point to new node
            newNode->next = head;  // New node points to the head
            head = newNode;        // Update the head to point to the new node
        }
    }
    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) return; // List is empty, nothing to delete
        Node* temp = head;
        Node* prev = nullptr;
        // If the node to be deleted is the head
        if (head->data == value) {
            if (head->next == head) {  // Only one node in the list
                delete head;
                head = nullptr;
                return;
            }
            // Find the last node to update its next pointer
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;  // Last node points to the second node
            delete head;              // Delete the head
            head = temp->next;        // Update head to the second node
            return;
        }
        // Traverse to find the node to delete
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != value);
        if (temp == head) {
            cout << "Value not found!" << endl;
            return;
        }
        prev->next = temp->next;  // Bypass the node to delete
        delete temp;
    }
    // Function to display the list (starting from the head)
    void display() const {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);  // Traverse until we reach the head again
        cout << "(head)" << endl;  // Indicating it's circular
    }
};
int main() {
    CircularLinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    cout << "List after appending:" << endl;
    list.display();
    list.prepend(5);
    cout << "List after prepending:" << endl;
    list.display();
    list.deleteNode(20);
    cout << "List after deleting node with value 20:" << endl;
    list.display();
    list.deleteNode(100);  // Value not in list
    cout << "List after trying to delete a non-existing node:" << endl;
    list.display();
    return 0;
}
#include <iostream>
using namespace std;
// Node structure for a doubly linked list
struct Node {
    int data;      // Data of the node
    Node* next;    // Pointer to the next node
    Node* prev;    // Pointer to the previous node
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}  // Constructor to initialize node
};
// DoublyLinkedList class
class DoublyLinkedList {
private:
    Node* head;    // Pointer to the head of the list
public:
    // Constructor
    DoublyLinkedList() : head(nullptr) {}
    // Destructor to free up memory
    ~DoublyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Function to insert a new node at the end of the list
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode; // If list is empty, make newNode the head
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;  // Insert at the end
            newNode->prev = temp;  // Set the prev pointer of the new node
        }
    }
    // Function to insert a new node at the beginning
    void prepend(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;  // If the list is empty, make the new node the head
        } else {
            newNode->next = head;  // Set the new node's next to current head
            head->prev = newNode;  // Set the current head's prev to new node
            head = newNode;        // Move head to the new node
        }
    }
    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) return;  // List is empty, nothing to delete
        Node* temp = head;
        // Search for the node with the given value
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Value not found!" << endl;
            return;
        }
        // If the node to delete is the head
        if (temp == head) {
            head = temp->next;
            if (head != nullptr) head->prev = nullptr;
        } else {
            temp->prev->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
        }
        delete temp;  // Free memory
    }
    // Function to display the list from the head to the end
    void display() const {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    // Function to display the list from the tail to the beginning
    void displayReverse() const {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        // Go to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Traverse backwards
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    DoublyLinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    cout << "List after appending:" << endl;
    list.display();
    list.prepend(5);
    cout << "List after prepending:" << endl;
    list.display();
    cout << "List in reverse order:" << endl;
    list.displayReverse();
    list.deleteNode(20);
    cout << "List after deleting node with value 20:" << endl;
    list.display();
    list.deleteNode(100);  // Value not in list
    cout << "List after trying to delete a non-existing node:" << endl;
    list.display();
    return 0;
}
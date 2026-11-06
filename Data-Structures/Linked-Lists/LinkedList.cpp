#include <iostream>
using namespace std;
// Node structure
struct Node {
    int data;      // Data part
    Node* next;    // Pointer to the next node
    Node(int val) : data(val), next(nullptr) {}  // Constructor to initialize node
};
// SinglyLinkedList class
class SinglyLinkedList {
private:
    Node* head;    // Pointer to the head of the list
public:
    // Constructor
    SinglyLinkedList() : head(nullptr) {}
    // Destructor to free up memory
    ~SinglyLinkedList() {
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
            temp->next = newNode; // Insert newNode at the end
        }
    }
    // Function to insert a new node at the beginning
    void prepend(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode; // Make newNode the new head
    }
    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) return; // List is empty, nothing to delete
        // If the node to delete is the head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Value not found!" << endl;
            return;
        }
        // Node to be deleted is temp->next
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    // Function to display the list
    void display() const {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    SinglyLinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.prepend(5);
    cout << "List after appending and prepending:" << endl;
    list.display();
    list.deleteNode(20);
    cout << "List after deleting node with value 20:" << endl;
    list.display();
    list.deleteNode(100);  // Value not in list
    cout << "List after trying to delete a non-existing node:" << endl;
    list.display();
    return 0;
}
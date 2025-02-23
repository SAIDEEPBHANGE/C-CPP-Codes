#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class QueueUsingLinkedList {
    Node* front;
    Node* rear;
public:
    QueueUsingLinkedList() {
        front = rear = nullptr;
    }
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        displayQueue();
    }
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            cout << "Dequeued: " << temp->data << endl;
            delete temp;
            displayQueue();
        }
    }
    bool isEmpty() {
        return front == nullptr;
    }
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    void displayQueue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~QueueUsingLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
// Example usage:
int main() {
    QueueUsingLinkedList q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    return 0;
}
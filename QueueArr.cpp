#include <iostream>
using namespace std;
class QueueUsingArray {
    int front, rear, size;
    int* queue;
public:
    QueueUsingArray(int capacity) {
        size = capacity;
        front = -1;
        rear = -1;
        queue = new int[size];
    }
    void enqueue(int item) {
        if (rear == size - 1) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            queue[++rear] = item;
            displayQueue();
        }
    }
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Dequeued: " << queue[front++] << endl;
            displayQueue();
        }
    }
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
    }
    void displayQueue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
    ~QueueUsingArray() {
        delete[] queue;
    }
};
// Example usage:
int main() {
    QueueUsingArray q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    return 0;
}
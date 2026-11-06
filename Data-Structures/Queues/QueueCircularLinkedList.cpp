#include <iostream>
using namespace std;
class CircularQueue {
    int front, rear, size;
    int* queue;
public:
    CircularQueue(int capacity) {
        size = capacity;
        front = -1;
        rear = -1;
        queue = new int[size];
    }
    void enqueue(int item) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % size;
            queue[rear] = item;
            displayQueue();
        }
    }
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Dequeued: " << queue[front] << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            displayQueue();
        }
    }
    bool isEmpty() {
        return front == -1;
    }
    int peek() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
    }
    void displayQueue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % size;
        }
        cout << queue[rear] << endl;
    }
    ~CircularQueue() {
        delete[] queue;
    }
};
// Example usage:
int main() {
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    return 0;
}
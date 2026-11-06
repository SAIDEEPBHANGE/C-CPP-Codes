#include <iostream>
#include <queue>
using namespace std;
void displayQueue(queue<int> q) {
    if (q.empty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    displayQueue(q);
    q.pop();
    cout << "After dequeue:" << endl;
    displayQueue(q);
    return 0;
}
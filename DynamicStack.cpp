#include <iostream>
using namespace std;
class DynamicStack {
private:
    int* arr;        // Array to store stack elements
    int top;         // Index to track the top element
    int capacity;    // Current capacity of the stack
public:
    // Constructor to initialize stack
    DynamicStack(int initialCapacity = 2) {
        capacity = initialCapacity;
        arr = new int[capacity];
        top = -1;  // Stack is empty initially
    }
    // Destructor to free memory
    ~DynamicStack() {
        delete[] arr;
    }
    // Function to check if stack is full
    bool isFull() const { // Marked as const
        return top == capacity - 1;
    }
    // Function to check if stack is empty
    bool isEmpty() const { // Marked as const
        return top == -1;
    }
    // Function to resize the stack (double its size)
    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        // Copy old elements to the new array
        for (int i = 0; i <= top; i++) {
            newArr[i] = arr[i];
        }
        // Free the old array and update the pointer
        delete[] arr;
        arr = newArr;
        cout << "Stack resized to capacity: " << capacity << endl;
    }
    // Function to add an element to the stack
    void push(int value) {
        if (isFull()) {
            resize();  // Resize the stack if it is full
        }
        arr[++top] = value;
        cout << value << " pushed to stack." << endl;
    }
    // Function to remove an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Stack is empty." << endl;
            return -1;
        }
        return arr[top--];
    }
    // Function to get the top element of the stack
    int peek() const { // Marked as const
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
    // Function to display stack elements
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    DynamicStack stack;
    stack.push(10);  // Push 10 onto the stack
    stack.push(20);  // Push 20 onto the stack
    stack.push(30);  // Push 30 onto the stack
    stack.push(40);  // Push 40 onto the stack
    stack.push(50);  // Push 50 onto the stack
    stack.push(60);  // Push 60 onto the stack (this will trigger resize)
    stack.display(); // Display the stack
    cout << "Top element is: " << stack.peek() << endl;  // Peek at the top element
    cout << "Popped element: " << stack.pop() << endl;  // Pop an element
    stack.display();  // Display the stack after popping
    return 0;
}
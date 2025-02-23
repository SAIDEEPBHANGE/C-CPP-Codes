#include <iostream>
using namespace std;
// Stack class using array
class Stack {
private:
    int* arr;        // Array to store stack elements
    int top;         // Index to track the top element
    int capacity;    // Maximum capacity of the stack
public:
    // Constructor to initialize stack
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;  // Stack is empty initially
    }
    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }
    // Function to check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }
    // Function to check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
    // Function to add an element to the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;  // Increment top and add element
        cout << value << " pushed to stack." << endl;
    }
    // Function to remove an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Stack is empty." << endl;
            return -1;
        }
        int poppedValue = arr[top--];  // Remove top element and decrement top
        return poppedValue;
    }
    // Function to get the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];  // Return top element
    }
    // Function to display stack elements
    void display() {
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
    Stack stack(5);  // Create a stack of capacity 5
    stack.push(10);  // Push 10 onto the stack
    stack.push(20);  // Push 20 onto the stack
    stack.push(30);  // Push 30 onto the stack
    stack.push(40);  // Push 40 onto the stack
    stack.push(50);  // Push 50 onto the stack
    stack.push(60);  // This will trigger stack overflow
    stack.display(); // Display the current stack
    cout << "Top element is: " << stack.peek() << endl;  // Peek at the top element
    cout << "Popped element: " << stack.pop() << endl;  // Pop an element
    stack.display();  // Display the stack after popping
    return 0;
}
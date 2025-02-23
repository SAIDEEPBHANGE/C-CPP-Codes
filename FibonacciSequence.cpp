#include <iostream>
using namespace std;
// Fibonacci Sequence using Recursion
int fibonacciRecursion(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}
// Fibonacci Sequence using Loop (Iterative Approach)
int fibonacciLoop(int n) {
    if (n <= 1) {
        return n;
    }
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}
int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci Sequence: ";
    cin >> n;
    cout << "Fibonacci Sequence using Recursion:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursion(i) << " ";
    }
    cout << endl;
    cout << "Fibonacci Sequence using Loop:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibonacciLoop(i) << " ";
    }
    cout << endl;
    return 0;
}
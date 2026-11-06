#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;
string fractionToDecimal(int numerator, int denominator) {
    // Handle the case where the result is 0
    if (numerator == 0) {
        return "0";
    }
    // Initialize the result string
    string result = "";
    // Determine if the result should be negative
    if ((numerator < 0) ^ (denominator < 0)) {
        result += "-";
    }
    // Work with absolute values to simplify the calculation
    long long num = abs((long long)numerator);
    long long denom = abs((long long)denominator);
    // Integer part of the fraction
    result += to_string(num / denom);
    // Remainder after the integer part
    long long remainder = num % denom;
    // If there is no remainder, return the result
    if (remainder == 0) {
        return result;
    }
    // Decimal part
    result += ".";
    // Map to store the index where each remainder first occurs
    unordered_map<long long, int> remainder_map;
    // Process the decimal part
    while (remainder != 0) {
        // If this remainder has been seen before, we have a repeating decimal
        if (remainder_map.find(remainder) != remainder_map.end()) {
            int index = remainder_map[remainder];
            result.insert(index, "(");
            result += ")";
            return result;
        }
        // Store the index of the remainder
        remainder_map[remainder] = result.length();
        // Multiply the remainder by 10 to get the next digit
        remainder *= 10;
        result += to_string(remainder / denom);
        // Update the remainder
        remainder %= denom;
    }
    return result;
}
int main() {
    int numerator = 1, denominator = 2;
    cout << fractionToDecimal(numerator, denominator) << endl; // "0.5"
    numerator = 2, denominator = 3;
    cout << fractionToDecimal(numerator, denominator) << endl; // "0.(6)"
    numerator = 4, denominator = 333;
    cout << fractionToDecimal(numerator, denominator) << endl; // "0.(012)"
    numerator = 1, denominator = 6;
    cout << fractionToDecimal(numerator, denominator) << endl; // "0.1(6)"
    return 0;
}
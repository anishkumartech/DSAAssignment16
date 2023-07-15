#include <iostream>
#include <stack>
#include <string>

int reverseNumber(int number) {
    std::string numberString = std::to_string(number);
    std::stack<char> stack;

    // Push each digit onto the stack
    for (char digit : numberString) {
        stack.push(digit);
    }

    // Pop each digit from the stack and append it to the reversed number string
    std::string reversedString;
    while (!stack.empty()) {
        reversedString += stack.top();
        stack.pop();
    }

    // Convert the reversed number string back to an integer
    int reversedNumber = std::stoi(reversedString);

    return reversedNumber;
}

int main() {
    int number1 = 365;
    int reversed1 = reverseNumber(number1);
    std::cout << "Reversed number for " << number1 << ": " << reversed1 << std::endl;

    int number2 = 6899;
    int reversed2 = reverseNumber(number2);
    std::cout << "Reversed number for " << number2 << ": " << reversed2 << std::endl;

    return 0;
}


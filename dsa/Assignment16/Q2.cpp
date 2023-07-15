#include <iostream>
#include <stack>

void sortStack(std::stack<int>& inputStack) {
    std::stack<int> tempStack;

    while (!inputStack.empty()) {
        int temp = inputStack.top();
        inputStack.pop();

        while (!tempStack.empty() && tempStack.top() > temp) {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    // Copy elements from tempStack to inputStack to get the sorted stack
    while (!tempStack.empty()) {
        inputStack.push(tempStack.top());
        tempStack.pop();
    }
}

void printStack(const std::stack<int>& stack) {
    std::cout << "Stack: ";
    std::stack<int> temp = stack;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> stack1;
    stack1.push(34);
    stack1.push(3);
    stack1.push(31);
    stack1.push(98);
    stack1.push(92);
    stack1.push(23);

    std::cout << "Before sorting:" << std::endl;
    printStack(stack1);

    sortStack(stack1);

    std::cout << "After sorting:" << std::endl;
    printStack(stack1);

    std::stack<int> stack2;
    stack2.push(3);
    stack2.push(5);
    stack2.push(1);
    stack2.push(4);
    stack2.push(2);
    stack2.push(8);

    std::cout << "Before sorting:" << std::endl;
    printStack(stack2);

    sortStack(stack2);

    std::cout << "After sorting:" << std::endl;
    printStack(stack2);

    return 0;
}


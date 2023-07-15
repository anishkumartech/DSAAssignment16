#include <iostream>
#include <stack>

void deleteMiddle(std::stack<int>& stack, int middleIndex) {
    if (stack.empty() || middleIndex < 0 || middleIndex >= stack.size()) {
        return;
    }

    if (stack.size() == 1) {
        stack.pop();
        return;
    }

    std::stack<int> tempStack;

    for (int i = 0; i < middleIndex; i++) {
        tempStack.push(stack.top());
        stack.pop();
    }

    stack.pop();

    while (!tempStack.empty()) {
        stack.push(tempStack.top());
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
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);

    std::cout << "Before deleting middle element:" << std::endl;
    printStack(stack1);

    int middleIndex1 = stack1.size() / 2;
    deleteMiddle(stack1, middleIndex1);

    std::cout << "After deleting middle element:" << std::endl;
    printStack(stack1);

    std::stack<int> stack2;
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);
    stack2.push(4);
    stack2.push(5);
    stack2.push(6);

    std::cout << "Before deleting middle element:" << std::endl;
    printStack(stack2);

    int middleIndex2 = stack2.size() / 2;
    deleteMiddle(stack2, middleIndex2);

    std::cout << "After deleting middle element:" << std::endl;
    printStack(stack2);

    return 0;
}



#include <iostream>
#include <queue>
#include <stack>

std::string checkIncreasingOrder(std::queue<int>& givenQueue) {
    std::stack<int> stack;
    std::queue<int> secondQueue;
    int expected = 1;

    while (!givenQueue.empty()) {
        if (givenQueue.front() == expected) {
            secondQueue.push(givenQueue.front());
            givenQueue.pop();
            expected++;
        } else if (!stack.empty() && stack.top() == expected) {
            secondQueue.push(stack.top());
            stack.pop();
            expected++;
        } else {
            stack.push(givenQueue.front());
            givenQueue.pop();
        }
    }

    while (!stack.empty()) {
        if (stack.top() == expected) {
            secondQueue.push(stack.top());
            stack.pop();
            expected++;
        } else {
            return "No";
        }
    }

    if (!givenQueue.empty() || !stack.empty()) {
        return "No";
    }

    return "Yes";
}

int main() {
    std::queue<int> queue1;
    queue1.push(5);
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);
    queue1.push(4);

    std::string result1 = checkIncreasingOrder(queue1);
    std::cout << "Result 1: " << result1 << std::endl;

    std::queue<int> queue2;
    queue2.push(5);
    queue2.push(1);
    queue2.push(2);
    queue2.push(6);
    queue2.push(3);
    queue2.push(4);

    std::string result2 = checkIncreasingOrder(queue2);
    std::cout << "Result 2: " << result2 << std::endl;

    return 0;
}

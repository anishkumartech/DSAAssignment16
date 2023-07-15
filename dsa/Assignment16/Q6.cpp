#include <iostream>
#include <queue>
#include <stack>

std::queue<int> reverseFirstKElements(std::queue<int>& q, int k) {
    std::stack<int> stack;

    // Step 1: Dequeue the first k elements and push them onto the stack
    for (int i = 0; i < k; i++) {
        stack.push(q.front());
        q.pop();
    }

    std::queue<int> tempQueue;

    // Step 2: Enqueue the elements from the stack into the temporary queue
    while (!stack.empty()) {
        tempQueue.push(stack.top());
        stack.pop();
    }

    // Step 3: Enqueue the remaining elements from the original queue into the temporary queue
    while (!q.empty()) {
        tempQueue.push(q.front());
        q.pop();
    }

    // Step 4: Copy the elements from the temporary queue back into the original queue
    while (!tempQueue.empty()) {
        q.push(tempQueue.front());
        tempQueue.pop();
    }

    return q;
}

void printQueue(const std::queue<int>& q) {
    std::cout << "Queue: ";
    std::queue<int> temp = q;
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.push(7);

    int k = 4;

    std::cout << "Before reversing: ";
    printQueue(queue);

    std::queue<int> reversedQueue = reverseFirstKElements(queue, k);

    std::cout << "After reversing first " << k << " elements: ";
    printQueue(reversedQueue);

    return 0;
}


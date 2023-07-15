#include <deque>
#include<iostream>

class FrontMiddleBackQueue {
    std::deque<int> frontDeque;
    std::deque<int> backDeque;

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        frontDeque.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (frontDeque.size() > backDeque.size()) {
            backDeque.push_front(frontDeque.back());
            frontDeque.pop_back();
        }
        frontDeque.push_back(val);
    }

    void pushBack(int val) {
        backDeque.push_back(val);
        balance();
    }

    int popFront() {
        if (frontDeque.empty() && backDeque.empty())
            return -1;

        int val;
        if (!frontDeque.empty()) {
            val = frontDeque.front();
            frontDeque.pop_front();
        } else {
            val = backDeque.front();
            backDeque.pop_front();
        }

        balance();
        return val;
    }

    int popMiddle() {
        if (frontDeque.empty() && backDeque.empty())
            return -1;

        int val;
        if (frontDeque.size() == backDeque.size()) {
            val = frontDeque.back();
            frontDeque.pop_back();
        } else {
            val = frontDeque.front();
            frontDeque.pop_front();
        }

        balance();
        return val;
    }

    int popBack() {
        if (frontDeque.empty() && backDeque.empty())
            return -1;

        int val;
        if (!backDeque.empty()) {
            val = backDeque.back();
            backDeque.pop_back();
        } else {
            val = frontDeque.back();
            frontDeque.pop_back();
        }

        balance();
        return val;
    }

private:
    void balance() {
        if (frontDeque.size() > backDeque.size() + 1) {
            backDeque.push_front(frontDeque.back());
            frontDeque.pop_back();
        } else if (backDeque.size() > frontDeque.size()) {
            frontDeque.push_back(backDeque.front());
            backDeque.pop_front();
        }
    }
};

int main() {
    FrontMiddleBackQueue q;
    q.pushFront(1);
    q.pushBack(2);
    q.pushMiddle(3);
    q.pushMiddle(4);

    std::cout << q.popFront() << std::endl;
    std::cout << q.popMiddle() << std::endl;
    std::cout << q.popMiddle() << std::endl;
    std::cout << q.popBack() << std::endl;
    std::cout << q.popFront() << std::endl;

}

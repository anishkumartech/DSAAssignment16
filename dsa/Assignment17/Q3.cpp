
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int countStudentsUnableToEat(const std::vector<int>& students, const std::vector<int>& sandwiches) {
    std::queue<int> studentQueue;
    std::stack<int> sandwichStack;

    // Fill the student queue
    for (int student : students) {
        studentQueue.push(student);
    }

    // Fill the sandwich stack
    for (int sandwich : sandwiches) {
        sandwichStack.push(sandwich);
    }

    // Simulate the process
    while (!studentQueue.empty() && !sandwichStack.empty()) {
        if (studentQueue.front() == sandwichStack.top()) {
            studentQueue.pop();
            sandwichStack.pop();
        } else {
            int frontStudent = studentQueue.front();
            studentQueue.pop();
            studentQueue.push(frontStudent);
        }
    }

    return studentQueue.size();
}

int main() {
    std::vector<int> students1 = {1, 1, 0, 0};
    std::vector<int> sandwiches1 = {0, 1, 0, 1};
    int unableToEat1 = countStudentsUnableToEat(students1, sandwiches1);
    std::cout << "Number of students unable to eat: " << unableToEat1 << std::endl;

    std::vector<int> students2 = {1, 1, 1, 0, 0, 1};
    std::vector<int> sandwiches2 = {1, 0, 0, 0, 1, 1};
    int unableToEat2 = countStudentsUnableToEat(students2, sandwiches2);
    std::cout << "Number of students unable to eat: " << unableToEat2 << std::endl;

    return 0;
}

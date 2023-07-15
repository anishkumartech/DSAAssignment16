#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int maxAbsDifference(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> leftSmaller(n);
    std::vector<int> rightSmaller(n);

    std::stack<int> stack;

    // Find nearest smaller element on the left side
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && stack.top() >= arr[i]) {
            stack.pop();
        }
        leftSmaller[i] = stack.empty() ? 0 : stack.top();
        stack.push(arr[i]);
    }

    // Clear the stack
    while (!stack.empty()) {
        stack.pop();
    }

    // Find nearest smaller element on the right side
    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() && stack.top() >= arr[i]) {
            stack.pop();
        }
        rightSmaller[i] = stack.empty() ? 0 : stack.top();
        stack.push(arr[i]);
    }

    // Find the maximum absolute difference
    int maxDiff = 0;
    for (int i = 0; i < n; i++) {
        maxDiff = std::max(maxDiff, std::abs(leftSmaller[i] - rightSmaller[i]));
    }

    return maxDiff;
}

int main() {
    std::vector<int> arr1 = {2, 1, 8};
    int maxDiff1 = maxAbsDifference(arr1);
    std::cout << "Maximum absolute difference: " << maxDiff1 << std::endl;

    std::vector<int> arr2 = {2, 4, 8, 7, 7, 9, 3};
    int maxDiff2 = maxAbsDifference(arr2);
    std::cout << "Maximum absolute difference: " << maxDiff2 << std::endl;

    std::vector<int> arr3 = {5, 1, 9, 2, 5, 1, 7};
    int maxDiff3 = maxAbsDifference(arr3);
    std::cout << "Maximum absolute difference: " << maxDiff3 << std::endl;

    return 0;
}

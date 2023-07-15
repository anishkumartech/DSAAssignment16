#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

std::vector<int> findNearestGreaterFrequency(const std::vector<int>& arr) {
    std::unordered_map<int, int> freq;
    std::stack<int> stack;
    std::vector<int> result(arr.size(), -1);

    // Step 1: Calculate frequency of each element
    for (int num : arr) {
        freq[num]++;
    }

    // Step 2-7: Find nearest element with greater frequency
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!stack.empty() && freq[arr[i]] >= freq[arr[stack.top()]]) {
            stack.pop();
        }

        if (!stack.empty()) {
            result[i] = arr[stack.top()];
        }

        stack.push(i);
    }

    return result;
}

int main() {
    std::vector<int> arr1 = {1, 1, 2, 3, 4, 2, 1};
    std::vector<int> result1 = findNearestGreaterFrequency(arr1);

    std::vector<int> arr2 = {1, 1, 1, 2, 2, 2, 2, 11, 3, 3};
    std::vector<int> result2 = findNearestGreaterFrequency(arr2);

    // Print the results
    std::cout << "Result 1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Result 2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


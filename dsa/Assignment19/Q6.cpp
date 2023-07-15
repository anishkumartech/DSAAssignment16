
#include <iostream>
#include <vector>

std::vector<int> mergeArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> merged;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0;
    int j = 0;

    // Merge the arrays
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Add the remaining elements from arr1, if any
    while (i < n1) {
        merged.push_back(arr1[i]);
        i++;
    }

    // Add the remaining elements from arr2, if any
    while (j < n2) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

// Helper function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    std::vector<int> arr1 = {1, 3, 4, 5};
    std::vector<int> arr2 = {2, 4, 6, 8};
    std::vector<int> merged = mergeArrays(arr1, arr2);

    printArray(merged);

    return 0;
}

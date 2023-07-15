
#include <iostream>
#include <vector>

void rearrangeArray(std::vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    int j = 0;

    // Find the next positive number's position
    while (j < n && arr[j] >= 0) {
        j++;
    }

    // Rearrange the array
    while (i < n && j < n) {
        // Swap the current positive number with the next negative number
        std::swap(arr[i], arr[j]);

        // Find the next positive number's position
        i += 2;
        while (j < n && arr[j] >= 0) {
            j++;
        }
    }
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
    std::vector<int> arr = {1, 2, 3, -4, -1, 4};
    rearrangeArray(arr);

    printArray(arr);

    return 0;
}

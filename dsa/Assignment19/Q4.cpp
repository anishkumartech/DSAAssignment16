#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int n = nums.size();
    int j = 0;

    // Move non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    // Fill the remaining positions with zeroes
    while (j < n) {
        nums[j++] = 0;
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
    std::vector<int> nums = {1, 2, 0, 4, 3, 0, 5, 0};
    moveZeroes(nums);

    printArray(nums);

    return 0;
}


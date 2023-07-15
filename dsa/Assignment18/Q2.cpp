#include <iostream>
#include <vector>

void sortColors(std::vector<int>& nums) {
    int low = 0;        // Pointer for the section of red color (0)
    int mid = 0;        // Pointer for the section of white color (1)
    int high = nums.size() - 1;   // Pointer for the section of blue color (2)

    while (mid <= high) {
        if (nums[mid] == 0) {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else if (nums[mid] == 2) {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    std::vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);

    // Print the sorted colors
    for (const auto& color : nums) {
        std::cout << color << " ";
    }
    std::cout << std::endl;

    return 0;
}


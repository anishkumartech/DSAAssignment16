
#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::vector<int> result;

    // Find the common elements
    for (int num : nums2) {
        if (set1.count(num)) {
            result.push_back(num);
            set1.erase(num);
        }
    }

    return result;
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
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    std::vector<int> intersect = intersection(nums1, nums2);

    printArray(intersect);

    return 0;
}

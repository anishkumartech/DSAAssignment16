
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> intersect(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_map<int, int> freqMap;
    std::vector<int> result;

    // Build frequency map for nums1
    for (int num : nums1) {
        freqMap[num]++;
    }

    // Find the common elements and reduce their frequency
    for (int num : nums2) {
        if (freqMap[num] > 0) {
            result.push_back(num);
            freqMap[num]--;
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
    std::vector<int> nums1 = {4,9,5};
    std::vector<int> nums2 = {9,4,9,8,4};
    std::vector<int> intersected = intersect(nums1, nums2);

    printArray(intersected);

    return 0;
}

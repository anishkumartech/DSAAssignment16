#include <iostream>
#include <vector>
#include <algorithm>

int kadane(const std::vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum = std::max(nums[i], currentSum + nums[i]);
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
}

int maxSubarraySumCircular(const std::vector<int>& nums) {
    int totalSum = 0;
    int maxSum = 0;
    int minSum = 0;
    int tempMax = 0;
    int tempMin = 0;

    for (int num : nums) {
        totalSum += num;
        tempMax += num;
        tempMin += num;
        maxSum = std::max(maxSum, tempMax);
        minSum = std::min(minSum, tempMin);
        if (tempMax < 0)
            tempMax = 0;
        if (tempMin > 0)
            tempMin = 0;
    }

    // Handle the case where all elements are negative
    if (totalSum == minSum)
        return maxSum;

    return std::max(maxSum, totalSum - minSum);
}

int main() {
    std::vector<int> nums1 = {1, -2, 3, -2};
    int maxSum1 = maxSubarraySumCircular(nums1);
    std::cout << "Maximum subarray sum: " << maxSum1 << std::endl;

    std::vector<int> nums2 = {5, -3, 5};
    int maxSum2 = maxSubarraySumCircular(nums2);
    std::cout << "Maximum subarray sum: " << maxSum2 << std::endl;

    std::vector<int> nums3 = {-3, -2, -3};
    int maxSum3 = maxSubarraySumCircular(nums3);
    std::cout << "Maximum subarray sum: " << maxSum3 << std::endl;

    return 0;
}

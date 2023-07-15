#include <iostream>
#include <vector>
#include <algorithm>

int lengthOfLIS(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 1); // Initialize dp array with 1

    // Iterate through the array starting from the second element
    for (int i = 1; i < n; i++) {
        // Check all previous elements
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                // Update dp[i] if the current element extends the increasing subsequence
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum value in the dp array
    int maxLen = *std::max_element(dp.begin(), dp.end());

    return maxLen;
}

int main() {
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int len = lengthOfLIS(nums);
    std::cout << "Length of Longest Increasing Subsequence: " << len << std::endl;

    return 0;
}


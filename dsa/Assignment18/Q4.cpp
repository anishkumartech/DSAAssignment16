#include <iostream>
#include <vector>

int maximumGap(std::vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return 0; // Return 0 if the array contains less than 2 elements
    }

    // Find the maximum and minimum values in the array
    int minNum = nums[0];
    int maxNum = nums[0];
    for (int num : nums) {
        minNum = std::min(minNum, num);
        maxNum = std::max(maxNum, num);
    }

    // Calculate the size of each bucket
    int bucketSize = std::max(1, (maxNum - minNum) / (n - 1));

    // Calculate the number of buckets
    int numBuckets = (maxNum - minNum) / bucketSize + 1;

    // Create buckets to store the minimum and maximum values
    std::vector<int> minBucket(numBuckets, INT_MAX);
    std::vector<int> maxBucket(numBuckets, INT_MIN);

    // Assign each number to its corresponding bucket
    for (int num : nums) {
        int index = (num - minNum) / bucketSize;
        minBucket[index] = std::min(minBucket[index], num);
        maxBucket[index] = std::max(maxBucket[index], num);
    }

    // Calculate the maximum gap
    int maxGap = 0;
    int prevMax = minNum;
    for (int i = 0; i < numBuckets; i++) {
        if (minBucket[i] != INT_MAX) {
            maxGap = std::max(maxGap, minBucket[i] - prevMax);
            prevMax = maxBucket[i];
        }
    }

    return maxGap;
}

int main() {
    std::vector<int> nums = {3, 6, 9, 1};
    int maxGap = maximumGap(nums);
    std::cout << "Maximum Gap: " << maxGap << std::endl;

    return 0;
}


#include <iostream>
#include <vector>

void merge(std::vector<int>& nums, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = 0;

    std::vector<int> temp(end - start + 1);

    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= end) {
        temp[k++] = nums[j++];
    }

    for (int p = start; p <= end; p++) {
        nums[p] = temp[p - start];
    }
}

void mergeSort(std::vector<int>& nums, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
}

std::vector<int> sortArray(std::vector<int>& nums) {
    int n = nums.size();
    mergeSort(nums, 0, n - 1);
    return nums;
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
    std::vector<int> nums = {5, 2, 3, 1};
    std::vector<int> sortedNums = sortArray(nums);

    printArray(sortedNums);

    return 0;
}


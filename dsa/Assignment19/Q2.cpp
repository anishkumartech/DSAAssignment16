#include <iostream>
#include <vector>

void merge(std::vector<std::pair<int, int>>& arr, int start, int mid, int end, std::vector<int>& counts) {
    int i = start;
    int j = mid + 1;
    int k = 0;
    int rightCount = 0;

    std::vector<std::pair<int, int>> temp(end - start + 1);

    while (i <= mid && j <= end) {
        if (arr[i].first <= arr[j].first) {
            counts[arr[i].second] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        counts[arr[i].second] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (int p = start; p <= end; p++) {
        arr[p] = temp[p - start];
    }
}

void mergeSort(std::vector<std::pair<int, int>>& arr, int start, int end, std::vector<int>& counts) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid, counts);
        mergeSort(arr, mid + 1, end, counts);
        merge(arr, start, mid, end, counts);
    }
}

std::vector<int> countSmaller(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> counts(n, 0);
    std::vector<std::pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = std::make_pair(nums[i], i);
    }

    mergeSort(arr, 0, n - 1, counts);

    return counts;
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
    std::vector<int> nums = {5, 2, 6, 1};
    std::vector<int> counts = countSmaller(nums);

    printArray(counts);

    return 0;
}


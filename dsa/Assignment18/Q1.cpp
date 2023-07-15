#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>>& intervals) {
    std::vector<std::vector<int>> mergedIntervals;

    // Sort intervals based on start time
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    // Merge overlapping intervals
    for (const auto& interval : intervals) {
        if (mergedIntervals.empty() || interval[0] > mergedIntervals.back()[1]) {
            mergedIntervals.push_back(interval);
        } else {
            mergedIntervals.back()[1] = std::max(mergedIntervals.back()[1], interval[1]);
        }
    }

    return mergedIntervals;
}

int main() {
    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<std::vector<int>> merged = mergeIntervals(intervals);

    // Print the merged intervals
    for (const auto& interval : merged) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}


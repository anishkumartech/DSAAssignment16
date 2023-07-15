#include <iostream>
#include <vector>
#include <algorithm>

int findMinArrowShots(std::vector<std::vector<int>>& points) {
    if (points.empty()) {
        return 0;
    }

    // Sort the balloons based on their end points
    std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    });

    int arrows = 1;
    int reference = points[0][1];

    // Iterate through the remaining balloons
    for (int i = 1; i < points.size(); i++) {
        // If the current balloon's start point is after the reference point,
        // we need an additional arrow and update the reference point
        if (points[i][0] > reference) {
            arrows++;
            reference = points[i][1];
        }
    }

    return arrows;
}

int main() {
    std::vector<std::vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int minArrows = findMinArrowShots(points);
    std::cout << "Minimum Arrows Needed: " << minArrows << std::endl;

    return 0;
}


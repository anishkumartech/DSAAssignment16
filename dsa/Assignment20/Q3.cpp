#include <iostream>
#include <queue>

bool isLevelOrderBST(int arr[], int n) {
    if (n == 0) {
        return true;
    }

    std::queue<std::pair<int, std::pair<int, int>>> q;
    q.push({arr[0], {INT_MIN, INT_MAX}});

    int i = 1;
    while (!q.empty() && i < n) {
        auto curr = q.front();
        q.pop();

        int value = curr.first;
        int minValue = curr.second.first;
        int maxValue = curr.second.second;

        if (value < minValue || value > maxValue) {
            return false;
        }

        if (i < n && arr[i] < value) {
            q.push({arr[i], {minValue, value}});
            i++;
        }

        if (i < n && arr[i] > value) {
            q.push({arr[i], {value, maxValue}});
            i++;
        }
    }

    return true;
}

int main() {
    int arr1[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    if (isLevelOrderBST(arr1, size1)) {
        std::cout << "Output1: Yes" << std::endl;
    } else {
        std::cout << "Output1: No" << std::endl;
    }

    int arr2[] = {11, 6, 13, 5, 12, 10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    if (isLevelOrderBST(arr2, size2)) {
        std::cout << "Output2: Yes" << std::endl;
    } else {
        std::cout << "Output2: No" << std::endl;
    }

    return 0;
}

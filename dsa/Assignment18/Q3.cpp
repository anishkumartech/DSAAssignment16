#include <iostream>

//bool isBadVersion(int version); // API function

bool isBadVersion(int version) {
    // Example implementation of the isBadVersion function
    // Replace this with your own implementation

    if (version >= 4) {
        return true;   // Version 4 and onwards are bad
    } else {
        return false;  // Versions 1, 2, and 3 are good
    }
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n = 5;
    int bad = 4;

    int firstBad = firstBadVersion(n);
    std::cout << "First bad version: " << firstBad << std::endl;

    return 0;
}

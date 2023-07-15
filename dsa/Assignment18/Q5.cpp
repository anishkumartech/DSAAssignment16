#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;

    for (int num : nums) {
        if (seen.count(num) > 0) {
            return true; // Found a duplicate
        }
        seen.insert(num);
    }

    return false; // No duplicates found
}

int main() {
    std::vector<int> nums = {1, 2, 3, 1};
    bool hasDuplicates = containsDuplicate(nums);
    std::cout << "Contains Duplicates: " << std::boolalpha << hasDuplicates << std::endl;

    return 0;
}


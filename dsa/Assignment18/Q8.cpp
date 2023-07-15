#include <iostream>
#include <vector>
#include <stack>

bool find132pattern(std::vector<int>& nums) {
    int n = nums.size();
    std::stack<int> st;
    int maxVal = INT_MIN;

    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] < maxVal) {
            return true;
        }

        while (!st.empty() && nums[i] > st.top()) {
            maxVal = std::max(maxVal, st.top());
            st.pop();
        }

        st.push(nums[i]);
    }

    return false;
}

int main() {
    std::vector<int> nums = {3,1,4,2};
    bool foundPattern = find132pattern(nums);
    std::cout << "Pattern Found: " << (foundPattern ? "true" : "false") << std::endl;

    return 0;
}

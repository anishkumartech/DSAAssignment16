#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

int maxSum = INT_MIN;

int findMaxSubtreeSum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = findMaxSubtreeSum(root->left);
    int rightSum = findMaxSubtreeSum(root->right);

    int currentSum = root->val + leftSum + rightSum;

    maxSum = std::max(maxSum, currentSum);

    return currentSum;
}

int findMaxSubtreeSumWrapper(TreeNode* root) {
    findMaxSubtreeSum(root);
    return maxSum;
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(2);

    // Find the maximum subtree sum
    int maxSubtreeSum = findMaxSubtreeSumWrapper(root);
    std::cout << "Maximum subtree sum: " << maxSubtreeSum << std::endl;

    return 0;
}


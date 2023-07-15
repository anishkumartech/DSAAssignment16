#include <iostream>
#include <queue>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* constructBST(int arr[], int start, int end) {
    if (start > end) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[start]);

    int splitIndex = end + 1;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] > arr[start]) {
            splitIndex = i;
            break;
        }
    }

    root->left = constructBST(arr, start + 1, splitIndex - 1);
    root->right = constructBST(arr, splitIndex, end);

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->value << " ";
    inorderTraversal(root->right);
}

int main() {
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = constructBST(arr, 0, size - 1);

    std::cout << "BST (Inorder traversal): ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}

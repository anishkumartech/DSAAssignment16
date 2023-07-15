
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void convertToDLL(TreeNode* root, TreeNode** head, TreeNode** prev) {
    if (root == nullptr) {
        return;
    }

    convertToDLL(root->left, head, prev);

    if (*prev == nullptr) {
        // Set the head of the doubly linked list
        *head = root;
    } else {
        // Adjust pointers to create the doubly linked list
        (*prev)->right = root;
        root->left = *prev;
    }

    *prev = root;

    convertToDLL(root->right, head, prev);
}

void printDLL(TreeNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->right;
    }
    std::cout << std::endl;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(35);

    TreeNode* head = nullptr;
    TreeNode* prev = nullptr;

    convertToDLL(root, &head, &prev);

    std::cout << "Output: ";
    printDLL(head);

    return 0;
}

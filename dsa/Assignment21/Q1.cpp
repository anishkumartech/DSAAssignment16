#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root, std::vector<int>& nodes) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left, nodes);
    nodes.push_back(root->val);
    inorderTraversal(root->right, nodes);
}

void convertToBST(TreeNode* root, std::vector<int>& nodes, int& index) {
    if (root == nullptr) {
        return;
    }

    convertToBST(root->left, nodes, index);
    root->val = nodes[index];
    index++;
    convertToBST(root->right, nodes, index);
}

TreeNode* binaryTreeToBST(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    std::vector<int> nodes;
    inorderTraversal(root, nodes);
    std::sort(nodes.begin(), nodes.end());

    int index = 0;
    convertToBST(root, nodes, index);

    return root;
}

void inorderPrint(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderPrint(root->left);
    std::cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(4);

    std::cout << "Input BST: ";
    inorderPrint(root);
    std::cout << std::endl;

    root = binaryTreeToBST(root);

    std::cout << "Output BST: ";
    inorderPrint(root);
    std::cout << std::endl;

    return 0;
}



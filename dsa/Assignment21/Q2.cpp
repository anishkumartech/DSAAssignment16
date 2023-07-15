
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    }

    return root;
}

TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->val > n1 && root->val > n2) {
        return findLCA(root->left, n1, n2);
    }

    if (root->val < n1 && root->val < n2) {
        return findLCA(root->right, n1, n2);
    }

    return root;
}

int findDistance(TreeNode* root, int key, int distance) {
    if (root == nullptr) {
        return -1;
    }

    if (root->val == key) {
        return distance;
    }

    if (key < root->val) {
        return findDistance(root->left, key, distance + 1);
    }

    return findDistance(root->right, key, distance + 1);
}

int findNodeDistance(TreeNode* root, int n1, int n2) {
    TreeNode* lca = findLCA(root, n1, n2);
    int distance1 = findDistance(lca, n1, 0);
    int distance2 = findDistance(lca, n2, 0);

    return distance1 + distance2;
}

int main() {
    std::vector<int> values = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    int n = values.size();

    TreeNode* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    int node1 = 6;
    int node2 = 14;

    int distance = findNodeDistance(root, node1, node2);

    std::cout << "The distance between the two keys = " << distance << std::endl;

    return 0;
}

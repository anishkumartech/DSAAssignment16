
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

void connectNodes(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        TreeNode* prev = nullptr;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* curr = q.front();
            q.pop();

            if (prev != nullptr) {
                prev->next = curr;
            }

            prev = curr;

            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }

        // Set the next pointer of the last node in the level to nullptr
        prev->next = nullptr;
    }
}

void printLevelOrder(TreeNode* root) {
    while (root != nullptr) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            std::cout << curr->val;
            if (curr->next != nullptr) {
                std::cout << " -> ";
            } else {
                std::cout << " -> -1";
            }
            curr = curr->next;
        }
        std::cout << std::endl;
        root = root->left;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    connectNodes(root);

    std::cout << "Output:" << std::endl;
    printLevelOrder(root);

    return 0;
}

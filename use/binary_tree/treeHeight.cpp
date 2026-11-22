
#include <iostream>
#include <cassert>
#include <algorithm>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value)
        : data(value), left(nullptr), right(nullptr) {}
};

int treeHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return 1 + std::max(leftHeight, rightHeight);
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void testTreeHeight() {
    assert(treeHeight(nullptr) == 0);

    TreeNode* single = new TreeNode(1);
    assert(treeHeight(single) == 1);
    deleteTree(single);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    assert(treeHeight(root) == 3);
    deleteTree(root);

    std::cout << "treeHeight tests passed!" << std::endl;
}

int main() {
    testTreeHeight();
    return 0;
}

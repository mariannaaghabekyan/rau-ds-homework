
#include <iostream>
#include <cassert>
#include <utility>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value)
        : data(value), left(nullptr), right(nullptr) {}
};

void mirrorTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::swap(root->left, root->right);

    mirrorTree(root->left);
    mirrorTree(root->right);
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void testMirrorTree() {
    mirrorTree(nullptr);

    TreeNode* single = new TreeNode(1);
    mirrorTree(single);
    assert(single->data == 1);
    assert(single->left == nullptr);
    assert(single->right == nullptr);
    deleteTree(single);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    mirrorTree(root);

    assert(root->data == 1);
    assert(root->left->data == 3);
    assert(root->right->data == 2);
    assert(root->right->right->data == 4);
    assert(root->right->left == nullptr);

    mirrorTree(root);

    assert(root->left->data == 2);
    assert(root->right->data == 3);
    assert(root->left->left->data == 4);

    deleteTree(root);

    std::cout << "mirrorTree tests passed!" << std::endl;
}

int main() {
    testMirrorTree();
    return 0;
}

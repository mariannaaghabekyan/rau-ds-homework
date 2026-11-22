
#include <iostream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value)
        : data(value), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void testCountNodes() {

    assert(countNodes(nullptr) == 0);

    TreeNode* single = new TreeNode(1);
    assert(countNodes(single) == 1);
    deleteTree(single);


    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    assert(countNodes(root) == 4);
    deleteTree(root);

    std::cout << "countNode tests passed!" << std::endl;
}

int main() {
    testCountNodes();
    return 0;
}

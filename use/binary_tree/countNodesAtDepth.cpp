#include <iostream>
#include <cassert>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value): data(value), left(nullptr), right(nullptr){}
};

int countNodesAtDepth(TreeNode* root, int k){
    if(root == nullptr || k < 1){
        return 0;
    }

    if(k == 1){
        return 1;
    }

    return countNodesAtDepth(root->left, k - 1) + countNodesAtDepth(root->right, k - 1);
}

void deleteTree(TreeNode* root){
    if(root == nullptr){
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void testCountNodesAtDepth(){
    assert(countNodesAtDepth(nullptr, 1) == 0);

    TreeNode* single = new TreeNode(1);
    assert(countNodesAtDepth(single, 1) == 1);
    assert(countNodesAtDepth(single, 2) == 0);
    deleteTree(single);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    assert(countNodesAtDepth(root, 1) == 1);
    assert(countNodesAtDepth(root, 2) == 2);
    assert(countNodesAtDepth(root, 3) == 2);
    assert(countNodesAtDepth(root, 4) == 0);
    assert(countNodesAtDepth(root, 0) == 0);

    deleteTree(root);

    std::cout << "countNodesAtDepth tests passed!" << std::endl;
}

int main() {
    testCountNodesAtDepth();
    return 0;
}

#include <iostream>
#include <cassert>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value) : data(value), left(nullptr), right(nullptr){}
};

int sumNodes(TreeNode* root){
    if(root == nullptr){
        return 0;
    }

    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

void deleteTree(TreeNode* root){
    if(root == nullptr){
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void testSumNodes(){
    assert(sumNodes(nullptr) == 0);

    TreeNode* single = new TreeNode(5);
    assert(sumNodes(single) == 5);
    deleteTree(single);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    assert(sumNodes(root) == 10);
    deleteTree(root);

    TreeNode* negative = new TreeNode(-1);
    negative->left = new TreeNode(-2);
    negative->right = new TreeNode(3);

    assert(sumNodes(negative) == 0);
    deleteTree(negative);

    std::cout << "sumNode tests passed!" << std::endl;
}

int main(){
    testSumNodes();
    return 0;
}
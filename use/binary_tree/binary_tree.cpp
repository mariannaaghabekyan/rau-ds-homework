#include <iostream>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int countNodes(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);

}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    std::cout << "Number of nodes: " << countNodes(root) << std::endl;
    return 0;
}
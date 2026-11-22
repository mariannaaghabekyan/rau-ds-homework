#include <iostream>
#include <cassert>
#include <sstream>
#include <string>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value) : data(value), left(nullptr), right(nullptr){} 

};

void preorder(TreeNode* root){
    if(root == nullptr){
        return;
    }

    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root){
    if (root == nullptr){
        return;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void postorder(TreeNode* root){
    if(root == nullptr){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

void deleteTree(TreeNode* root){
    if(root == nullptr){
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void testTraversals() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::ostringstream output;

    std::streambuf* originalCout = std::cout.rdbuf();

    std::cout.rdbuf(output.rdbuf());
    preorder(root);
    std::cout.rdbuf(originalCout);
    assert(output.str() == "1 2 3 ");

    output.str("");
    std::cout.rdbuf(output.rdbuf());
    inorder(root);
    std::cout.rdbuf(originalCout);
    assert(output.str() == "2 1 3 ");

    output.str("");
    std::cout.rdbuf(output.rdbuf());
    postorder(root);
    std::cout.rdbuf(originalCout);
    assert(output.str() == "2 3 1 ");

    deleteTree(root);

    std::cout << "traversals tests passed!" << std::endl;
}
int main(){
    testTraversals();
    return 0;
}

#include <iostream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value): data(value), left(nullptr), right(nullptr){}
};

bool areIdentical(TreeNode* root1, TreeNode* root2){
    if(root1 == nullptr && root2 == nullptr){
        return true;
    }

    if( root1 == nullptr || root2 == nullptr){
        return false;
    }

    return root1->data == root2->data && 
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right);
}

void deleteTree(TreeNode* root){
    if(root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void testsAreIdentical()
{
    assert(areIdentical(nullptr,nullptr));

    TreeNode* single = new TreeNode(5);
    assert(!areIdentical(single,nullptr));
    assert(!areIdentical(nullptr,single));
    deleteTree(single);

    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    assert(areIdentical(tree1,tree2));
    
    tree2->right->data = 4;
    assert(!areIdentical(tree1,tree2));
    tree2->right->data = 3;

    tree2->left->left = new TreeNode(4);
    assert(!areIdentical(tree1, tree2));

    deleteTree(tree1);
    deleteTree(tree2);

    std::cout << "areIdentical tests passed!"<< std::endl;
}

int main(){
    testsAreIdentical();
    return 0;
}
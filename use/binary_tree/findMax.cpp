#include <iostream>
#include <cassert>
#include <algorithm>
#include <climits>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value):data(value), left(nullptr), right(nullptr){}
};

int findMax(TreeNode* root){
    if(root == nullptr){
        return INT_MIN;
    }

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    return std::max(root->data, std::max(leftMax, rightMax));
}

int findMin(TreeNode* root){
    if(root == nullptr){
        return INT_MAX;
    }

    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);

    return std::min(root->data, std::min(leftMin, rightMin));
}

void deleteTree(TreeNode* root){
    if(root == nullptr){
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void testFindMinMax(){
    assert(findMax(nullptr) == INT_MIN);
    assert(findMin(nullptr) == INT_MAX);

    TreeNode* single = new TreeNode(5);
    assert(findMax(single) == 5);
    assert(findMin(single) == 5);
    deleteTree(single);

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);

    assert(findMax(root) == 8);
    assert(findMin(root) == 1);
    deleteTree(root);

    TreeNode* negative = new TreeNode(-5);
    negative->left = new TreeNode(-10);
    negative->right = new TreeNode(-2);

    assert(findMax(negative) == -2);
    assert(findMin(negative) == -10);
    deleteTree(negative);

    std::cout << "findMax and findMin tests passed!" << std::endl;
}

int main(){
    testFindMinMax();
    return 0;
}
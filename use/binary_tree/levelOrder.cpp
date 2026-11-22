#include <iostream>
#include <cassert>
#include <queue>
#include <sstream>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void levelOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

     while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void testLevelOrder() {
    std::ostringstream output;
    std::streambuf* originalCout = std::cout.rdbuf();

    std::cout.rdbuf(output.rdbuf());
    levelOrder(nullptr);
    std::cout.rdbuf(originalCout);

    assert(output.str() == "");

    TreeNode* single = new TreeNode(1);

    output.str("");
    std::cout.rdbuf(output.rdbuf());
    levelOrder(single);
    std::cout.rdbuf(originalCout);

    assert(output.str() == "1 ");
    deleteTree(single);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    output.str("");
    std::cout.rdbuf(output.rdbuf());
    levelOrder(root);
    std::cout.rdbuf(originalCout);

    assert(output.str() == "1 2 3 4 5 ");
    deleteTree(root);

    std::cout << "levelOrder tests passed!" << std::endl;
}
int main() {
    testLevelOrder();
    return 0;
}
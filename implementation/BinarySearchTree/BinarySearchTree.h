

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
    };

    Node* _root;
    int _size;

    Node* insert_recursive(Node* node, const T& value) {
        if (node == nullptr) {
            ++_size;
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert_recursive(node->left, value);
        } else if (value > node->data) {
            node->right = insert_recursive(node->right, value);
        }

        return node;
    }

    Node* find_recursive(Node* node, const T& value) const {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return find_recursive(node->left, value);
        }

        return find_recursive(node->right, value);
    }

    Node* remove_recursive(Node* node, const T& value) {
        if (node == nullptr) return nullptr;

        if (value < node->data) {
            node->left = remove_recursive(node->left, value);
        } else if (value > node->data) {
            node->right = remove_recursive(node->right, value);
        } else {
            --_size;

            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* successor = node->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }

            node->data = successor->data;
            ++_size;
            node->right = remove_recursive(node->right, successor->data);
        }

        return node;
    }

    void clear_recursive(Node* node) {
        if (node == nullptr) return;

        clear_recursive(node->left);
        clear_recursive(node->right);
        delete node;
    }

    int height_recursive(Node* node) const {
        if (node == nullptr) return 0;

        int leftHeight = height_recursive(node->left);
        int rightHeight = height_recursive(node->right);

        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }

    Node* copy_recursive(Node* node) {
        if (node == nullptr) return nullptr;

        Node* copy = new Node(node->data);
        copy->left = copy_recursive(node->left);
        copy->right = copy_recursive(node->right);

        return copy;
    }

    void inorder_recursive(Node* node) const {
        if (node == nullptr) return;

        inorder_recursive(node->left);
        std::cout << node->data << " ";
        inorder_recursive(node->right);
    }

    void preorder_recursive(Node* node) const {
        if (node == nullptr) return;

        std::cout << node->data << " ";
        preorder_recursive(node->left);
        preorder_recursive(node->right);
    }

    void postorder_recursive(Node* node) const {
        if (node == nullptr) return;

        postorder_recursive(node->left);
        postorder_recursive(node->right);
        std::cout << node->data << " ";
    }

public:
    BinarySearchTree() : _root(nullptr), _size(0) {}

    ~BinarySearchTree() {
        clear();
    }

    BinarySearchTree(const BinarySearchTree& other)
        : _root(nullptr), _size(other._size) {
        _root = copy_recursive(other._root);
    }

    BinarySearchTree& operator=(const BinarySearchTree& other) {
        if (this != &other) {
            clear();
            _root = copy_recursive(other._root);
            _size = other._size;
        }

        return *this;
    }

    void insert(const T& value) {
        _root = insert_recursive(_root, value);
    }

    void remove(const T& value) {
        _root = remove_recursive(_root, value);
    }

    bool find(const T& value) const {
        return find_recursive(_root, value) != nullptr;
    }

    void inorder() const {
        inorder_recursive(_root);
        std::cout << std::endl;
    }

    void preorder() const {
        preorder_recursive(_root);
        std::cout << std::endl;
    }

    void postorder() const {
        postorder_recursive(_root);
        std::cout << std::endl;
    }

    int size() const {
        return _size;
    }

    int height() const {
        return height_recursive(_root);
    }

    void clear() {
        clear_recursive(_root);
        _root = nullptr;
        _size = 0;
    }

    bool is_empty() const {
        return _root == nullptr;
    }
};

#endif

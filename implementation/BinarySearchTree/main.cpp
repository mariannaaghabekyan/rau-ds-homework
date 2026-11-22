
#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>
#include <sstream>

void test_insert() {
    BinarySearchTree<int> bst;

    assert(bst.is_empty());

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    assert(bst.size() == 5);
    assert(!bst.is_empty());
    assert(bst.find(50));
    assert(bst.find(30));
    assert(bst.find(70));
    assert(!bst.find(100));

    bst.insert(50);
    assert(bst.size() == 5);

    std::cout << "test_insert passed" << std::endl;
}

void test_remove() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    bst.remove(20);
    assert(!bst.find(20));
    assert(bst.size() == 4);

    bst.remove(30);
    assert(!bst.find(30));
    assert(bst.size() == 3);

    bst.remove(50);
    assert(!bst.find(50));
    assert(bst.size() == 2);

    bst.remove(100);
    assert(bst.size() == 2);

    std::cout << "test_remove passed" << std::endl;
}

void test_find() {
    BinarySearchTree<int> bst;

    assert(!bst.find(10));

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);

    assert(bst.find(10));
    assert(bst.find(5));
    assert(bst.find(15));
    assert(!bst.find(20));

    std::cout << "test_find passed" << std::endl;
}

void test_traversals() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    std::cout << "Inorder: ";
    bst.inorder();

    std::cout << "Preorder: ";
    bst.preorder();

    std::cout << "Postorder: ";
    bst.postorder();

    std::cout << "test_traversals passed" << std::endl;
}

void test_size_height() {
    BinarySearchTree<int> bst;

    assert(bst.size() == 0);
    assert(bst.height() == 0);

    bst.insert(50);
    assert(bst.size() == 1);
    assert(bst.height() == 1);

    bst.insert(30);
    bst.insert(70);
    bst.insert(20);

    assert(bst.size() == 4);
    assert(bst.height() == 3);

    std::cout << "test_size_height passed" << std::endl;
}

void test_copy_constructor() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    BinarySearchTree<int> copy(bst);

    assert(copy.size() == 3);
    assert(copy.find(50));
    assert(copy.find(30));
    assert(copy.find(70));

    copy.insert(100);
    assert(!bst.find(100));

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment() {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);

    BinarySearchTree<int> copy;
    copy.insert(100);

    copy = bst;

    assert(copy.size() == 2);
    assert(copy.find(10));
    assert(copy.find(5));
    assert(!copy.find(100));

    copy = copy;
    assert(copy.size() == 2);

    std::cout << "test_assignment passed" << std::endl;
}

void test_clear() {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);

    bst.clear();

    assert(bst.is_empty());
    assert(bst.size() == 0);
    assert(bst.height() == 0);
    assert(!bst.find(10));

    std::cout << "test_clear passed" << std::endl;
}

int main() {
    std::cout << "Running BinarySearchTree tests" << std::endl;

    test_insert();
    test_remove();
    test_find();
    test_traversals();
    test_size_height();
    test_copy_constructor();
    test_assignment();
    test_clear();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

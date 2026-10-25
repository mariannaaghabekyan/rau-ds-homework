#include "Stack.h"
#include <cassert>
#include <iostream>

void test_push() {
    Stack<int> s;
    
    s.push(5);
    assert(s.size() == 1);
    assert(s.top() == 5);
    
    s.push(10);
    s.push(15);
    assert(s.size() == 3);
    assert(s.top() == 15);
    
    std::cout << "test_push passed" << std::endl;
}

void test_pop() {
    Stack<int> s;

    s.push(5);
    s.push(10);
    s.push(15);

    s.pop();
    assert(s.size() == 2);
    assert(s.top() == 10);

    s.pop();
    assert(s.top() == 5);

    s.pop();
    assert(s.is_empty());

    std::cout << "test_pop passed" << std::endl;
}

void test_size_and_empty() {
    Stack<int> s;

    assert(s.size() == 0);
    assert(s.is_empty());

    s.push(42);

    assert(s.size() == 1);
    assert(!s.is_empty());

    std::cout << "test_size_and_empty passed" << std::endl;
}

void test_copy_and_clear() {
    Stack<int> s1;
    s1.push(5);
    s1.push(10);

    Stack<int> s2 = s1;
    assert(s2.size() == 2);
    assert(s2.top() == 10);

    s2.pop();
    assert(s2.top() == 5);
    assert(s1.top() == 10);

    Stack<int> s3;
    s3.push(99);
    s3 = s1;
    assert(s3.size() == 2);
    assert(s3.top() == 10);

    s3.clear();
    assert(s3.is_empty());
    assert(s3.size() == 0);

    std::cout << "test_copy_and_clear passed" << std::endl;
}

void test_peek_and_capacity() {
    Stack<int> s;

    assert(s.capacity() >= 1);
    s.push(7);
    s.push(14);

    assert(s.peek() == 14);
    assert(s.top() == 14);
    assert(s.size() == 2);

    s.peek() = 20;
    assert(s.top() == 20);

    std::cout << "test_peek_and_capacity passed" << std::endl;
}

int main() {
    std::cout << "Running Stack tests" << std::endl;
    test_push();
    test_pop();
    test_size_and_empty();
    test_copy_and_clear();
    test_peek_and_capacity();
    std::cout << "All tests passed" << std::endl;
    return 0;
}

#include "ForwardList.h"
#include <cassert>
#include <iostream>
#include <stdexcept>
 
void test_constructor_and_empty(){
ForwardList<int> list;
    assert(list.empty());
    assert(list.size() == 0);
    assert(list.begin() == nullptr);
    std::cout << "test_constructor_and_empty passed\n";
}

void test_push_front() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    assert(list.size() == 3);
    assert(list.front() == 3);
    assert(list.begin()->data == 3);
    std::cout << "test_push_front passed\n";
}
void test_pop_front(){
ForwardList<int> list;
    list.push_front(10);
    list.push_front(20);

    list.pop_front();
    assert(list.front() == 10);
    assert(list.size() == 1);

    list.pop_front();
    assert(list.empty());

    bool threw = false;
    try {
        list.pop_front();
    } catch (const std::out_of_range&) {
        threw = true;
    }
    assert(threw);
    std::cout << "test_pop_front passed\n";
}
void test_front() {
    ForwardList<int> list;
    bool threw = false;

    try {
        list.front();
    } catch (const std::out_of_range&) {
        threw = true;
    }
    assert(threw);

    list.push_front(42);
    assert(list.front() == 42);
    list.front() = 50;
    assert(list.front() == 50);

    const ForwardList<int>& const_list = list;
    assert(const_list.front() == 50);
    std::cout << "test_front passed\n";
}

void test_insert_after() {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(1);

    list.insert_after(list.begin(), 2);
    assert(list.size() == 3);
    assert(list.begin()->data == 1);
    assert(list.begin()->next->data == 2);
    assert(list.begin()->next->next->data == 3);

    list.insert_after(nullptr, 99);
    assert(list.size() == 3);
    std::cout << "test_insert_after passed\n";
}

void test_erase_after() {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    list.erase_after(list.begin());
    assert(list.size() == 2);
    assert(list.begin()->next->data == 3);

    list.erase_after(nullptr);
    assert(list.size() == 2);

    list.erase_after(list.begin()->next);
    assert(list.size() == 2); 

    std::cout << "test_erase_after passed\n";
}

void test_clear() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);

    list.clear();
    assert(list.empty());
    assert(list.size() == 0);
    assert(list.begin() == nullptr);
    list.clear(); 
    assert(list.empty());
    std::cout << "test_clear passed\n";
}
void test_reverse() {
    ForwardList<int> list;
    list.reverse(); 
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.reverse();

    assert(list.front() == 3);
    assert(list.begin()->next->data == 2);
    assert(list.begin()->next->next->data == 1);

    list.reverse();
    assert(list.front() == 1);
    std::cout << "test_reverse passed\n";
}

void test_size_empty_begin() {
    ForwardList<int> list;
    assert(list.size() == 0);
    assert(list.empty());
    assert(list.begin() == nullptr);

    list.push_front(7);
    assert(list.size() == 1);
    assert(!list.empty());
    assert(list.begin()->data == 7);

    std::cout << "test_size_empty_begin passed\n";
}

void test_copy_constructor() {
    ForwardList<int> original;
    original.push_front(3);
    original.push_front(2);
    original.push_front(1);

    ForwardList<int> copy(original);
    assert(copy.size() == 3);
    assert(copy.front() == 1);
    assert(copy.begin()->next->data == 2);

    copy.front() = 100;
    assert(original.front() == 1);

    ForwardList<int> empty;
   ForwardList<int> empty_copy(empty);
    assert(empty_copy.empty());

    std::cout << "test_copy_constructor passed\n";
}

void test_assignment() {
    ForwardList<int> original;
    original.push_front(2);
    original.push_front(1);
    ForwardList<int> assigned;
    assigned.push_front(99);
    assigned = original;
    assert(assigned.size() == 2);
    assert(assigned.front() == 1);
    assert(assigned.begin()->next->data == 2);

    assigned.front() = 50;
    assert(original.front() == 1);

    assigned = assigned;
    assert(assigned.front() == 50);

    ForwardList<int> empty;
    assigned = empty;
    assert(assigned.empty());

    std::cout << "test_assignment passed\n";
}
void test_destructor() {
    {
        ForwardList<int> list;
        list.push_front(1);
        list.push_front(2);
    }
    std::cout << "test_destructor passed\n";
}

int main() {
    std::cout << "Running ForwardList tests" << std::endl;
    test_constructor_and_empty();
    test_push_front();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_size_empty_begin();
    test_copy_constructor();
    test_assignment();
    test_destructor();
    std::cout << "All tests passed" << std::endl;
    return 0;
}

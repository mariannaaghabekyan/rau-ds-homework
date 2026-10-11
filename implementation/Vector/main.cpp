#include "Vector.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

void test_constructors() {
    Vector<int> v;
    assert(v.size() == 0);
    assert(v.empty());
    assert(v.capacity() == 0);

    Vector<int> filled(3);
    assert(filled.size() == 3);
    assert(filled[0] == 0);
    assert(filled[1] == 0);
    assert(filled[2] == 0);

    std::cout << "test_constructors passed\n";
}

void test_push_back() {
    Vector<int> v;
    v.push_back(5);
    v.push_back(10);
    v.push_back(15);

    assert(v.size() == 3);
    assert(v[0] == 5);
    assert(v[1] == 10);
    assert(v.back() == 15);
    assert(v.capacity() >= v.size());

    std::cout << "test_push_back passed\n";
}

void test_pop_back() {
    Vector<int> v;
    v.push_back(5);
    v.push_back(10);

    v.pop_back();
    assert(v.size() == 1);
    assert(v.back() == 5);

    v.pop_back();
    assert(v.empty());

    bool threw = false;
    try {
        v.pop_back();
    } catch (const std::out_of_range&) {
        threw = true;
    }
    assert(threw);

    std::cout << "test_pop_back passed\n";
}

void test_access() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    assert(v[0] == 10);
    v[0] = 99;
    assert(v[0] == 99);

    assert(v.at(1) == 20);

    bool threw = false;
    try {
        v.at(2);
    } catch (const std::out_of_range&) {
        threw = true;
    }
    assert(threw);

    std::cout << "test_access passed\n";
}

void test_front_back() {
    Vector<int> v;
    v.push_back(7);
    v.push_back(14);

    assert(v.front() == 7);
    assert(v.back() == 14);

    v.front() = 3;
    v.back() = 21;
    assert(v[0] == 3);
    assert(v[1] == 21);

    Vector<int> empty;
    bool front_threw = false;
    bool back_threw = false;

    try {
        empty.front();
    } catch (const std::out_of_range&) {
        front_threw = true;
    }

    try {
        empty.back();
    } catch (const std::out_of_range&) {
        back_threw = true;
    }

    assert(front_threw);
    assert(back_threw);

    std::cout << "test_front_back passed\n";
}

void test_copy_and_assignment() {
    Vector<int> original;
    original.push_back(4);
    original.push_back(8);

    Vector<int> copied(original);
    assert(copied.size() == 2);
    assert(copied[0] == 4);
    assert(copied[1] == 8);

    copied[0] = 100;
    assert(original[0] == 4);

    Vector<int> assigned;
    assigned.push_back(99);
    assigned = original;

    assert(assigned.size() == 2);
    assert(assigned[0] == 4);
    assert(assigned[1] == 8);

    assigned = assigned;
    assert(assigned.size() == 2);
    assert(assigned[0] == 4);

    std::cout << "test_copy_and_assignment passed\n";
}

void test_reserve_clear_iterators() {
    Vector<int> v;
    v.reserve(10);

    assert(v.capacity() >= 10);
    assert(v.size() == 0);

    v.push_back(11);
    v.push_back(22);

    assert(v.size() == 2);
    assert(*v.begin() == 11);
    assert(*(v.end() - 1) == 22);
    assert(v.end() - v.begin() == 2);

    v.clear();
    assert(v.empty());
    assert(v.size() == 0);
    assert(v.capacity() >= 10);

    v.push_back(33);
    assert(v.front() == 33);

    std::cout << "test_reserve_clear_iterators passed\n";
}

int main() {
    std::cout << "Running Vector tests\n";

    test_constructors();
    test_push_back();
    test_pop_back();
    test_access();
    test_front_back();
    test_copy_and_assignment();
    test_reserve_clear_iterators();

    std::cout << "All tests passed\n";
    return 0;
}

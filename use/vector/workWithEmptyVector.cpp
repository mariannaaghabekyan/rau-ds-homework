#include <iostream>
#include <vector>
#include <cassert>

void workWithEmptyVector() {
    std::vector<int> vec;

    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i);

        std::cout << "After push_back(" << i << "): "
                  << "size = " << vec.size()
                  << ", capacity = " << vec.capacity()
                  << '\n';
    }

    std::cout << "Elements: ";

    for (int x : vec) {
        std::cout << x << ' ';
    }

    std::cout << '\n';
}

void test_workWithEmptyVector() {
    std::vector<int> vec;

   
    assert(vec.empty());
    assert(vec.size() == 0);

   
    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i);

        assert(vec.size() == static_cast<std::size_t>(i));
        assert(vec.back() == i);
    }

 
    assert(vec.size() == 10);

    
    for (int i = 0; i < 10; ++i) {
        assert(vec[i] == i + 1);
    }

    assert(!vec.empty());
    assert(vec.capacity() >= vec.size());

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    workWithEmptyVector();

    test_workWithEmptyVector();

    return 0;
}
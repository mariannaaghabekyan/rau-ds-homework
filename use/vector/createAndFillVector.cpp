#include <iostream>
#include <vector>
#include <cassert>

void createAndFillVector(int N) {
    std::vector<int> vec(N);

    for (int i = 0; i < N; ++i) {
        vec[i] = i + 1;
    }

    std::cout << "Elements: ";

    for (int x : vec) {
        std::cout << x << ' ';
    }

    std::cout << '\n';
    std::cout << "Size: " << vec.size() << '\n';
    std::cout << "Capacity: " << vec.capacity() << '\n';
}

void test_createAndFillVector() {
    int N = 5;
    std::vector<int> vec(N);

    assert(vec.size() == 5);
    assert(vec.capacity() >= vec.size());

    
    std::vector<int> single(1);
    single[0] = 1;

    assert(single.size() == 1);
    assert(single[0] == 1);

   
    std::vector<int> empty(0);

    assert(empty.empty());
    assert(empty.size() == 0);

    
    std::vector<int> testVec(5);

    for (int i = 0; i < 5; ++i) {
        testVec[i] = i + 1;
    }

    for (int i = 0; i < 5; ++i) {
        assert(testVec[i] == i + 1);
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    createAndFillVector(5);

    test_createAndFillVector();

    return 0;
}
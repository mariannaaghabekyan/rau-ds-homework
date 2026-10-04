#include <iostream>
#include <vector>
#include <cassert>
#include <string>

template <typename T>
void resizeVector(std::vector<T>& vec, std::size_t newSize, const T& defaultValue) {
    std::cout << "Before: ";

    for (const T& x : vec) {
        std::cout << x << ' ';
    }

    std::cout << '\n';

    vec.resize(newSize, defaultValue);

    std::cout << "After: ";

    for (const T& x : vec) {
        std::cout << x << ' ';
    }

    std::cout << '\n';
}

void test_resizeVector() {
    std::vector<int> vec = {1, 2, 3};

    resizeVector(vec, 5, 42);

    assert(vec.size() == 5);
    assert(vec[0] == 1);
    assert(vec[1] == 2);
    assert(vec[2] == 3);
    assert(vec[3] == 42);
    assert(vec[4] == 42);

    std::vector<int> smaller = {1, 2, 3, 4, 5};

    resizeVector(smaller, 3, 99);

    assert(smaller.size() == 3);
    assert(smaller[0] == 1);
    assert(smaller[1] == 2);
    assert(smaller[2] == 3);

    std::vector<double> doubles = {1.5, 2.5};

    resizeVector(doubles, 4, 3.14);

    assert(doubles.size() == 4);
    assert(doubles[0] == 1.5);
    assert(doubles[1] == 2.5);
    assert(doubles[2] == 3.14);
    assert(doubles[3] == 3.14);

    std::vector<std::string> words = {"hello"};

    resizeVector(words, 3, std::string("default"));

    assert(words.size() == 3);
    assert(words[0] == "hello");
    assert(words[1] == "default");
    assert(words[2] == "default");

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    std::vector<int> v = {1, 2, 3};

    resizeVector(v, 5, 42);

    test_resizeVector();

    return 0;
}
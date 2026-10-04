#include <iostream>
#include <vector>
#include <string>
#include <cassert>

template <typename T>
int linearSearch(const std::vector<T>& vec, const T& target) {
    for (std::size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return static_cast<int>(i);
        }
    }

    return -1;
}

void test_linearSearch() {
    std::vector<int> intVec = {10, 20, 30, 20, 40};

    assert(linearSearch(intVec, 20) == 1);
    assert(linearSearch(intVec, 40) == 4);
    assert(linearSearch(intVec, 99) == -1);

    std::vector<double> doubleVec = {1.1, 2.2, 3.3, 2.2};

    assert(linearSearch(doubleVec, 2.2) == 1);
    assert(linearSearch(doubleVec, 3.3) == 2);
    assert(linearSearch(doubleVec, 5.5) == -1);

    std::vector<std::string> stringVec = {
        "apple", "banana", "apple", "orange"
    };

    assert(linearSearch(stringVec, std::string("apple")) == 0);
    assert(linearSearch(stringVec, std::string("orange")) == 3);
    assert(linearSearch(stringVec, std::string("grape")) == -1);

    std::vector<int> emptyVec;

    assert(linearSearch(emptyVec, 10) == -1);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    std::vector<int> intVec = {10, 20, 30, 20, 40};
    std::cout << "int: " << linearSearch(intVec, 20) << '\n';

    std::vector<double> doubleVec = {1.1, 2.2, 3.3};
    std::cout << "double: " << linearSearch(doubleVec, 3.3) << '\n';

    std::vector<std::string> stringVec = {
        "apple", "banana", "orange"
    };
    std::cout << "string: "
              << linearSearch(stringVec, std::string("banana")) << '\n';

    test_linearSearch();

    return 0;
}
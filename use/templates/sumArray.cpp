#include <iostream>
#include <string>
#include <cassert>

template <typename T>
T sumArray(const T* array, std::size_t size) {
    T sum{};

    for (std::size_t i = 0; i < size; ++i) {
        sum += array[i];
    }

    return sum;
}

void test_sumArray() {
    int intArray[] = {1, 2, 3, 4, 5};

    assert(sumArray(intArray, 5) == 15);

    double doubleArray[] = {1.5, 2.5, 3.0};

    assert(sumArray(doubleArray, 3) == 7.0);

    std::string stringArray[] = {"Hello", " ", "World"};

    assert(sumArray(stringArray, 3) == "Hello World");

    int singleElement[] = {42};

    assert(sumArray(singleElement, 1) == 42);

    int emptyArray[] = {1, 2, 3};

    assert(sumArray(emptyArray, 0) == 0);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};

    std::cout << "int sum: "
              << sumArray(intArray, 5) << '\n';

    double doubleArray[] = {1.5, 2.5, 3.0};

    std::cout << "double sum: "
              << sumArray(doubleArray, 3) << '\n';

    std::string stringArray[] = {"Hello", " ", "World"};

    std::cout << "string sum: "
              << sumArray(stringArray, 3) << '\n';

    test_sumArray();

    return 0;
}
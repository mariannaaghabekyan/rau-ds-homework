#include <iostream>
#include <string>
#include <cassert>

template <typename T>
void printElement(const T& value) {
    std::cout << value << '\n';
}

void test_printElement() {
    int intValue = 42;
    double doubleValue = 3.14;
    std::string stringValue = "Hello";

    assert(intValue == 42);
    assert(doubleValue == 3.14);
    assert(stringValue == "Hello");

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    printElement(42);
    printElement(3.14);
    printElement(std::string("Hello"));

    test_printElement();

    return 0;
}
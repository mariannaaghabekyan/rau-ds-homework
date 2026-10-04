#include <iostream>
#include <cassert>
#include <cstring>
#include <string>

template <typename T>
bool isEqual(const T& first, const T& second) {
    return first == second;
}


template <>
bool isEqual<const char*>(const char* const& first, const char* const& second) {
    return std::strcmp(first, second) == 0;
}

void test_isEqual() {
    assert(isEqual(10, 10));
    assert(!isEqual(10, 20));


    assert(isEqual(3.14, 3.14));
    assert(!isEqual(3.14, 2.71));

    std::string first = "Hello";
    std::string second = "Hello";
    std::string third = "World";

    assert(isEqual(first, second));
    assert(!isEqual(first, third));

    const char* text1 = "Hello";
    const char* text2 = "Hello";
    const char* text3 = "World";

    assert(isEqual(text1, text2));
    assert(!isEqual(text1, text3));

    char firstText[] = "Hello";
    char secondText[] = "Hello";

    const char* firstPtr = firstText;
    const char* secondPtr = secondText;

    assert(firstPtr != secondPtr);
    assert(isEqual(firstPtr, secondPtr));

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    std::cout << "10 == 10: "
              << (isEqual(10, 10) ? "true" : "false") << '\n';

    std::cout << "10 == 20: "
              << (isEqual(10, 20) ? "true" : "false") << '\n';

    const char* first = "Hello";
    const char* second = "Hello";
    const char* third = "World";

    std::cout << "\"Hello\" == \"Hello\": "
              << (isEqual(first, second) ? "true" : "false") << '\n';

    std::cout << "\"Hello\" == \"World\": "
              << (isEqual(first, third) ? "true" : "false") << '\n';

    test_isEqual();

    return 0;
}
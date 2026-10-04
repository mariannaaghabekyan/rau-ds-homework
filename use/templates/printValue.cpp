#include <iostream>
#include <cassert>
#include <sstream>

template <typename T>
void printValue(const T& value) {
    std::cout << value << '\n';
}

template <>
void printValue<bool>(const bool& value) {
    std::cout << (value ? "true" : "false") << '\n';
}


template <>
void printValue<char*>(char* const& value) {
    std::cout << '"' << value << '"' << '\n';
}

template <std::size_t N>
void printValue(const char (&value)[N]) {
    std::cout << '"' << value << '"' << '\n';
}

void test_printValue() {
    std::ostringstream output;

    std::streambuf* oldBuffer = std::cout.rdbuf(output.rdbuf());

    printValue(42);
    assert(output.str() == "42\n");

    output.str("");
    output.clear();


    printValue(true);
    assert(output.str() == "true\n");

    output.str("");
    output.clear();

    printValue(false);
    assert(output.str() == "false\n");

    output.str("");
    output.clear();


    char* text = const_cast<char*>("Hello");
    printValue(text);
    assert(output.str() == "\"Hello\"\n");

    output.str("");
    output.clear();

    char word[] = "World";
    printValue(word);
    assert(output.str() == "\"World\"\n");

    std::cout.rdbuf(oldBuffer);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    int number = 42;
    bool isReady = true;
    char text[] = "Hello";

    std::cout << "Integer: ";
    printValue(number);

    std::cout << "Boolean: ";
    printValue(isReady);

    std::cout << "String: ";
    printValue(text);

    test_printValue();

    return 0;
}
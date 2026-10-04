#include <iostream>
#include <string>
#include <cassert>

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void test_mySwap() {
    int a = 10;
    int b = 20;

    mySwap(a, b);

    assert(a == 20);
    assert(b == 10);

    double x = 1.5;
    double y = 3.14;

    mySwap(x, y);

    assert(x == 3.14);
    assert(y == 1.5);

    std::string first = "Hello";
    std::string second = "World";

    mySwap(first, second);

    assert(first == "World");
    assert(second == "Hello");

    int same1 = 42;
    int same2 = 42;

    mySwap(same1, same2);

    assert(same1 == 42);
    assert(same2 == 42);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    int a = 10;
    int b = 20;

    mySwap(a, b);

    std::cout << "int: " << a << ' ' << b << '\n';

    double x = 1.5;
    double y = 3.14;

    mySwap(x, y);

    std::cout << "double: " << x << ' ' << y << '\n';

    std::string first = "Hello";
    std::string second = "World";

    mySwap(first, second);

    std::cout << "string: " << first << ' ' << second << '\n';

    test_mySwap();

    return 0;
}
#include <iostream>
#include <string>
#include <cassert>

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(const T1& firstValue, const T2& secondValue)
        : first(firstValue), second(secondValue) {}

    void print() const {
        std::cout << first << ' ' << second << '\n';
    }

    const T1& getFirst() const {
        return first;
    }

    const T2& getSecond() const {
        return second;
    }
};

void test_Pair() {
    Pair<int, double> numbers(10, 3.14);

    assert(numbers.getFirst() == 10);
    assert(numbers.getSecond() == 3.14);

    Pair<std::string, int> person("Marianna", 20);

    assert(person.getFirst() == "Marianna");
    assert(person.getSecond() == 20);

    Pair<std::string, std::string> words("Hello", "World");

    assert(words.getFirst() == "Hello");
    assert(words.getSecond() == "World");

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    Pair<int, double> numbers(10, 3.14);
    std::cout << "Numbers: ";
    numbers.print();

    Pair<std::string, int> person("Marianna", 20);
    std::cout << "Person: ";
    person.print();

    Pair<std::string, std::string> words("Hello", "World");
    std::cout << "Words: ";
    words.print();

    test_Pair();

    return 0;
}
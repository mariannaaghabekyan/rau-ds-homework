#include <iostream>
#include <cassert>

template <typename T>
class Range {
private:
    T start;
    T end;

public:
    Range(T startValue, T endValue)
        : start(startValue), end(endValue) {}

    bool contains(const T& value) const {
        return value >= start && value <= end;
    }

    auto length() const {
    return end - start;
}

    void print() const {
        std::cout << '[' << start << ", " << end << ']' << '\n';
    }
};

void test_Range() {
    Range<int> numbers(3, 10);

    assert(numbers.contains(3));
    assert(numbers.contains(7));
    assert(numbers.contains(10));

    assert(!numbers.contains(2));
    assert(!numbers.contains(11));

    assert(numbers.length() == 7);

   
    Range<double> decimals(1.5, 5.5);

    assert(decimals.contains(1.5));
    assert(decimals.contains(3.5));
    assert(decimals.contains(5.5));

    assert(!decimals.contains(1.4));
    assert(!decimals.contains(5.6));

    assert(decimals.length() == 4.0);

   
    Range<char> letters('a', 'f');

    assert(letters.contains('a'));
    assert(letters.contains('c'));
    assert(letters.contains('f'));

    assert(!letters.contains('A'));
    assert(!letters.contains('g'));

    assert(letters.length() == 5);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    Range<int> numbers(3, 10);

    std::cout << "Integer range: ";
    numbers.print();

    std::cout << "Contains 7: "
              << (numbers.contains(7) ? "yes" : "no") << '\n';

    std::cout << "Length: " << numbers.length() << '\n';

    Range<double> decimals(1.5, 5.5);

    std::cout << "Double range: ";
    decimals.print();

    std::cout << "Contains 3.5: "
              << (decimals.contains(3.5) ? "yes" : "no") << '\n';

    std::cout << "Length: " << decimals.length() << '\n';

    Range<char> letters('a', 'f');

    std::cout << "Char range: ";
    letters.print();

    std::cout << "Contains 'c': "
              << (letters.contains('c') ? "yes" : "no") << '\n';

    std::cout << "Length: " << letters.length() << '\n';

    test_Range();

    return 0;
}
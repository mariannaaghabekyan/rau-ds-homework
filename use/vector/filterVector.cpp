#include <iostream>
#include <vector>
#include <cassert>
#include <string>

template <typename T, typename Predicate>
std::vector<T> filterVector(const std::vector<T>& vec, Predicate predicate) {
    std::vector<T> filtered;

    for (const T& value : vec) {
        if (predicate(value)) {
            filtered.push_back(value);
        }
    }

    return filtered;
}

bool isEven(int x) {
    return x % 2 == 0;
}

bool isPositive(double x) {
    return x > 0;
}

bool isLongWord(const std::string& word) {
    return word.length() > 4;
}

void test_filterVector() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};

    std::vector<int> evenNumbers = filterVector(numbers, isEven);

    std::vector<int> expectedEven = {2, 4, 6};

    assert(evenNumbers == expectedEven);

    std::vector<int> noMatch = {1, 3, 5, 7};

    std::vector<int> filteredNoMatch = filterVector(noMatch, isEven);

    assert(filteredNoMatch.empty());

    std::vector<int> allMatch = {2, 4, 6, 8};

    std::vector<int> filteredAll = filterVector(allMatch, isEven);

    assert(filteredAll == allMatch);

    std::vector<int> empty;

    std::vector<int> filteredEmpty = filterVector(empty, isEven);

    assert(filteredEmpty.empty());

    std::vector<double> decimals = {-2.5, 1.5, 3.0, -4.0};

    std::vector<double> positive = filterVector(decimals, isPositive);

    std::vector<double> expectedPositive = {1.5, 3.0};

    assert(positive == expectedPositive);

    std::vector<std::string> words = {
        "cat",
        "hello",
        "world",
        "hi",
        "programming"
    };

    std::vector<std::string> longWords =
        filterVector(words, isLongWord);

    std::vector<std::string> expectedLongWords = {
        "hello",
        "world",
        "programming"
    };

    assert(longWords == expectedLongWords);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    std::vector<int> filtered = filterVector(vec, isEven);

    std::cout << "Filtered: ";

    for (int x : filtered) {
        std::cout << x << ' ';
    }

    std::cout << '\n';

    test_filterVector();

    return 0;
}
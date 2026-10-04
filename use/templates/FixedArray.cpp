#include <iostream>
#include <cassert>
#include <string>

template <typename T, std::size_t N>
class FixedArray {
private:
    T data[N];

public:
    void set(int index, T value) {
        data[index] = value;
    }

    T get(int index) const {
        return data[index];
    }

    std::size_t size() const {
        return N;
    }
};

void test_FixedArray() {
  
    FixedArray<int, 5> numbers;

    assert(numbers.size() == 5);

    numbers.set(0, 10);
    numbers.set(2, 42);
    numbers.set(4, 99);

    assert(numbers.get(0) == 10);
    assert(numbers.get(2) == 42);
    assert(numbers.get(4) == 99);

    
    FixedArray<double, 3> decimals;

    decimals.set(0, 1.5);
    decimals.set(1, 2.5);
    decimals.set(2, 3.5);

    assert(decimals.get(0) == 1.5);
    assert(decimals.get(1) == 2.5);
    assert(decimals.get(2) == 3.5);

   
    FixedArray<std::string, 2> words;

    words.set(0, "Hello");
    words.set(1, "World");

    assert(words.get(0) == "Hello");
    assert(words.get(1) == "World");


    std::cout << "All tests passed!" << std::endl;
}

int main() {
    FixedArray<int, 5> numbers;

    numbers.set(0, 10);
    numbers.set(1, 20);
    numbers.set(2, 30);

    std::cout << "First: " << numbers.get(0) << '\n';
    std::cout << "Second: " << numbers.get(1) << '\n';
    std::cout << "Third: " << numbers.get(2) << '\n';
    std::cout << "Size: " << numbers.size() << '\n';

    test_FixedArray();

    return 0;
}
#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createVectorFromInput() {
    std::vector<int> vec;
    int number;

    while (std::cin >> number && number != 0) {
        vec.push_back(number);
    }

    return vec;
}

void test_createVectorFromInput() {
    std::vector<int> testVec;

    testVec.push_back(7);
    testVec.push_back(8);
    testVec.push_back(9);

    assert(testVec.size() == 3);
    assert(testVec[0] == 7);
    assert(testVec[1] == 8);
    assert(testVec[2] == 9);

    std::vector<int> emptyVec;

    assert(emptyVec.empty());
    assert(emptyVec.size() == 0);

    std::vector<int> singleVec;
    singleVec.push_back(42);

    assert(singleVec.size() == 1);
    assert(singleVec[0] == 42);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    std::cout << "Enter numbers (0 to stop): ";

    std::vector<int> inputVec = createVectorFromInput();

    std::cout << "Size: " << inputVec.size() << '\n';

    std::cout << "Elements: ";

    for (int x : inputVec) {
        std::cout << x << ' ';
    }

    std::cout << '\n';

    test_createVectorFromInput();

    return 0;
}
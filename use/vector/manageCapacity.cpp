#include <iostream>
#include <vector>
#include <cassert>

void manageCapacity(std::vector<int>& vec) {
    std::cout << "Initial size: " << vec.size() << '\n';
    std::cout << "Initial capacity: " << vec.capacity() << '\n';

    std::size_t oldSize = vec.size();

    vec.reserve(oldSize + 500);

    std::cout << "Capacity after reserve: " << vec.capacity() << '\n';

    for (int i = 1; i <= 500; ++i) {
        vec.push_back(i);
    }

    std::cout << "Final size: " << vec.size() << '\n';
    std::cout << "Final capacity: " << vec.capacity() << '\n';
}

void test_manageCapacity() {
    std::vector<int> vec;

    manageCapacity(vec);

    assert(vec.size() == 500);
    assert(vec.capacity() >= 500);

    for (int i = 0; i < 500; ++i) {
        assert(vec[i] == i + 1);
    }

    std::vector<int> existingVec = {10, 20, 30};

    manageCapacity(existingVec);

    assert(existingVec.size() == 503);

    assert(existingVec[0] == 10);
    assert(existingVec[1] == 20);
    assert(existingVec[2] == 30);

    assert(existingVec[3] == 1);
    assert(existingVec[502] == 500);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    std::vector<int> vec;

    manageCapacity(vec);

    test_manageCapacity();

    return 0;
}
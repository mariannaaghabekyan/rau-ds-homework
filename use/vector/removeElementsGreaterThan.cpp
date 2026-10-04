#include <iostream>
#include <vector>
#include <cassert>

int removeElementsGreaterThan(std::vector<int>& vec, int threshold) {
    int removed = 0;

    while (!vec.empty() && vec.back() > threshold) {
        vec.pop_back();
        ++removed;
    }

    return removed;
}

void test_removeElementsGreaterThan() {
    std::vector<int> vec = {1, 3, 5, 7, 9};

    int removed = removeElementsGreaterThan(vec, 5);

    assert(removed == 2);
    assert(vec.size() == 3);
    assert(vec[0] == 1);
    assert(vec[1] == 3);
    assert(vec[2] == 5);

    std::vector<int> noRemoval = {1, 2, 3, 4, 5};

    removed = removeElementsGreaterThan(noRemoval, 5);

    assert(removed == 0);
    assert(noRemoval.size() == 5);

    std::vector<int> allRemoval = {6, 7, 8};

    removed = removeElementsGreaterThan(allRemoval, 5);

    assert(removed == 3);
    assert(allRemoval.empty());

    std::vector<int> emptyVec;

    removed = removeElementsGreaterThan(emptyVec, 5);

    assert(removed == 0);
    assert(emptyVec.empty());

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    std::vector<int> v = {1, 3, 5, 7, 9};

    int removed = removeElementsGreaterThan(v, 5);

    std::cout << "Removed: " << removed << '\n';

    std::cout << "Elements: ";

    for (int x : v) {
        std::cout << x << ' ';
    }

    std::cout << '\n';

    test_removeElementsGreaterThan();

    return 0;
}
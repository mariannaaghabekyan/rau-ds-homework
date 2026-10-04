

#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> mergeSortedVectors(const std::vector<int>& vec1,
                                    const std::vector<int>& vec2) {
    std::vector<int> merged;

    std::size_t i = 0;
    std::size_t j = 0;

    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] <= vec2[j]) {
            merged.push_back(vec1[i]);
            ++i;
        } else {
            merged.push_back(vec2[j]);
            ++j;
        }
    }

    while (i < vec1.size()) {
        merged.push_back(vec1[i]);
        ++i;
    }

    while (j < vec2.size()) {
        merged.push_back(vec2[j]);
        ++j;
    }

    return merged;
}

void test_mergeSortedVectors() {
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8, 9};

    std::vector<int> merged = mergeSortedVectors(vec1, vec2);

    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    assert(merged == expected);

    std::vector<int> empty;
    std::vector<int> numbers = {1, 2, 3};

    merged = mergeSortedVectors(empty, numbers);
    assert(merged == numbers);

    merged = mergeSortedVectors(numbers, empty);
    assert(merged == numbers);

    std::vector<int> duplicates1 = {1, 2, 2, 5};
    std::vector<int> duplicates2 = {2, 3, 5};

    merged = mergeSortedVectors(duplicates1, duplicates2);

    std::vector<int> expectedDuplicates = {1, 2, 2, 2, 3, 5, 5};

    assert(merged == expectedDuplicates);

    std::vector<int> single1 = {10};
    std::vector<int> single2 = {20};

    merged = mergeSortedVectors(single1, single2);

    std::vector<int> expectedSingle = {10, 20};

    assert(merged == expectedSingle);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8, 9};

    std::vector<int> merged = mergeSortedVectors(vec1, vec2);

    std::cout << "Merged: ";

    for (int x : merged) {
        std::cout << x << ' ';
    }

    std::cout << '\n';

    test_mergeSortedVectors();

    return 0;
}

#include <iostream>
#include <vector>
#include <cassert>

int findSubsequence(const std::vector<int>& mainVec,
                    const std::vector<int>& subVec) {
    if (subVec.empty()) {
        return 0;
    }

    if (subVec.size() > mainVec.size()) {
        return -1;
    }

    for (std::size_t i = 0; i <= mainVec.size() - subVec.size(); ++i) {
        bool found = true;

        for (std::size_t j = 0; j < subVec.size(); ++j) {
            if (mainVec[i + j] != subVec[j]) {
                found = false;
                break;
            }
        }

        if (found) {
            return static_cast<int>(i);
        }
    }

    return -1;
}

void test_findSubsequence() {
    std::vector<int> mainVec = {1, 2, 3, 4, 5, 6};
    std::vector<int> subVec = {3, 4, 5};

    assert(findSubsequence(mainVec, subVec) == 2);

    std::vector<int> beginning = {1, 2, 3};

    assert(findSubsequence(mainVec, beginning) == 0);

    std::vector<int> ending = {4, 5, 6};

    assert(findSubsequence(mainVec, ending) == 3);

    std::vector<int> notFound = {7, 8};

    assert(findSubsequence(mainVec, notFound) == -1);

    std::vector<int> tooLong = {1, 2, 3, 4, 5, 6, 7};

    assert(findSubsequence(mainVec, tooLong) == -1);

    std::vector<int> empty;

    assert(findSubsequence(mainVec, empty) == 0);

    std::vector<int> duplicates = {1, 2, 2, 3, 2, 3};
    std::vector<int> duplicateSub = {2, 3};

    assert(findSubsequence(duplicates, duplicateSub) == 2);

    std::vector<int> single = {5};

    assert(findSubsequence(mainVec, single) == 4);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    std::vector<int> mainVec = {1, 2, 3, 4, 5, 6};
    std::vector<int> subVec = {3, 4, 5};

    int index = findSubsequence(mainVec, subVec);

    std::cout << "Index: " << index << '\n';

    test_findSubsequence();

    return 0;
}
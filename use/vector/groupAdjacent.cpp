#include <iostream>
#include <vector>
#include <cassert>

std::vector<std::vector<int>> groupAdjacent(const std::vector<int>& vec) {
    std::vector<std::vector<int>> groups;

    if (vec.empty()) {
        return groups;
    }

    std::vector<int> currentGroup;

    for (int value : vec) {
        if (currentGroup.empty() || value == currentGroup.back()) {
            currentGroup.push_back(value);
        } else {
            groups.push_back(currentGroup);
            currentGroup.clear();
            currentGroup.push_back(value);
        }
    }

    groups.push_back(currentGroup);

    return groups;
}

void test_groupAdjacent() {
    std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};

    std::vector<std::vector<int>> groups = groupAdjacent(vec);

    std::vector<std::vector<int>> expected = {
        {1, 1},
        {2, 2, 2},
        {3},
        {1, 1}
    };

    assert(groups == expected);

    std::vector<int> empty;

    groups = groupAdjacent(empty);

    assert(groups.empty());

    std::vector<int> single = {5};

    groups = groupAdjacent(single);

    assert(groups.size() == 1);
    assert(groups[0] == std::vector<int>{5});

    std::vector<int> allSame = {7, 7, 7, 7};

    groups = groupAdjacent(allSame);

    assert(groups.size() == 1);
    assert(groups[0] == std::vector<int>({7, 7, 7, 7}));

    std::vector<int> allDifferent = {1, 2, 3, 4};

    groups = groupAdjacent(allDifferent);

    assert(groups.size() == 4);
    assert(groups[0] == std::vector<int>({1}));
    assert(groups[1] == std::vector<int>({2}));
    assert(groups[2] == std::vector<int>({3}));
    assert(groups[3] == std::vector<int>({4}));

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};

    std::vector<std::vector<int>> groups = groupAdjacent(vec);

    std::cout << "Groups: ";

    for (const std::vector<int>& group : groups) {
        std::cout << "{";

        for (int x : group) {
            std::cout << x << ' ';
        }

        std::cout << "} ";
    }

    std::cout << '\n';

    test_groupAdjacent();

    return 0;
}
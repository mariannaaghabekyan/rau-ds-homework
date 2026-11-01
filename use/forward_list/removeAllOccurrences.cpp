#include <iostream>
#include <forward_list>

int removeAllOccurrences(std::forward_list<int>& fl, int value) {
    int count = 0;

    auto prev = fl.before_begin();
    auto current = fl.begin();

    while (current != fl.end()) {
        if (*current == value) {
            current = fl.erase_after(prev);
            ++count;
        } else {
            prev = current;
            ++current;
        }
    }

    return count;
}

int main() {
    std::forward_list<int> fl = {1, 2, 3, 2, 4, 2};

    int removed = removeAllOccurrences(fl, 2);

    for (int x : fl) {
        std::cout << x << ' ';
    }

    std::cout << "\nRemoved: " << removed << '\n';

    return 0;
}
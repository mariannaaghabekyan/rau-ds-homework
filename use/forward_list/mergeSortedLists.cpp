#include <iostream>
#include <forward_list>

void mergeSortedLists(std::forward_list<int>& fl1,
                      std::forward_list<int>& fl2) {
    fl1.merge(fl2);
    fl2.clear();
}

int main() {
    std::forward_list<int> fl1 = {1, 3, 5};
    std::forward_list<int> fl2 = {2, 4, 6};

    mergeSortedLists(fl1, fl2);

    for (int x : fl1) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    std::cout << "Second list empty: " << std::boolalpha << fl2.empty() << '\n';

    return 0;
}
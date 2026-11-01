#include <iostream>
#include <forward_list>

void createAndFillList(int N) {
    std::forward_list<int> flist;

    for (int i = 1; i <= N; ++i) {
        flist.push_front(i);
    }

    for (int x : flist) {
        std::cout << x << ' ';
    }

    std::cout << '\n';
}

int main() {
    createAndFillList(5);
    return 0;
}
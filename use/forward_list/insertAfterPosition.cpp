#include <iostream>
#include <forward_list>

bool insertAfterPosition(std::forward_list<int>& fl, int position, int value) {
    if (position < 0) {
        return false;
    }

    auto it = fl.begin();

    for (int i = 0; i < position; ++i) {
        if (it == fl.end()) {
            return false;
        }
        ++it;
    }

    if (it == fl.end()) {
        return false;
    }

    fl.insert_after(it, value);
    return true;
}

int main() {
    std::forward_list<int> fl = {1, 2, 3, 4};

    if (insertAfterPosition(fl, 1, 99)) {
        for (int x : fl) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
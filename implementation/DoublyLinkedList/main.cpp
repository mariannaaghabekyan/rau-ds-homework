#include "DoublyLinkedList.h"
#include <cassert>
#include <iostream>

// Реализуйте методы DoublyLinkedList<T>:
//   1. DoublyLinkedList()              - конструктор
//   2. ~DoublyLinkedList()             - деструктор
//   3. DoublyLinkedList(const &)       - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push_back(const T&)             - добавить в конец
//   6. push_front(const T&)            - добавить в начало
//   7. pop_back()                      - удалить с конца
//   8. pop_front()                     - удалить с начала
//   9. insert(int, const T&)           - вставить на позицию
//  10. erase(int)                      - удалить с позиции
//  11. front()                         - первый элемент
//  12. back()                          - последний элемент
//  13. clear()                         - очистить
//  14. reverse()                       - развернуть

void test_push_back() {
    DoublyLinkedList<int> list;
    
    list.push_back(10);
    assert(list.size() == 1);
    assert(list.back() == 10);
    
    list.push_back(20);
    list.push_back(30);
    assert(list.size() == 3);
    
    std::cout << "test_push_back passed" << std::endl;
}
void test_erase_node() {
    DoublyLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    auto* middle = list.begin()->next;
    list.erase(middle);

    assert(list.size() == 2);
    assert(list.front() == 10);
    assert(list.back() == 30);

    auto* first = list.begin();
    list.erase(first);

    assert(list.size() == 1);
    assert(list.front() == 30);

    auto* last = list.begin();
    list.erase(last);

    assert(list.empty());

    std::cout << "test_erase_node passed" << std::endl;
}

// void test_push_front() { ... }
// void test_pop_back() { ... }

int main() {
    std::cout << "Running DoublyLinkedList tests" << std::endl;
    test_push_back();
    test_erase_node();
    std::cout << "All tests passed" << std::endl;
    return 0;
}

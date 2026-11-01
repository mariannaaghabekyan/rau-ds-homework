#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
    };
    
    Node* _head;
    Node* _tail;
    int _size;

public:
    /// 1. Конструктор по умолчанию
   DoublyLinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}
    
    /// 2. Деструктор
    ~DoublyLinkedList(){
        clear();
    }
    
    /// 3. Конструктор копирования
    DoublyLinkedList(const DoublyLinkedList& other);
    
    /// 4. Оператор присваивания
    DoublyLinkedList& operator=(const DoublyLinkedList& other);
    
    /// 5. push_back(const T& x) - добавить в конец
    void push_back(const T& x){
    Node* node = new Node(x);

    if (_tail == nullptr) {
        _head = _tail = node;
    } else {
        node->prev = _tail;
        _tail->next = node;
        _tail = node;
    }

    ++_size;
}
    
    /// 6. push_front(const T& x) - добавить в начало
    void push_front(const T& x);
    
    /// 7. pop_back() - удалить с конца
    void pop_back();
    
    /// 8. pop_front() - удалить с начала
    void pop_front();
    
    /// 9. insert(int pos, const T& x) - вставить на позицию
    void insert(int pos, const T& x);
    
    /// 10. erase(int pos) - удалить с позиции
    void erase(int pos);
    void erase(Node* node) {
    if (node == nullptr) {
        return;
    }

    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        _head = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        _tail = node->prev;
    }

    delete node;
    --_size;
}
    
    /// 11. front() - первый элемент
    T& front(){
        return _head->data;
    }
    const T& front() const{
        return _head->data;
    }
    
    /// 12. back() - последний элемент
    T& back() {
    return _tail->data;
}
    const T& back() const{
    return _tail->data;
}
    
    /// 13. clear() - очистить
    void clear(){
    Node* current = _head;

    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

void reverse() {
    Node* current = _head;

    while (current != nullptr) {
        Node* temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp;
    }

    Node* temp = _head;
    _head = _tail;
    _tail = temp;
}
 
    
    int size() const{
        return _size;
    }
    bool empty() const{
        return _size == 0;
    }
    Node* begin() {
    return _head;
}
};

#endif // DOUBLYLINKEDLIST_H

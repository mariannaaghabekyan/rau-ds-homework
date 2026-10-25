#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    T* _data;
    int _capacity;
    int _size;
    
    void expand();

public:
    /// 1. Конструктор по умолчанию
    Stack();
    
    /// 2. Деструктор
    ~Stack();
    
    /// 3. Конструктор копирования
    Stack(const Stack& other);
    
    /// 4. Оператор присваивания
    Stack& operator=(const Stack& other);
    
    /// 5. push(const T& x) - добавить в стек
    void push(const T& x);
    
    /// 6. pop() - удалить с вершины
    void pop();
    
    /// 7. top() - вершина стека
    T& top();
    const T& top() const;
    
    /// 8. size() - количество элементов
    int size() const;
    
    /// 9. capacity() - вместимость
    int capacity() const;
    
    /// 10. is_empty() - пуст ли
    bool is_empty() const;
    
    /// 11. clear() - очистить
    void clear();
    
    /// 12. peek() - посмотреть вершину без удаления
    T& peek();
    const T& peek() const;
};
template <typename T>
Stack<T>::Stack(){
    _capacity = 2;
    _size = 0;
    _data = new T[_capacity];
}

template<typename T>
Stack<T>::~Stack(){
    delete[] _data;
}

template <typename T>
void Stack<T>::expand(){
    _capacity *= 2;

    T* newData = new T[_capacity];
    for(int i = 0; i< _size; ++i){
        newData[i] = _data[i];
    }
    delete[] _data;
    _data = newData;
}

template <typename T>
void Stack<T>::push(const T& x){
    if(_size == _capacity){
       expand();
    }
    _data[_size] = x;
    ++_size;
}

template <typename T>
void Stack<T>::pop(){
    if(_size > 0){
        --_size;
    }
}

template <typename T>
T& Stack<T>::top() {
    return _data[_size - 1];
}

template <typename T>
const T& Stack<T>::top() const {
    return _data[_size - 1];
}

template <typename T>
int Stack<T>::size() const {
    return _size;
}

template <typename T>
int Stack<T>::capacity() const {
    return _capacity;
}

template <typename T>
bool Stack<T>::is_empty() const {
    return _size == 0;
}

template <typename T>
void Stack<T>::clear() {
    _size = 0;
}

template <typename T>
T& Stack<T>::peek() {
    return _data[_size - 1];
}

template <typename T>
const T& Stack<T>::peek() const {
    return _data[_size - 1];
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
    _capacity = other._capacity;
    _size = other._size;
    _data = new T[_capacity];

    for (int i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if (this == &other) {
        return *this;
    }

    T* newData = new T[other._capacity];

    for (int i = 0; i < other._size; ++i) {
        newData[i] = other._data[i];
    }

    delete[] _data;

    _data = newData;
    _size = other._size;
    _capacity = other._capacity;

    return *this;
}

#endif 


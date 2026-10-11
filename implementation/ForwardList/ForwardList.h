#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <stdexcept>

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };
    
    Node* _head;
    int _size;

public:
    ForwardList() : _head(nullptr), _size(0){}
    
    ~ForwardList() {
       clear();
}
    ForwardList(const ForwardList& other)
         : _head(nullptr), _size(0) {
           Node* current = other._head;

           while (current != nullptr){
               push_back_copy(current->data);
               current = current->next;
}
}
    ForwardList& operator=(const ForwardList& other){
     if(this == &other){
       return *this;
}

      ForwardList temp(other);
      
     Node* old_head = _head;
     _head = temp._head;
     _size = temp._size;
     
    temp._head = old_head;
    temp._size = 0;
    
    return *this;
}
    void push_front(const T& x) {
     Node* node = new Node(x);
     node->next = _head;
     _head = node;
     ++_size;
}
    void pop_front() {
       if(_head == nullptr){
          throw std::out_of_range("ForwardList is empty");
         }

         Node* old_head = _head;
         _head = _head->next;
         delete old_head;
         --_size;
}
    T& front(){
      if(_head == nullptr){
         throw std::out_of_range("ForwardList is empty");
}
     return _head->data;
}
    const T& front() const{
        if(_head == nullptr){
           throw std::out_of_range("ForwardList is empty");
}
      return _head->data;
}
    void insert_after(Node* node, const T& value){
        if(node == nullptr){
         return;
}
       Node* new_node = new Node(value);
       new_node->next = node->next;
       node->next = new_node;
       ++_size;
}
  
    void erase_after(Node* node){
        if(node == nullptr || node->next == nullptr){
           return;
}

     Node* removed = node->next;
     node->next = removed->next;
     delete removed;
     --_size;
}
    void clear(){
     while (_head != nullptr) {
            Node* next = _head->next;
            delete _head;
            _head = next;
        }

        _size = 0;
    }

  
    void reverse(){
        Node* previous = nullptr;
        Node* current = _head;

        while (current != nullptr) {
            Node* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        _head = previous;
    }
    
    /// 12. size() - количество элементов
    int size() const{
    return _size;
}
    
    /// 13. empty() - пуст ли
    bool empty() const{
      return _size == 0;
}
    
    /// 14. begin() - начало списка
    Node* begin(){
    return _head;
}
    Node* begin() const{
       return _head;
}
private:
void push_back_copy(const T& value){
  Node* node = new Node(value);
  if(_head == nullptr){
  _head = node;
}else{
Node* current = _head;
  while (current->next != nullptr){
current = current->next;
}
current->next = node;
}
++_size;
}


};

#endif 

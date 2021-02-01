#pragma once

#include <iostream>

template <class T>
class SingleLinkedList {
 private:
  struct Node {
    T _data;
    std::unique_ptr<Node> _next = nullptr;
    Node(T x) : _data{x}, _next{nullptr} {}
  };
  std::unique_ptr<Node> _head{nullptr};
  Node* _tail = nullptr;

 public:
  SingleLinkedList() = default;

  void Dump() const {
    for (Node* loop = _head.get(); loop != nullptr; loop = loop->_next.get()) {
      std::cout << loop->_data << " ";
    }
    std::cout << std::endl;
  }

  // bool empty() const { return head.get() == nullptr; }
  // int getSize() const;
  void push(const T& data);
  void push(T&& data);

  // Iterator basics
  class Iterator;
  Iterator begin() { return Iterator(_head.get()); }
  Iterator end() { return Iterator(nullptr); }
};

template <class T>
void SingleLinkedList<T>::push(const T& data) {
  auto new_node = std::make_unique<Node>(data);

  if (!_head) {
    _head = std::move(new_node);
    _tail = _head.get();
  } else {
    _tail->_next = std::move(new_node);
    _tail = _tail->_next.get();
  }
}

template <class T>
class SingleLinkedList<T>::Iterator {
  using iterator_category = std::forward_iterator_tag;

 public:
  // Constructor
  Iterator(Node* ptr) : mPtr{ptr} {}
  // Compulsory methods
  Iterator& operator++();
  T& operator*();
  bool operator==(const Iterator& iter);
  bool operator!=(const Iterator& iter);

 private:
  Node* mPtr;
};

template <typename T>
typename SingleLinkedList<T>::Iterator&
SingleLinkedList<T>::Iterator::operator++() {
  this->mPtr = mPtr->_next.get();
  return *this;
}

template <typename T>
T& SingleLinkedList<T>::Iterator::operator*() {
  return this->mPtr->_data;
}

template <typename T>
bool SingleLinkedList<T>::Iterator::operator==(const Iterator& iter) {
  return this->mPtr == iter.mPtr;
}

template <typename T>
bool SingleLinkedList<T>::Iterator::operator!=(const Iterator& iter) {
  return this->mPtr != iter.mPtr;
}

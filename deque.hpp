#pragma once

#include <iostream>
#include <memory>

template <class T>
class Deque {
 private:
  struct Node {
    T _data;
    std::unique_ptr<Node> _next = nullptr;
    Node* _prev = nullptr;
    Node(T x) : _data{x}, _next{nullptr}, _prev{nullptr} {}
  };

  std::unique_ptr<Node> _head{nullptr};
  Node* _tail = nullptr;

  int _size{0};

 public:
  Deque() = default;

  void Dump() const {
    for (Node* loop = _head.get(); loop != nullptr; loop = loop->_next.get()) {
      std::cout << loop->_data << " ";
    }
    std::cout << std::endl;
  }

  // bool empty() const { return head.get() == nullptr; }
  int size() const;
  void push_back(const T& data);
  void push_back(T&& data);

  T pop_back();

  // Iterator basics
  class Iterator;
  Iterator begin() { return Iterator(_head.get()); }
  Iterator end() { return Iterator(nullptr); }
};

template <class T>
void Deque<T>::push_back(const T& data) {
  auto new_node = std::make_unique<Node>(data);

  if (!_head) {
    _head = std::move(new_node);
    _tail = _head.get();
  } else {
    _tail->_next = std::move(new_node);
    Node* saved = _tail;
    _tail = _tail->_next.get();
    _tail->_prev = saved;
  }
  _size++;
}

template <class T>
T Deque<T>::pop_back() {
  T ret_val{_tail->_data};
  if (_tail != _head.get()) {
    _tail->_prev->_next = nullptr;
    _tail = _tail->_prev;
  }
  _size--;
  std::cout << "  Returning " << ret_val << std::endl;
  return ret_val;
}

template <class T>
int Deque<T>::size() const {
  return _size;
}

template <class T>
class Deque<T>::Iterator {
  using iterator_category = std::forward_iterator_tag;

 public:
  Iterator(Node* ptr) : mPtr{ptr} {}
  Iterator& operator++();
  T& operator*();
  bool operator==(const Iterator& iter);
  bool operator!=(const Iterator& iter);

 private:
  Node* mPtr;
};

template <typename T>
typename Deque<T>::Iterator& Deque<T>::Iterator::operator++() {
  this->mPtr = mPtr->_next.get();
  return *this;
}

template <typename T>
T& Deque<T>::Iterator::operator*() {
  return this->mPtr->_data;
}

template <typename T>
bool Deque<T>::Iterator::operator==(const Iterator& iter) {
  return this->mPtr == iter.mPtr;
}

template <typename T>
bool Deque<T>::Iterator::operator!=(const Iterator& iter) {
  return this->mPtr != iter.mPtr;
}

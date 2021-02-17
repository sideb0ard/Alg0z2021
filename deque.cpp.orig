#include "deque.hpp"

#include <iostream>

bool Deque::IsEmpty() {
  if (!_first) return true;
  return false;
}

int Deque::Size() { return _size; }

void Deque::AddFirst(std::string value) {
  auto item = std::make_shared<Algo::Item>(value);
  item->next = _first;
  _first = item;

  if (item->next) item->next->prev = _first;

  if (!_last) _last = item;
};

void Deque::AddLast(std::string value) {
  auto item = std::make_shared<Algo::Item>(value);
  std::cout << "Adding " << value << std::endl;
  if (!_last) {
    _last = item;
    if (!_first)
      _first = item;
    else {
      _last->prev = _first;
      _first->next = _last;
    }
  } else {
    auto last_last = _last;
    last_last->next = item;
    _last = item;
    _last->prev = last_last;
  }
}

std::string Deque::RemoveFirst() {
  auto ret = _first;
  if (ret) {
    _first = ret->next;
    ret->next = nullptr;
    if (_first) _first->prev = nullptr;
  }
  return ret->value;
}

std::string Deque::RemoveLast() {
  auto ret = _last;
  if (ret) {
    if (ret->prev) {
      auto prev = ret->prev;
      _last = prev;
      _last->next = nullptr;
    } else
      _last = nullptr;

    ret->prev = nullptr;
  }
  return ret->value;
}

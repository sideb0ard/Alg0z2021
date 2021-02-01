#include "stack_client.h"

#include <iostream>

void StackOfStrings::DumpWurds() {
  for (int i = 0; i < _size; i++) {
    std::cout << _stack[i] << " ";
  }
  std::cout << std::endl;
}

void StackOfStrings::Push(std::string item) {
  if (!IsFull()) {
    // std::cout << "Pushing '" << item << "' to posiion:" << _size <<
    // std::endl;
    _stack[_size++] = item;
  }
}

std::string StackOfStrings::Pop() {
  // std::cout << "POP? what size?" << _size << std::endl;
  if (!IsEmpty()) return _stack[--_size];
  return "";
}

bool StackOfStrings::IsEmpty() { return _size == 0; }

bool StackOfStrings::IsFull() { return _size == STACK_SIZE; }

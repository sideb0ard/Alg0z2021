#include "heap.h"

#include <iostream>

void Node::Insert(int val) {
  std::cout << "Inserting " << val << " and fake ref:" << value_
            << left_child_idx_ << right_child_idx_ << std::endl;
}

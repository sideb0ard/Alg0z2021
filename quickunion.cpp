#include "quickunion.hpp"

#include <iostream>

namespace {
void print_vec(std::vector<int>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
}
}  // namespace

QuickUnion::QuickUnion(int num_objects) : num_objects_{num_objects} {
  for (int i = 0; i < num_objects_; i++) {
    nums_.push_back(i);
    sz_.push_back(1);
  }
  std::cout << "NEW QUICK UNION. Nums are:";
  print_vec(nums_);
};

void QuickUnion::Union(int p, int q) {
  int p_val = Root(p);
  int q_val = Root(q);
  if (p_val == q_val) return;
  if (sz_[p_val] < sz_[q_val]) {
    nums_[p_val] = q_val;
    sz_[q_val] += sz_[p_val];
  } else {
    nums_[q_val] = p_val;
    sz_[p_val] += sz_[q_val];
  }
  // std::cout << "UNION! " << q_val << " " << p_val << std::endl;
  // print_vec(nums_);
  // print_vec(sz_);
}

bool QuickUnion::Connected(int p, int q) { return Root(p) == Root(q); }

int QuickUnion::Root(int i) {
  while (i != nums_[i]) {
    nums_[i] = nums_[nums_[i]];
    i = nums_[i];
  }
  return i;
}

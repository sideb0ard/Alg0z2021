#include "quickfind.hpp"

#include <iostream>

namespace {
void print_vec(std::vector<int>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
}
}  // namespace

QuickFind::QuickFind(int num_objects) : num_objects_{num_objects} {
  for (int i = 0; i < num_objects_; i++) {
    nums_.push_back(i);
  }
  std::cout << "NEW UF. Nums are:";
  print_vec(nums_);
};

void QuickFind::Union(int p, int q) {
  int q_val = nums_[q];
  int p_val = nums_[p];
  std::cout << "UNION! " << q_val << " " << p_val << std::endl;
  for (int i = 0; i < nums_.size(); i++) {
    if (nums_[i] == p_val) nums_[i] = q_val;
  }
  print_vec(nums_);
}

bool QuickFind::Connected(int p, int q) {
  if (nums_[p] == nums_[q]) return true;
  return false;
}
int QuickFind::Find(int p) { return 1; }
int QuickFind::Count() { return 1; }

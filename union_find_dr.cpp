#include <iostream>

#include "quickunion.hpp"

int main() {
  int num_objects;
  std::cin >> num_objects;
  std::cout << "NUM OBJECTS:" << num_objects << std::endl;

  QuickUnion uf = QuickUnion(num_objects);
  int p, q;
  while (std::cin) {
    std::cin >> p >> q;
    if (!uf.Connected(p, q)) {
      std::cout << "READ " << p << " and " << q << std::endl;
      uf.Union(p, q);
    }
  }
}

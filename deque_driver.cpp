#include <iostream>
#include <vector>

#include "deque.hpp"

int main() {
  Deque<std::string> d;

  std::string wurd;
  std::string dash = "-";
  char delim = ' ';

  while (getline(std::cin, wurd, delim)) {
    wurd.erase(std::remove(wurd.begin(), wurd.end(), '\n'), wurd.end());
    d.push_back(wurd);
  }

  for (auto w : d) std::cout << "WAKA WAKA " << w << std::endl;

  std::cout << "SIZE OF D IS " << d.size() << std::endl;

  while (d.size() != 0) {
    auto wurd = d.pop_back();
    std::cout << "POPPED " << wurd << std::endl;
  }
  std::cout << "SIZE OF D IS " << d.size() << std::endl;
}

#include <iostream>
#include <string>

#include "slinkedlist.hpp"

int main() {
  SingleLinkedList<std::string> slist{};

  std::string wurd;
  char delim = ' ';

  while (getline(std::cin, wurd, delim)) {
    wurd.erase(std::remove(wurd.begin(), wurd.end(), '\n'), wurd.end());
    std::cout << "Loooking at wurd:" << wurd << std::endl;
    slist.push(wurd);
  }

  slist.Dump();

  std::cout << "ELTON DO THIS!\n";

  for (auto w : slist) std::cout << "ITERATED w " << w << std::endl;
}

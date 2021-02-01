#include <iostream>
#include <vector>

#include "deque.hpp"

int main() {
  Deque d;

  std::string wurd;
  std::string dash = "-";
  char delim = ' ';

  while (getline(std::cin, wurd, delim)) {
    wurd.erase(std::remove(wurd.begin(), wurd.end(), '\n'), wurd.end());
    // std::cout << "Loooking at wurd:" << wurd << std::endl;
    d.AddLast(wurd);
  }
  // std::cout << std::endl;
  // stacky.DumpWurds();
}

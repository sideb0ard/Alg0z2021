#include <iostream>
#include <vector>

#include "stack_client.h"

int main() {
  StackOfStrings stacky;

  std::string wurd;
  std::string dash = "-";
  char delim = ' ';

  while (getline(std::cin, wurd, delim)) {
    wurd.erase(std::remove(wurd.begin(), wurd.end(), '\n'), wurd.end());
    // std::cout << "Loooking at wurd:" << wurd << std::endl;
    if (wurd.compare(dash) == 0) {
      std::string ret = stacky.Pop();
      if (!ret.empty()) std::cout << ret << " ";
    } else {
      stacky.Push(wurd);
    }
  }
  std::cout << std::endl;
  // stacky.DumpWurds();
}

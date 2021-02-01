#include <array>
#include <string>

const int STACK_SIZE = 50;

class StackOfStrings {
 public:
  StackOfStrings() = default;

  void Push(std::string item);
  std::string Pop();
  bool IsEmpty();
  bool IsFull();

  void DumpWurds();

 private:
  std::array<std::string, STACK_SIZE> _stack{};
  int _size{0};
};

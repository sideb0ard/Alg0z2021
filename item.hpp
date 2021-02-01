#include <memory>
#include <string>

namespace Algo {
struct Item {
  Item(std::string value) : value{value} {}
  std::string value;
  std::shared_ptr<Algo::Item> prev{nullptr};
  std::shared_ptr<Algo::Item> next{nullptr};
  std::string Dump() { return value; }
};

};  // namespace Algo

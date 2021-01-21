#include <vector>

class QuickUnion {
 public:
  QuickUnion(int num_objects);
  void Union(int p, int q);
  bool Connected(int p, int q);
  int Find(int p);
  int Count();

 private:
  int num_objects_{0};
  std::vector<int> nums_;
  std::vector<int> sz_;

 private:
  int Root(int i);
};

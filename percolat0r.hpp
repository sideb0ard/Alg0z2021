#include <vector>

class Percolation {
 public:
  Percolation(int n);
  void Open(int row, int col);
  bool IsOpen(int row, int col);
  bool IsFull(int row, int col);
  int NumberOfOpenSites();
  bool Percolates();

 private:
  std::vector<std::vector<int>> _grid;
};

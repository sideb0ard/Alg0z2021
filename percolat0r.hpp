#include <vector>

#include "quickunion.hpp"

class Percolation {
 public:
  Percolation(int n);
  void Open(int row, int col);
  bool IsOpen(int row, int col);
  bool IsFull(int row, int col);
  int NumberOfOpenSites();
  bool Percolates();

 public:
  std::vector<std::vector<int>> _grid;

 private:
  QuickUnion _connections;
  int _size{0};
  int _open_sites{0};
};

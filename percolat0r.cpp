#include <percolat0r.hpp>

Percolation::Percolation(int n) {
  for (int i = 0; i < n; ++i) {
    std::vector<int> v;
    for (int j = 0; j < n; ++j) v.push_back(1);
    _grid.push_back(v);
  }
}
void Percolation::Open(int row, int col) { _grid[row][col] = 0; }
bool Percolation::IsOpen(int row, int col) { return !_grid[row][col]; }
bool Percolation::IsFull(int row, int col) { return _grid[row][col]; }

int Percolation::NumberOfOpenSites() { return 1; }
bool Percolation::Percolates() { return true; }

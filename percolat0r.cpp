#include "percolat0r.hpp"

#include <iostream>

Percolation::Percolation(int n) : _connections{n * n}, _size{n} {
  for (int i = 0; i < n; ++i) {
    std::vector<int> v{};
    for (int j = 0; j < n; ++j) v.push_back(1);
    _grid.push_back(v);
  }
}
void Percolation::Open(int row, int col) {
  if (IsFull(row, col)) {
    _grid[row][col] = 0;
    _open_sites++;
    if (row > 0) _connections.Union(row * _size + col, (row - 1) * _size + col);
    if (row + 1 < (_size - 1))
      _connections.Union(row * _size + col, (row + 1) * _size + col);
    if (col > 0) _connections.Union(row * _size + col, row * _size + (col - 1));
    if (col + 1 < (_size - 1))
      _connections.Union(row * _size + col, row * _size + (col + 1));
  }
}

bool Percolation::IsOpen(int row, int col) { return !_grid[row][col]; }
bool Percolation::IsFull(int row, int col) { return _grid[row][col]; }

int Percolation::NumberOfOpenSites() { return _open_sites; }

bool Percolation::Percolates() {
  for (int i = 0; i < _size; i++) {
    for (int j = 0; j < _size; j++) {
      int dest_grid = (_size - 1) * _size + j;
      // std::cout << "i:" << i << " and j:" << dest_grid << std::endl;
      if (_connections.Connected(i, dest_grid)) return true;
    }
  }
  return false;
}

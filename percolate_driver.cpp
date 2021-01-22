#include <stdlib.h> /* srand, rand */
#include <time.h>

#include <cstdlib>
#include <iostream>

#include "percolat0r.hpp"

namespace {
void PrintGrid(std::vector<std::vector<int>>& grid) {
  for (auto i : grid) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}
}  // namespace

int main(int argc, char** argv) {
  srand(time(NULL));

  int grid_width = 20;

  Percolation perky{grid_width};
  PrintGrid(perky._grid);
  int num_opened = 0;
  while (!perky.Percolates()) {
    int rand_row = rand() % grid_width;
    int rand_col = rand() % grid_width;
    if (perky.IsFull(rand_row, rand_col)) {
      perky.Open(rand_row, rand_col);
      num_opened++;
    }
  }
  PrintGrid(perky._grid);
  int open_sites = perky.NumberOfOpenSites();
  float thresh = float(open_sites) / (grid_width * grid_width);
  std::cout << "NUm Open Sites:" << open_sites << " / "
            << grid_width * grid_width << " THRESH:" << thresh << std::endl;
}

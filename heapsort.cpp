#include <iostream>
#include <vector>

#include "heap.h"

std::vector<int> numz = {9, 4, 13, 2, 94, 34};

int Parent(int i) { return i / 2; }
int Left(int i) { return 2 * i; }
int Right(int i) { return 2 * i + 1; }

void MaxHeapify(std::vector<int>& numz, int i) {
  int l = Left(i);
  int r = Right(i);
  if (l <=
}

void BuildHeap(std::vector<int>& numz) {}

int main() {
  BuildHeap(numz);
  for (int i = 0; i < numz.size(); ++i) {
    std::cout << "[" << i << "]:" << numz[i] << std::endl;
  }
}

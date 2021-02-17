#include <iostream>
#include <vector>

void merge(std::vector<int>& numz, std::vector<int>& numz_aux, int low, int mid,
           int hi) {
  for (int i = 0; i < numz.size(); i++) {
    numz_aux[i] = numz[i];
  }
  int i = low, j = mid + 1;
  for (int k = low; k <= hi; k++) {
    if (i > mid)
      numz[k] = numz_aux[j++];
    else if (j > hi)
      numz[k] = numz_aux[i++];
    else if (numz_aux[i] > numz_aux[j]) {
      numz[k] = numz_aux[j++];
    } else
      numz[k] = numz_aux[i++];
  }
}

void sort(std::vector<int>& numz, std::vector<int>& numz2, int lo, int hi,
          int depth) {
  for (int i = 0; i < depth; i++) std::cout << "*";
  if (hi <= lo) return;
  std::cout << " Looking at " << lo << " and " << hi << std::endl;
  int mid = lo + (hi - lo) / 2;
  sort(numz, numz2, lo, mid, depth + 1);
  sort(numz, numz2, mid + 1, hi, depth + 1);
  for (int i = 0; i < depth; i++) std::cout << "*";
  std::cout << " MERGING:" << lo << " mid:" << mid << " hi:" << hi << std::endl;
  merge(numz, numz2, lo, mid, hi);
}

void sort_driver(std::vector<int>& numz) {
  std::vector numz_copy = numz;
  int depth = 1;
  sort(numz, numz_copy, 0, numz.size() - 1, depth);
}

int main() {
  std::vector numz = {3, 4, 6, 0, 1, 2, 5, 9, 7, 8};
  sort_driver(numz);

  for (auto n : numz) std::cout << "NUmz:" << n << std::endl;
}

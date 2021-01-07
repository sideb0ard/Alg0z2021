#include <iostream>
#include <vector>

void print_array(std::vector<int>& nums, int level) {
  for (int i = 0; i < level; i++) std::cout << " ";
  for (auto i : nums) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void insertion_sort(std::vector<int>& nums) {
  if (nums.size() < 2) {
    return;
  }
  for (int i = 1; i < nums.size(); ++i) {
    auto key = nums[i];
    auto j = i - 1;
    while (j >= 0 && nums[j] > key) {
      nums[j + 1] = nums[j];
      --j;
    }
    nums[j + 1] = key;
  }
}

void merge(std::vector<int>& nums, int l, int m, int r) {
  std::cout << "MERGE CALLED WITH L:" << l << " M:" << m << " R:" << r
            << std::endl;
  int len_left = m - l + 1;
  int len_right = r - m;

  int left[len_left], right[len_right];
  for (int i = 0; i < len_left; i++) left[i] = nums[l + i];
  for (int j = 0; j < len_right; j++) right[j] = nums[m + 1 + j];

  int left_idx = 0;
  int right_idx = 0;
  int k = l;

  while (left_idx < len_left && right_idx < len_right) {
    if (left[left_idx] < right[right_idx])
      nums[k] = left[left_idx++];
    else
      nums[k] = right[right_idx++];
    k++;
  }

  while (left_idx < len_left) {
    nums[k] = left[left_idx++];
    k++;
  }
  while (right_idx < len_right) {
    nums[k] = right[right_idx++];
    k++;
  }

  for (int i = l; i <= r; i++) {
    std::cout << "POS:" << i << " VAL: " << nums[i] << std::endl;
  }
}

void merge_sort(std::vector<int>& nums, int left, int right) {
  std::cout << "MS called with "
            << " left:" << left << " right:" << right << std::endl;
  if (left < right) {
    int mid = (left + right - 1) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
  }
  std::cout << "AIIGHT, AFTER MERGE:";
  // print_array(nums);
}
void merge2(std::vector<int>& nums, int start, int mid, int end, int level) {
  for (int i = 0; i < level; i++) std::cout << " ";
  std::cout << "*MERGE start:" << start << " mid:" << mid << " end:" << end
            << std::endl;

  std::vector<int> left;
  int left_size = mid - start + 1;
  for (int i = 0; i < left_size; i++) left.push_back(nums[start + i]);

  std::vector<int> right;
  int right_size = end - mid;
  for (int i = 0; i < right_size; i++) right.push_back(nums[mid + 1 + i]);

  int left_idx = 0;
  int right_idx = 0;
  int nums_idx = start;
  while (nums_idx < end) {
    while (left_idx < left_size && right_idx < right_size) {
      if (left[left_idx] < right[right_idx])
        nums[nums_idx] = left[left_idx++];
      else
        nums[nums_idx] = right[right_idx++];
      nums_idx++;
    }
    while (left_idx < left_size) nums[nums_idx++] = left[left_idx++];
    while (right_idx < right_size) nums[nums_idx++] = right[right_idx++];
  }
}

void merge_sort2(std::vector<int>& nums, int start, int end, int level) {
  for (int i = 0; i < level; i++) std::cout << " ";
  std::cout << "Merge Sort start:" << start << " end:" << end << std::endl;
  ++level;
  if (end > start) {
    auto mid = (start + end) / 2;
    merge_sort2(nums, start, mid, level);
    merge_sort2(nums, mid + 1, end, level);
    merge2(nums, start, mid, end, level);
    print_array(nums, level);
  }
}

int main() {
  std::vector<int> nums{5, 2, 4, 6, 1, 3};
  std::cout << "Starting with:" << std::endl;
  print_array(nums, 0);

  // insertion_sort(nums);
  merge_sort2(nums, 0, nums.size() - 1, 0);

  std::cout << "Finsihing with:" << std::endl;
  print_array(nums, 0);
}

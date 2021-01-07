

class Node {
 public:
  Node(int value = -1) : value_{value} {}
  ~Node() = default;
  void Insert(int value);
  void SetValue(int value);

 private:
  int value_;
  int left_child_idx_ = {-1};
  int right_child_idx_{-1};
};

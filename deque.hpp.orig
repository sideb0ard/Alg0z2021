#include <memory>

#include "item.hpp"

class Deque {
 public:
  Deque() = default;
  bool IsEmpty();
  int Size();
  void AddFirst(std::string val);
  void AddLast(std::string val);
  std::string RemoveFirst();
  std::string RemoveLast();

  struct Iterator {
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::shared_ptr<Algo::Item>;

    Iterator(std::shared_ptr<Algo::Item> item) : m_ptr(item) {}
#//reference operator*() const { return *m_ptr; }
#//pointer operator->() { return m_ptr; }

    // Prefix increment
    Iterator& operator++() {
      m_ptr = m_ptr->next;
      return *this;
    }

    // Postfix increment
    Iterator operator++(std::shared_ptr<Algo::Item>) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    friend bool operator==(const Iterator& a, const Iterator& b) {
      return a.m_ptr == b.m_ptr;
    };
    friend bool operator!=(const Iterator& a, const Iterator& b) {
      return a.m_ptr != b.m_ptr;
    };

   private:
    std::shared_ptr<Algo::Item> m_ptr{nullptr};
  };
  Iterator begin() { return Iterator(_first); };
  Iterator end() { return Iterator(_last); };

 private:
  std::shared_ptr<Algo::Item> _first{nullptr};
  std::shared_ptr<Algo::Item> _last{nullptr};
  size_t _size{0};
};

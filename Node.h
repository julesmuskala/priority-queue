#ifndef NODE_H_
#define NODE_H_

namespace priorityQueue {

template <class T, class P>
class Node {
  T data_;
  P priority_;

 public:
  Node(T& data, P& priority) noexcept : data_(data), priority_(priority) {}

  Node(const T& data, const P& priority) noexcept : data_(data), priority_(priority) {}

  P& get_priority() noexcept {
    return priority_;
  }

  T& get_data() noexcept {
    return data_;
  }

  T* operator->() noexcept {
    return &data_;
  }

  bool operator<(Node& rhs) const noexcept {
    return priority_ < rhs.priority_;
  }

  bool operator>(Node& rhs) const noexcept {
    return priority_ > rhs.priority_;
  }

  bool operator<=(Node& rhs) const noexcept {
    return priority_ <= rhs.priority_;
  }

  bool operator>=(Node& rhs) const noexcept {
    return priority_ >= rhs.priority_;
  }

  bool operator<=>(Node& rhs) const noexcept {
    return priority_ <=> rhs.priority_;
  }
};

}  // namespace priorityQueue

#endif  // NODE_H_
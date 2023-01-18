#include <functional>
#include <memory>
#include <utility>

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

namespace priorityQueue {

#define PRIORITY_QUEUE_ALLOC_SIZE 8

template <class T>
class PriorityQueue {
  std::allocator<T> allocator_;

  T* data_;
  size_t size_;
  size_t alloc_size_;

  void move_data_(const size_t new_alloc_size) {
    T* const new_head = allocator_.allocate(new_alloc_size);

    if (size_) {
      std::copy(data_, data_ + size_, new_head);

      allocator_.deallocate(data_, alloc_size_);
    }

    data_ = new_head;
    alloc_size_ = new_alloc_size;
  }

  inline void grow_() {
    move_data_(alloc_size_ + PRIORITY_QUEUE_ALLOC_SIZE);
  }

  inline void shrink_() {
    if (alloc_size_ > PRIORITY_QUEUE_ALLOC_SIZE) return;

    move_data_(alloc_size_ - PRIORITY_QUEUE_ALLOC_SIZE);
  }

  void bubble_up_() {
    size_t i = size_ - 1;

    while (i > 0) {
      const size_t parentIndex = (i - 1) / 2;

      if (!compare_(data_[i], data_[parentIndex])) break;

      std::swap<T>(data_[parentIndex], data_[i]);

      i = parentIndex;
    }
  }

  void rotate_() {
    size_t i = 0;

    while (true) {
      const size_t lIndex = 2 * i + 1;
      const size_t rIndex = 2 * i + 2;
      size_t swapIndex = -1;

      if (lIndex < size_ && compare_(data_[lIndex], data_[i])) {
        swapIndex = lIndex;
      }

      if (rIndex < size_) {
        if ((swapIndex == -1 && compare_(data_[rIndex], data_[i])) ||
            (swapIndex != -1 && compare_(data_[rIndex], data_[lIndex]))) {
          swapIndex = rIndex;
        }
      }

      if (swapIndex == -1) break;

      std::swap<T>(data_[i], data_[swapIndex]);

      i = swapIndex;
    }
  }

 protected:
  virtual inline bool compare_(T& lv, T& rv) {
    return lv < rv;
  }

 public:
  PriorityQueue() : size_(0), alloc_size_(0), data_(nullptr) {
    grow_();
  }

  PriorityQueue(PriorityQueue<T>&& other) noexcept : size_(other.size_),
                                                     alloc_size_(other.alloc_size_),
                                                     data_(other.data_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.alloc_size_ = 0;

    other.grow_();
  }

  ~PriorityQueue() noexcept {
    allocator_.deallocate(data_, alloc_size_);
  }

  void push(const T& value) {
    if (size_ + 1 > alloc_size_) {
      grow_();
    }

    data_[size_] = value;

    ++size_;

    bubble_up_();
  }

  void push(T& value) {
    if (size_ + 1 > alloc_size_) {
      grow_();
    }

    data_[size_] = value;

    ++size_;

    bubble_up_();
  }

  template <class... Args>
  void emplace(Args&&... args) {
    push(T(std::forward<Args>(args)...));
  }

  void pop() {
    if (!size_) return;

    if (size_ - 1 < alloc_size_ - PRIORITY_QUEUE_ALLOC_SIZE) {
      shrink_();
    }

    --size_;

    data_[0] = data_[size_];
    rotate_();
  }

  bool empty() const noexcept {
    return !size_;
  }

  size_t size() const noexcept {
    return size_;
  }

  T& front() const {
    return *data_;
  }
};

}  // namespace priorityQueue

#endif  // PRIORITY_QUEUE_H_
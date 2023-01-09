#include <string>

#include "PriorityQueue.h"

#ifndef STRING_PRIORITY_QUEUE_H_
#define STRING_PRIORITY_QUEUE_H_

namespace priorityQueue {

class StringPriorityQueue : public PriorityQueue<std::string> {
  inline bool compare_(std::string& lv, std::string& rv) override {
    return lv.compare(rv) <= 0;
  }
};

}  // namespace priorityQueue

#endif  // STRING_PRIORITY_QUEUE_H_
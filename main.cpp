#include <iostream>
#include <string>

#include "PriorityQueue.h"
#include "StringPriorityQueue.h"

using namespace priorityQueue;
using std::cout, std::endl;

int main() {
  PriorityQueue<int> intPQ;

  for (int i = 32; i > 0; --i) {
    intPQ.push(i);
  }

  while (!intPQ.empty()) {
    cout << intPQ.front() << " ";
    intPQ.pop();
  }

  cout << endl;

  StringPriorityQueue strPQ;

  for (int i = 25; i >= 0; --i) {
    strPQ.emplace(1, i + 65);
  }

  while (!strPQ.empty()) {
    cout << strPQ.front() << " ";
    strPQ.pop();
  }

  cout << endl;
}
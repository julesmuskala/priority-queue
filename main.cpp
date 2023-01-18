#include <iostream>
#include <string>

#include "Node.h"
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

  PriorityQueue<Node<char, int>> nodePQ;

  for (int i = 25; i >= 0; --i) {
    nodePQ.emplace(i + 97, i);
  }

  while (!nodePQ.empty()) {
    auto node = nodePQ.front();
    cout << "[" << node.get_data() << " " << node.get_priority() << "]"
         << " ";
    nodePQ.pop();
  }

  cout << endl;

  for (int i = 25; i >= 0; --i) {
    nodePQ.push(Node<char, int>(122 - i, i));
  }

  while (!nodePQ.empty()) {
    auto node = nodePQ.front();
    cout << "[" << node.get_data() << " " << node.get_priority() << "]"
         << " ";
    nodePQ.pop();
  }

  cout << endl;
}
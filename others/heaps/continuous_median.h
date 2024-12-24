#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

// Do not edit the class below except for
// the insert method. Feel free to add new
// properties and methods to the class.
class ContinuousMedianHandler {
 public:
  double median;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, std::greater<int>> minHeap;

  void rebalanceHeaps() {
    if(maxHeap.size() > minHeap.size()) {
      auto top = maxHeap.top();
      maxHeap.pop();
      minHeap.push(top);
    } else {
      auto top = minHeap.top();
      minHeap.pop();
      maxHeap.push(top);
    }
  }

  void insert(int number) {
    if(maxHeap.empty()) {
      maxHeap.push(number);
      median = number;
      return;
    }

    if(number <= maxHeap.top()) {
      maxHeap.push(number);
    } else {
      minHeap.push(number);
    }

    if(abs((int)maxHeap.size() - (int)minHeap.size()) > 1) {
      rebalanceHeaps();
    }
  
    int len{(int)minHeap.size() + (int)maxHeap.size()};
    if(len % 2 == 0) {
      median = (double)(maxHeap.top() + minHeap.top()) / 2;
    } else {
      median = (maxHeap.size() > minHeap.size()) ? maxHeap.top() : minHeap.top();
    }
  }

  double getMedian() { return median; }
};

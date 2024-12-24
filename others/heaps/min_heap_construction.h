#include <vector>
using namespace std;
#define N (heap.size()-1)

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
 public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  vector<int> buildHeap(vector<int>& vec) {
    int firstParent = (vec.size() - 2) / 2;
	for(int i = firstParent; i >= 0; i--) {
		siftDown(i, vec.size()-1, vec);
	}
    return vec;
  }

  void siftDown(int currentIdx, int endIdx, vector<int>& heap) {
    int c1 = currentIdx * 2 + 1;
	while(c1 <= endIdx) {
		int c2 = (currentIdx*2 + 2) <= endIdx ? (currentIdx*2 + 2) : -1;
		int idxToSwap;
		if(c2 != -1 && heap[c2] < heap[c1]) {
			idxToSwap = c2;
		} else {
			idxToSwap = c1;
		}
        if(heap[idxToSwap] < heap[currentIdx]) {
          swap(heap[currentIdx], heap[idxToSwap]);
          currentIdx = idxToSwap;
  		  c1 = currentIdx * 2 + 1;
        } else {
          return;
        }
	 }
  }

  void siftUp(int currentIdx) {
    int parent = (currentIdx-1) / 2;
	while(currentIdx > 0 && heap[currentIdx] < heap[parent]) {
		swap(heap[currentIdx], heap[parent]);
		currentIdx = parent;
		parent = (currentIdx - 1) / 2;
	}
  }

  int peek() {
    return heap[0];
  }

  int remove() {
    swap(heap[0], heap[heap.size()-1]);
	int tbr = heap.back();
	heap.pop_back();
	siftDown(0, N, heap);
    return tbr;
  }

  void insert(int value) {
    heap.push_back(value);
	siftUp(N);
  }
  
  void swap(int& i, int &j)
  {
	int tmp = i;
	i = j;
	j = tmp;
  }
};
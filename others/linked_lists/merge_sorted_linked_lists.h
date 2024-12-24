#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList* mergeLinkedLists(LinkedList* h1, LinkedList* h2) {
  LinkedList* prev = nullptr;
  LinkedList* p1 = h1;
  LinkedList* p2 = h2;
  while(p1 && p2) {
      if(p1->value < p2->value) {
          prev = p1;
          p1 = p1->next;
      } else {
          if(prev) {
              prev->next = p2;
          }
          
          prev = p2;
          p2 = p2->next;
          prev->next = p1;
      }
  }
  if(p1 == nullptr) {
      prev->next = p2;
  }
  
  return (h1->value < h2->value) ? h1 : h2;
}

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* middleNode(LinkedList* linkedList) {
  // Write your code here.
  if(linkedList == nullptr || linkedList->next == nullptr) {
    return linkedList;
  }

  LinkedList* slow = linkedList;
  LinkedList* fast = linkedList;
  while(fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

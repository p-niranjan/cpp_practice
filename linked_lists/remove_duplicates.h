using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* removeDuplicatesFromLinkedList(LinkedList* head) {
  LinkedList* cur = head;
  while(cur && cur->next != nullptr) {
    if(cur->value == cur->next->value) {
      cur->next = cur->next->next;
      continue;
    }
    cur = cur->next;
  }
  return head;
}

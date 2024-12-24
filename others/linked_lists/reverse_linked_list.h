using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

LinkedList* reverseLinkedList(LinkedList* head) {
  LinkedList* cur = head;
  LinkedList* nxt = nullptr;
  LinkedList* prev = nullptr;
  while(cur != nullptr) {
    nxt = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nxt;
  }
  return prev;
}

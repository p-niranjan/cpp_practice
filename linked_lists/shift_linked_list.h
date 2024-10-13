using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList* shiftLinkedList(LinkedList* head, int k) {    
  LinkedList* oldTail = head;
  int len = 1;
  while(oldTail->next != nullptr) {
    oldTail = oldTail->next;
    len++;    
  }
  printf("len = %d, oldTail = %d ", len, oldTail->value);
  int offset = abs(k) % len;
  if(offset == 0) {
    return head;
  }
  int newTailPos = (k < 0) ? offset : len-offset;
  printf("offset = %d, newTailPos = %d ", offset, newTailPos);
  LinkedList* newTail = head;
  for(int i=1; i<newTailPos; i++) {
    newTail = newTail->next;
  }
  oldTail->next = head;
  printf("newTail = %d ", newTail->value);
  LinkedList* newHead = newTail->next;
  newTail->next = nullptr;
  // oldTail->next = head;
  return newHead;
}

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* sumOfLinkedLists(LinkedList* l1, LinkedList* l2) {
  LinkedList* p1 = l1;
  LinkedList* p2 = l2;
  LinkedList* sum = new LinkedList(0);
  LinkedList* p3 = sum;
  int carry = 0;
  while(p1 != nullptr && p2 != nullptr) {
    int v1 = p1->value;
    int v2 = p2->value;
    int sum = v1 + v2 + carry;
    carry = (sum > 9) ? 1 : 0;
    p3->next = new LinkedList(sum%10);
    p1 = p1->next;
    p2 = p2->next;    
    p3 = p3->next;
  }

  while(p1 != nullptr) {
    int v1 = p1->value;
    // int v2 = p2->value;
    int sum = v1 + carry;
    carry = (sum > 9) ? 1 : 0;
    p3->next = new LinkedList(sum%10);
    p1 = p1->next;
    p3 = p3->next;
  }

  while(p2 != nullptr) {
    // int v1 = p1->value;
    int v2 = p2->value;
    int sum = v2 + carry;
    carry = (sum > 9) ? 1 : 0;
    p3->next = new LinkedList(sum%10);
    p2 = p2->next;    
    p3 = p3->next;
  }
  if(carry > 0) {
    p3->next = new LinkedList(carry);
    carry = 0;
  }
  return sum->next;
}
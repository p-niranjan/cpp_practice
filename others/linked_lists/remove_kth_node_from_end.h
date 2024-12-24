#include <vector>
using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList* head, int k) {
  // Write your code here.
  LinkedList* first = head;
  LinkedList* second = head;
  int cnt = 1;
  while(cnt <= k) {
    second = second->next;
    cnt++;
  }

  if(second == nullptr) {
    LinkedList* tmp = head;
    head->value = head->next->value;
    // head->next = head->next->next;  
    // head = head->next;
    head->next = head->next->next;
    // delete tmp;
    // tmp = nullptr;
    return;
  }

  while(second->next != nullptr) {
    second = second->next;
    first = first->next;
  }
  LinkedList* tmp = first->next;
  first->next = tmp->next;
  delete tmp;
  tmp = nullptr;  
}

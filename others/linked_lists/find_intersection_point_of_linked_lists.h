using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* mergingLinkedLists(
  LinkedList* l1, LinkedList* l2
) {
	int c1 = 0, c2 = 0;
    LinkedList* one = l1;
    LinkedList* two = l2;
	while(one != nullptr) {
		c1++;
		one = one->next;
	}
	printf("c1 = %d\n", c1);
	while(two != nullptr) {
		c2++;
		two = two->next;
	}
	printf("c2 = %d\n", c2);
	LinkedList* big = (c1 > c2) ? l1 : l2;
	LinkedList* small = (c1 > c2) ? l2 : l1;
	
	int diff = abs(c1 - c2);
    printf("diff = %d\n", diff);
	for(int i=0; i<diff; i++) {
		big = big->next;
	}
	printf("Big travel\n");
	while(big != small) {
		big = big->next;
		small = small->next;
	}
	
	return big;
}

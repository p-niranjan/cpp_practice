using namespace std;

class Node {
 public:
  int value;
  Node* prev;
  Node* next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
 public:
  Node* head;
  Node* tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void setHead(Node* node) {
    // Write your code here.
    if(head == nullptr) {
      head = node;
      tail = node;
      return;
    }
    insertBefore(head, node);
  }

  void setTail(Node* node) {
    // Write your code here.
    if(head == nullptr) {
      setHead(node);
      return;
    }
    insertAfter(tail, node);
  }

  void insertBefore(Node* node, Node* nodeToInsert) {
    // Write your code here.
    //if(node == this->head && node == this->tail) {
    if(nodeToInsert == this->head && nodeToInsert == this->tail) {
      return;
    }
    remove(nodeToInsert);
    nodeToInsert->next = node;
    nodeToInsert->prev = node->prev;
    if(node->prev == nullptr) {
      head = nodeToInsert;
    } else {
      node->prev->next = nodeToInsert;
    }
    node->prev = nodeToInsert;
  }

  void insertAfter(Node* node, Node* nodeToInsert) {
    // Write your code here.
    if(nodeToInsert == head && nodeToInsert == tail) {
      return;
    }

    remove(nodeToInsert);
    nodeToInsert->prev = node;
    nodeToInsert->next = node->next;
    if((node->next) == nullptr) {
      tail = nodeToInsert;
    } else {
      node->next->prev = nodeToInsert;
    }
    node->next = nodeToInsert;
  }

  void insertAtPosition(int position, Node* nodeToInsert) {
    // Write your code here.
    if(position == 1) {
      setHead(nodeToInsert);
      return;
    }

    int pos = 1;
    Node* cur = head;
    while(cur && pos != position) {
      cur = cur->next;
      pos++;
    }
    if(cur) {
      insertBefore(cur, nodeToInsert);
    } else {
      setTail(nodeToInsert);
    }
  }

  void removeNodesWithValue(int value) {
    // Write your code here.
    Node* node = this->head;
    while(node) {
      Node* tmp = node;
      node = node->next;
      if(tmp->value == value) {
        remove(tmp);
      }
    }
  }

  void removeBindings(Node* node) {
    if(node->prev) {
      node->prev->next = node->next;
    }
    if(node->next) {
      node->next->prev = node->prev;
    }
    node->next = nullptr;
    node->prev = nullptr;
  }

  void remove(Node* node) {
    // Write your code here.
    if(node == this->head) {
      this->head = node->next;
    }
    if(node == this->tail) {
      this->tail = node->prev;
    }
    removeBindings(node);
  }

  bool containsNodeWithValue(int value) {
    // Write your code here.
    Node* cur = this->head;
    while(cur && cur->value != value) {
      cur = cur->next;
    }
    return cur != nullptr;
  }
};

using namespace std;

struct Node {
    string key;
    int value;
    Node *next;
    Node *prev;

    Node(string k, int v) {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

// Do not edit the class below except for the insertKeyValuePair,
// getValueFromKey, and getMostRecentKey methods. Feel free
// to add new properties and methods to the class.
class LRUCache {
 public:
  int capacity;
  unordered_map<string, Node *> cacheMap;
  Node *head;
  Node *tail;

  LRUCache(int capacity) 
  { 
    this->capacity = capacity > 1 ? capacity : 1;
    head = new Node("", -1);
    tail = new Node("", -1);
    head->next = tail;
    tail->prev = head;
  }

  void insertKeyValuePair(string key, int value) {
    if (cacheMap.find(key) != cacheMap.end()) {
        Node *oldNode = cacheMap[key];
        remove(oldNode);          
    }

    Node *node = new Node(key, value);
    cacheMap[key] = node;
    add(node);
   
    if (cacheMap.size() > capacity) {
        Node *nodeToDelete = tail->prev;
        remove(nodeToDelete);
        cacheMap.erase(nodeToDelete->key);
    }
  }

  int* getValueFromKey(string key) {
    if (cacheMap.find(key) == cacheMap.end()) {
       return nullptr;
    }      
    Node *node = cacheMap[key];
    remove(node);
    add(node);
    return &(node->value);
  }

  void add(Node *node) {
      Node *nextNode = head->next;
      head->next = node;
      node->prev = head;
      node->next = nextNode;
      nextNode->prev = node;
  }

    // Remove a node from the list
  void remove(Node *node) {
      Node *prevNode = node->prev;
      Node *nextNode = node->next;
      prevNode->next = nextNode;
      nextNode->prev = prevNode;
  }

  string getMostRecentKey() {
    return head ? head->next->key : "";
  }
};

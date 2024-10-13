#include <vector>
#include <queue>
using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void swapNode(BinaryTree* &node) {
  BinaryTree* tmp = node->left;
  node->left = node->right;
  node->right = tmp;
}

void invertBinaryTree(BinaryTree* tree) {
  // Write your code here.
  queue<BinaryTree*> q;
  q.push(tree);
  while(q.size() != 0) {
    BinaryTree* cur = q.front();
    q.pop();
    if(cur == nullptr) {
      continue;
    }
    swapNode(cur);
    q.push(cur->left);
    q.push(cur->right);
  }  
}

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;
  BinaryTree* parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

BinaryTree* LeftMostChildInRightSubtree(BinaryTree* node)
{
  BinaryTree* cur = node;
  while(cur->left != nullptr) {
    cur = cur->left;
  }
  return cur;
}

BinaryTree* RightMostParent(BinaryTree* node)
{
  BinaryTree* cur = node;
  while(cur->parent != nullptr && cur->parent->right == cur) {
    cur = cur->parent;
  }
  return cur->parent;
}

BinaryTree* findSuccessor(BinaryTree* tree, BinaryTree* node) {
  if(node->right != nullptr) {
   return LeftMostChildInRightSubtree(node->right);
  }
  return RightMostParent(node);
}

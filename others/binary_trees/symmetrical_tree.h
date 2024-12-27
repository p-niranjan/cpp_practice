using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

bool IsMirror(BinaryTree* left, BinaryTree* right) 
{
  if(left && right && left->value == right->value) {
    return IsMirror(left->left, right->right) && 
      IsMirror(left->right, right->left);
  }
  return left == right;
}

bool symmetricalTree(BinaryTree* tree) {
  // Write your code here.
  return IsMirror(tree->left, tree->right);
}

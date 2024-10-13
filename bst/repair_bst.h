using namespace std;

// This is an input class. Do not edit.
class BST {
 public:
  int value;
  BST* left = nullptr;
  BST* right = nullptr;

  BST(int value) { this->value = value; }
};

void inorder(BST* tree, BST* &n1, BST* &n2, BST* &prev)
{
  if(tree == nullptr) {
    return;
  }
  inorder(tree->left, n1, n2, prev);
  if(prev && prev->value > tree->value) {
    if(n1 == nullptr) {
      n1 = prev;
    }
    n2 = tree;
  }
  prev = tree;
  inorder(tree->right, n1, n2, prev);
}

void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

BST* repairBst(BST* tree) {
  BST* n1 = nullptr;
  BST* n2 = nullptr;
  BST* prev = nullptr;
  inorder(tree, n1, n2, prev);
  swap(n1->value, n2->value);
  return tree;
}

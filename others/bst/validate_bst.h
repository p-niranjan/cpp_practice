#include <stdio.h>
class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST& insert(int val);
};

bool isValidBst(BST* tree, int max, int min) {
  if(tree == nullptr) {
    printf("tree null: max = %d, min = %d\n", max, min);
    return true;
  }
  const int v = tree->value;
  printf("tree val = %d, max = %d, min = %d\n", v, max, min);
  if(v >= max || v < min) {
    printf("(v > max || v < min), return false\n");
    return false;
  }

  printf("traversing left val-1 = %d, min = %d\n", v-1, min);
  bool left = isValidBst(tree->left, v, min);
  printf("traversing right val+1 = %d, max = %d\n", v-1, max);
  bool right = isValidBst(tree->right, max, v);
  printf("left = %d, right = %d\n", left, right);
  return left && right;
}

bool validateBst(BST* tree) {
  // Write your code here.
  return isValidBst(tree, INT_MAX, INT_MIN);
}

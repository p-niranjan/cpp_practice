class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST& insert(int val);
};

int findClosestValueInBst(BST* tree, int target) {
  // Write your code here.
  int clst = tree->value;  
  while(tree != NULL) {
    int curdiff = abs(tree->value - target);
    int clstdiff = abs(target - clst);
    if(curdiff < clstdiff) {
      clst = tree->value;
    }
    if(target < tree->value) {
      tree = tree->left;
    } else {
      tree = tree->right;
    }
  }
  return clst;
}

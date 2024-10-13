using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

int depths(BinaryTree* node, int depth) {
  if(node == nullptr) {
    return 0;
  }

  return depth + depths(node->left, depth+1) +  depths(node->right, depth+1);
}

int nodeDepths(BinaryTree* root) {
  // Write your code here.
  return depths(root, 0);
}

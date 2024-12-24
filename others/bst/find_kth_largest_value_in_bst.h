using namespace std;

// This is an input class. Do not edit.
class BST {
 public:
  int value;
  BST* left = nullptr;
  BST* right = nullptr;

  BST(int value) { this->value = value; }
};

void inorder(BST* tree, vector<int> &a)
{
  if(tree == nullptr) {
    return;
  }
  inorder(tree->left, a);
  a.push_back(tree->value);
  inorder(tree->right, a);
}

int findKthLargestValueInBst(BST* tree, int k) {
  // Write your code here.
  vector<int> array;
  inorder(tree, array);
  int index = array.size() - k;
  return array[index];
}

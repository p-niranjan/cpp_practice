using namespace std;

// This is an input class. Do not edit.
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

struct TreeInfo
{
  int dia;
  int ht;
};

TreeInfo getTreeInfo(BinaryTree* tree) {
  if(tree == nullptr) {
    return {0,0};
  }

  TreeInfo left = getTreeInfo(tree->left);
  TreeInfo right = getTreeInfo(tree->right);
  int longestPathThroughRoot = right.ht + left.ht;
  int maxDiaSoFar = max(left.dia, right.dia);
  int curDia = max(longestPathThroughRoot, maxDiaSoFar);
  int curHt = 1 + max(left.ht, right.ht);
  return {curDia, curHt};
}

int binaryTreeDiameter(BinaryTree* tree) {
  // Write your code here.
  return getTreeInfo(tree).dia;
}

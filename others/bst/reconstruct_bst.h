using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) : value(value) {}
};

struct TreeInfo {
  bool isBst;
  int minVal;
  int maxVal;
  int bstSize;
  int bstSum;
  int totalSumOfBstNodes;
};

TreeInfo getTreeInfo(BinaryTree* node) 
{
  if(node == nullptr) {
    return {true, INT_MAX, INT_MIN, 0, 0, 0};
  }
  TreeInfo left = getTreeInfo(node->left);
  TreeInfo right = getTreeInfo(node->right);
  bool bstProp = (node->value > left.maxVal && node->value <= right.minVal);
  bool isBst = bstProp && left.isBst && right.isBst;
  int minVal = min(node->value , min(left.minVal, right.minVal));
  int maxVal = max(node->value , max(left.maxVal, right.maxVal));
  int totalSumOfBstNodes = left.totalSumOfBstNodes + right.totalSumOfBstNodes;
  int bstSize = 0, bstSum = 0;
  if(isBst) {
    printf("isBst %d\n", isBst);
    bstSize = 1 + left.bstSize + right.bstSize;
    bstSum = node->value + left.bstSum + right.bstSum;

    if(bstSize >= 3) {
      totalSumOfBstNodes = bstSum;
    }
  }
  return {isBst, minVal, maxVal, bstSize, bstSum, totalSumOfBstNodes};
}

int sumBsts(BinaryTree *tree) {
  return getTreeInfo(tree).totalSumOfBstNodes;
}

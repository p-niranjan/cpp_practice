#include <vector>
using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

struct TreeInfo {
  int maxSumAsBranch;
  int maxFinalSumAtNode;
};

TreeInfo maxPathSumHelper(BinaryTree* node)
{
  if (node == nullptr) {
    return {0, INT_MIN};
  }
  TreeInfo left = maxPathSumHelper(node->left);
  TreeInfo right = maxPathSumHelper(node->right);
  const int val = node->value;
  int maxSumOfChildAsBranch = max(left.maxSumAsBranch, right.maxSumAsBranch);
  int maxSumAsBranch = max(val+maxSumOfChildAsBranch, val);
  int maxSumAsTree = max((left.maxSumAsBranch + right.maxSumAsBranch + val), maxSumAsBranch);
  int maxFinalSumAtNode = max(max(left.maxFinalSumAtNode, right.maxFinalSumAtNode), maxSumAsTree);
  return {maxSumAsBranch, maxFinalSumAtNode};
}

int maxPathSum(BinaryTree tree) {
  return maxPathSumHelper(&tree).maxFinalSumAtNode;
}

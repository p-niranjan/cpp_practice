using namespace std;

struct TreeInfo
{
  bool isB;
  int ht;
};

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

TreeInfo getTreeInfo(BinaryTree* node)
{
  if(node == nullptr) {
    return {true, -1};
  }

  TreeInfo lti = getTreeInfo(node->left);
  TreeInfo rti = getTreeInfo(node->right);

  bool isB = lti.isB && rti.isB && abs(lti.ht - rti.ht) <= 1;
  int ht = max(lti.ht, rti.ht) + 1;
  return {isB, ht};
}

bool heightBalancedBinaryTree(BinaryTree* tree) {
  // Write your code here.
  return getTreeInfo(tree).isB;
}

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

int evaluateExpressionTree(BinaryTree* tree) {
  // Write your code here.
  if(tree->value >= 0) {
    return tree->value;
  }

  int left = evaluateExpressionTree(tree->left);
  int right = evaluateExpressionTree(tree->right);
  int expr = 0;
  switch(tree->value) {
    case(-1): expr =  (left + right) ; break;
    case(-2): expr =  (left - right) ; break;
    case(-3): expr =  (left / right) ; break;
    case(-4): expr =  (left * right) ; break;
    default: break;
  }
  return expr;
}

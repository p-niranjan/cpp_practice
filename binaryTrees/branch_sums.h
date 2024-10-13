using namespace std;

// This is the class of the input root. Do not edit it.
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

void calculate(BinaryTree* root, int runningSum, vector<int> &sums) {
  if(root == nullptr) {
    return;
  }
  int newSum = runningSum + root->value;
  if(!root->left && !root->right) {
    sums.push_back(newSum);
    return;
  }
  calculate(root->left, newSum, sums);
  calculate(root->right, newSum, sums);  
}

vector<int> branchSums(BinaryTree* root) {
  // Write your code here.
  vector<int> sums;
  calculate(root, 0, sums);
  return sums;
}

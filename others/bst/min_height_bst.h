using namespace std;

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

void construct(vector<int> &array, BST* &tree, int startIdx, int endIdx) {
  if(endIdx < startIdx) {
    return;
  }

  int midIdx = (startIdx + endIdx)/2;
  int element = array[midIdx];
  if(tree == nullptr) {
    tree = new BST(element);
  } else {
    tree->insert(element);
  }

  construct(array, tree, startIdx, midIdx-1);
  construct(array, tree, midIdx+1, endIdx);
}

BST* minHeightBst(vector<int> array) {
  // Write your code here.
  BST* tree = nullptr;
  construct(array, tree, 0, array.size()-1);
  return tree;
}

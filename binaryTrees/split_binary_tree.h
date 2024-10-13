using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

struct SplitTreeInfo
{
	bool canBeSplit;
	int splitSum;
};

int getTreeSum(BinaryTree* node)
{
	if(node == nullptr)
		return 0;
	
	return node->value + getTreeSum(node->left) + getTreeSum(node->right);
}

SplitTreeInfo checkSplit(BinaryTree* node, int desiredSum)
{
	if(node == nullptr)
		return {false, 0};
	 
	SplitTreeInfo leftTreeInfo = checkSplit(node->left, desiredSum);
	SplitTreeInfo rightTreeInfo = checkSplit(node->right, desiredSum);
	
	int currentTreeSum = leftTreeInfo.splitSum + rightTreeInfo.splitSum + node->value;
	bool canBeSplit = leftTreeInfo.canBeSplit || rightTreeInfo.canBeSplit || desiredSum == currentTreeSum;
	return {canBeSplit, currentTreeSum};
}

int splitBinaryTree(BinaryTree* node)
{
	int desiredSum = getTreeSum(node)/2;
	SplitTreeInfo treeInfo = checkSplit(node, desiredSum);
	return (treeInfo.canBeSplit) ? treeInfo.splitSum : 0;
}

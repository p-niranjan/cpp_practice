#include <vector>
using namespace std;

class AncestralTree {
 public:
  char name;
  AncestralTree* ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
  }

  void addAsAncestor(vector<AncestralTree*> descendants);
};

int getDescendantDepth(AncestralTree* desc, AncestralTree* top);
AncestralTree* backtrackAncestralTree(AncestralTree* deeper, AncestralTree* higher, int diff);

AncestralTree* getYoungestCommonAncestor(
  AncestralTree* topAncestor,
  AncestralTree* descendantOne,
  AncestralTree* descendantTwo
) {
  int d1 = getDescendantDepth(descendantOne, topAncestor);
  int d2 = getDescendantDepth(descendantTwo, topAncestor);
  if(d1 > d2) {
    return backtrackAncestralTree(descendantOne, descendantTwo, d1-d2);
  } else {
    return backtrackAncestralTree(descendantTwo, descendantOne, d2-d1);
  }
  // return nullptr;
}

int getDescendantDepth(AncestralTree* desc, AncestralTree* top)
{
  int depth = 0;
  while(desc != top) {
    desc = desc->ancestor;
    depth++;
  }
  return depth;
}


AncestralTree* backtrackAncestralTree(AncestralTree* deeper, AncestralTree* higher, int diff)
{
  int cnt = diff;
  while(cnt > 0) {
    deeper = deeper->ancestor;
    cnt--;
  }

  while(higher != deeper) {
    higher = higher->ancestor;
    deeper = deeper->ancestor;
  }
  return deeper;
}

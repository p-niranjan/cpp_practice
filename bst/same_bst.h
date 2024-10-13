#include <vector>

using namespace std;

vector<int> getSmaller(vector<int> a) 
{
  vector<int> out = {};
  for(int i=1; i<a.size(); i++) {
    if(a[i] < a[0]) {
      out.push_back(a[i]);
    }
  }
  return out;
}

vector<int> getGreaterOrEqual(vector<int> a) 
{
  vector<int> out = {};
  for(int i=1; i<a.size(); i++) {
    if(a[i] >= a[0]) {
      out.push_back(a[i]);
    }
  }
  return out;
}

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
  if(arrayOne.size() != arrayTwo.size()) {
    return false;
  }

  if(arrayOne.size() == 0 && arrayTwo.size() == 0) {
    return true;
  }

  if(arrayOne[0] != arrayTwo[0]) {
    return false;
  }

  vector<int> leftOne = getSmaller(arrayOne);
  vector<int> leftTwo = getSmaller(arrayTwo);
  vector<int> rightOne = getGreaterOrEqual(arrayOne);
  vector<int> rightTwo = getGreaterOrEqual(arrayTwo);
  return sameBsts(leftOne, leftTwo) && sameBsts(rightOne, rightTwo);
}

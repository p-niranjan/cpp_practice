#include <vector>
#include <cstdlib>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
  int l = 0, r = array.size() - 1, i = array.size() - 1;
  vector<int> out(array.size());
  //out.reserve(array.size());
  while(l <= r) {
    int left = array[l], right = array[r];
    if(abs(left) > abs(right)) {
      out[i] = left*left;
      l++;
      i--;
    } else {
      out[i] = right*right;
      r--;
      i--;
    }
  }
  return out;
}

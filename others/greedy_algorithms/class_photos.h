#include <vector>
#include <algorithm>
using namespace std;

int mx(const vector<int>& vec) {
  int max = vec[0];
  for(int i=0; i<vec.size(); i++) {
    max = (vec[i] > max) ? vec[i] : max;
  }
  return max;
}

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  // Write your code here.
  sort(redShirtHeights.begin(), redShirtHeights.end());
  sort(blueShirtHeights.begin(), blueShirtHeights.end());
  
  bool ret = true;
  int j=0, i=0, N = blueShirtHeights.size();
  int tr = mx(redShirtHeights), tb = mx(blueShirtHeights);
  vector<int> fr, br;
  if(tr > tb) {
    fr = blueShirtHeights;
    br = redShirtHeights;
  } else {
    fr = redShirtHeights;
    br = blueShirtHeights;
  }
  while(i < N && j < N) {
    if((fr[i] > br[j]) || (fr[i] == br[j])) {
      ret = false;
      break;
    }
    i++;
    j++;
  }
  return ret;
}

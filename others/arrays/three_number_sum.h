#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  vector<vector<int>> ret;
  int sz = array.size();
  sort(array.begin(), array.begin()+sz);
  for(int i=0; i < sz; i++) {
    int l = i+1, r = sz-1;
    int cur = i, sum = 0;
    cout << "i = " << i << " l = " << l << " r = " << r << " targetSum = " << targetSum <<endl;
    while(l < r) {
      sum = array[i] + array[l] + array[r];
      cout << "  sum = " << sum << endl;
      if(sum == targetSum) {
        ret.push_back({array[cur], array[l], array[r]});
        cout << "  " <<array[cur] << "," << array[l] << "," << array[r] << endl;
        l++;
        r--;
      } else if(sum < targetSum) {
        l++;
      } else {
        r--;
      }
    }
  }
  return ret;
}

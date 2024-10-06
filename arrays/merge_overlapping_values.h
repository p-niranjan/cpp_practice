#include <vector>
#include <algorithm>
using namespace std;

using vc = vector<int>;
bool compare(vector<int> int1, vector<int> int2) {
  return (int1[0] < int2[0]);
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  sort(intervals.begin(), intervals.end(), compare);
  //vc cur = intervals[0];
  int j = 0, N = intervals.size();
  vector<vc> out;
  out.push_back(intervals[0]);
  for(int i=1; i<N; i++) {
    vc& next = intervals[i];
    vc& cur = out[j];
    cout << "i: " << i << " intervals[i]: [" << next[0] << " , " << next[1] << "]\n";
    cout << "j: " << j << " out[j]: [" << cur[0] << " , " << cur[1] << "]\n";
    if(next[0] <= cur[1]) {
      int end = (cur[1] > next[1] ? cur[1] : next[1]);
      cur[1] = end;
      cout << "IF cur[ " << cur[0] << " , " << cur[1] <<"]\n";
    } else {
      out.push_back(next);
      j++;
      cout << "out.push_back(next); j: " << j <<"\n";
    }
  }
  return out;
}

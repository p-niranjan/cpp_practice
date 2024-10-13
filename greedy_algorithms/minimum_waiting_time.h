#include <algorithm>
using namespace std;

int minimumWaitingTime(vector<int> queries) {
  // Write your code here.
  int curWaitTime = 0, waitTime = 0;
  sort(queries.begin(), queries.end());
  for(int i=1; i<queries.size();i++) {
    curWaitTime += queries[i-1];
    waitTime += curWaitTime;
  }
  return waitTime;
}

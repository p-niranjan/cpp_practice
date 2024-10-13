#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> a) {
  // Write your code here.
  const uint32_t N = a.size();
  if(0 == N) {
    return 0;
  }

  if(1 == N) {
    return a[0];
  }

  int second = a[0];
  int first = max(second, a[1]);
  for(int i=2; i<N; i++) {
    int cur = max(first, (second+a[i]));
    second = first;
    first = cur;
  }
  return first;
}

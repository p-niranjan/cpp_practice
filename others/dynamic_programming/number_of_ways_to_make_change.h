#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  vector<int> ways(n+1, 0);
  ways[0] = 1;
  for(auto denom : denoms) {
    for(int amt = 1; amt < n+1; amt++) {
      if(denom <= amt) {
        ways[amt] += ways[amt-denom];
      }
    }
  }
  return ways[n];
}

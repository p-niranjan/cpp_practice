#include <vector>
using namespace std;

vector<vector<int>> buildSeq(vector<int> arr, vector<int> seqs, int cur, int sum);

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> arr) 
{
  const int N = arr.size();
  vector<int> sums = arr;
  vector<int> seqs(N, INT_MIN);
  int maxSumIndex = 0;
  for(int i=0; i<N; i++) {
    int cur = arr[i];
    for(int j=0; j<i; j++) {
      int other = arr[j];
      if(other < cur && cur + sums[j] >= sums[i]) {
        sums[i] = cur + sums[j];
        seqs[i] = j;
      }
    }
    if(sums[i] >= sums[maxSumIndex]) {
      maxSumIndex = i;
    }
  }
  return buildSeq(arr, seqs, maxSumIndex, sums[maxSumIndex]);
}

vector<vector<int>> buildSeq(vector<int> arr, vector<int> seqs, int cur, int sum)
{
  vector<vector<int>> seq(2);
  seq[0].push_back(sum);
  while(cur != INT_MIN) {
    seq[1].insert(seq[1].begin(), arr[cur]);
    printf("cur = %d, arr[cur] = %d\n", cur, arr[cur]);
    cur = seqs[cur];
  }
  return seq;
}
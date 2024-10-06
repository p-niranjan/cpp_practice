using namespace std;

vector<int> longestSubarrayWithSum(vector<int> a, int targetSum) {
  int start = 0, end = 0, currentSum = 0;
  const int N = a.size();
  vector<int> out;
  while(end < N) {
    currentSum += a[end];
    while(start < end && currentSum > targetSum) {
      currentSum -= a[start];
      start++;
    }

    if(currentSum == targetSum) {
      if(out.empty() || (end-start) > (out[1]-out[0])) {
        out = {start, end};
      }
    }
    end++;
  }
  return out;
}

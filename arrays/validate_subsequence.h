using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
  int arrIdx = 0, seqidx = 0;
  while(arrIdx < array.size() && seqidx < sequence.size()) {
    if(array[arrIdx] == sequence[seqidx]) {
      seqidx++;
    }
    arrIdx++;
  }
  return (seqidx == sequence.size());
}

using namespace std;

int getNextIdx(const vector<int> &arr, const int cur)
{
  const int jump = arr[cur];
  const int N = arr.size();
  int next = (jump + cur) % N;
  return (next >= 0) ? next : next+N;
}

bool hasSingleCycle(vector<int> array) {
  int numVisited = 0;
  int cur = 0;
  while(numVisited < array.size()) {
    if(numVisited > 0 && cur == 0) {
      return false;
    }
    numVisited++;
    cur = getNextIdx(array, cur);
  }
  return cur == 0;
}

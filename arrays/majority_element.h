using namespace std;

int majorityElement(vector<int> array) {
  // Write your code here.
  int N = array.size(), maj = array[0], cnt = 1;
  for(int i=1; i<N; i++) {
    if(array[i] == maj) {
      cnt++;
    } else {
      cnt--;
    }
    if(cnt == 0) {
      continue;
    }
  }
  if(cnt > 1) {
    return maj;
  }
  return -1;
}

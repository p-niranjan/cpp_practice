#include <vector>
using namespace std;

bool isOutOfOrder(const int& num, const int& i, const vector<int>& a) {
  if(0 == i) {
    return num > a[i+1];
  }
  if(a.size()-1 == i) {
    return num < a[i-1];
  }

  return (a[i] > a[i+1] || a[i] < a[i-1]);
}

vector<int> subarraySort(vector<int> a) {
  int minOOO = INT_MAX;
  int maxOOO = INT_MIN;
  vector<int> out(2);
  for(int i=0; i < a.size(); i++) {
    int num = a[i];
    if(isOutOfOrder(num, i, a)) {
      minOOO = min(minOOO, num);
      maxOOO = max(maxOOO, num);      
    }
  }
  if(INT_MAX == minOOO) {
    out[0] = -1;
    out[1] = -1;
    return {-1,-1};
  }
  int left = 0;
  while(minOOO >= a[left]) {
    left++;
  }
  int right = a.size()-1;
  while(maxOOO < a[right]) {
    right--;
  }
  return {left, right};
}

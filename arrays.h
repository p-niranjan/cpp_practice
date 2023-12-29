#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/* Two number sum */
void twoNumberSumUsingHashMap(vector<int> array, int targetSum) {
  int sz = array.size(), diff;
  unordered_set<int> mp;
  for(int i = 0; i < sz; i++) {
    diff = targetSum - array[i];
    cout << "i: " << i << " diff: " << diff << " array[i]: " << array[i] << endl;
    if(mp.find(diff) == mp.end()) {
      mp.insert(array[i]);
    } else {
      cout << array[i] << "," << diff << endl;
    }
  }
  cout << "" << endl;
}

void twoNumberSumUsingTraversers(vector<int> array, int targetSum) {
  sort(array.begin(), array.begin() + array.size());
  for(auto i : array) {
    cout << i << " ";
  }
  cout << endl;
  int L = 0, R = array.size() - 1;
  while(L < R)
    {
      if(array[L] + array[R] == targetSum)
      {
        cout << array[i] << "," << diff << endl;
      } else if(array[L] + array[R] < targetSum) {
        L++;
      } else {
        R--;
      }
    }  
  cout << "" << endl;
}

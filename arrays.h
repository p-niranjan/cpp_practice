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

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  vector<vector<int>> ret;
  int sz = array.size();
  sort(array.begin(), array.begin()+sz);
  for(int i=0; i < sz; i++) {
    int l = i+1, r = sz-1;
    int cur = i, sum = 0;
    cout << "i = " << i << " l = " << l << " r = " << r << " targetSum = " << targetSum <<endl;
    while(l < r) {
      sum = array[i] + array[l] + array[r];
      cout << "  sum = " << sum << endl;
      if(sum == targetSum) {
        ret.push_back({array[cur], array[l], array[r]});
        cout << "  " <<array[cur] << "," << array[l] << "," << array[r] << endl;
        l++;
        r--;
      } else if(sum < targetSum) {
        l++;
      } else {
        r--;
      }
    }
  }
  return ret;
}


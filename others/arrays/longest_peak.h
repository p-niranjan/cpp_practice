using namespace std;
#include <stdio.h>

int longestPeak(vector<int> a) {
  // Write your code here.
  int i = 1;
  int N = a.size();
  int cl = 0, sl = 0;
  while(i< N-1 ) {    
    bool isPeak = (a[i] > a[i-1]) && (a[i] > a[i+1]);
    printf("i: %d, a[i]: %d, a[i-1]: %d, a[i+1]: %d, isPeak: %d\n", 
      i, a[i], a[i-1], a[i+1], isPeak);
    if(!isPeak) {
      i++;
      continue;
    }

    int l = i-2;
    while(l>=0 && a[l] < a[l+1]) {
      printf("l: %d, a[l]: %d, a[l+1]: %d\n", i, a[l], a[l+1]);
      l--;
    }

    int r = i+2;
    while(r<N && a[r] < a[r-1]) {
      printf("r: %d, a[r]: %d, a[r-1]: %d\n", r, a[r], a[r-1]);
      r++;
    }
    cl = r - l - 1;
    cout << "cl: " << cl << " sl: " << sl << endl;
    sl = (cl > sl) ? cl : sl; 
    i++;
  }
  return sl;
}

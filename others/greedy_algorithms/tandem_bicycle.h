#include <vector>
#include <algorithm>
using namespace std;

bool desc(const int& a, const int& b) {
  return (a > b);
}

int tandemBicycle(
  vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest
) {
  // Write your code here.
  sort(redShirtSpeeds.begin(), redShirtSpeeds.end(), desc);
  if(fastest) {
    sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
  } else {
    sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end(), desc);
  }

  int sum = 0, N = blueShirtSpeeds.size(), opt;
  for(int i=0; i<N; i++) {
    if(fastest) {
      opt = (blueShirtSpeeds[i] > redShirtSpeeds[i]) ? blueShirtSpeeds[i] : redShirtSpeeds[i];  
    } else {
      opt = (blueShirtSpeeds[i] > redShirtSpeeds[i]) ? blueShirtSpeeds[i] : redShirtSpeeds[i];  
    }
    sum += opt;
  }
  return sum;
}

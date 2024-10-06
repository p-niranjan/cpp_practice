#include <vector>
#include <cstdlib>
using namespace std;

int firstDuplicateValue(vector<int> array) { 
  int N = array.size();
  for(int i=0; i<N; i++) {
    int absI = abs(array[i]);
    if(array[absI-1] < 0) {
      return absI;
    }
    array[absI-1] *= -1;
  }
  return -1; 
}

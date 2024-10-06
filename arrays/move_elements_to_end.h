#include <vector>

using namespace std;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.
  int i = 0, j = array.size() - 1;
  while(i < j) {
    while((i < j) && (array[j] == toMove)) {
      j--;
    }
    if(array[i] == toMove) {
      swap(array[i], array[j]);      
    }
    i++;
  }
  
  return array;
}

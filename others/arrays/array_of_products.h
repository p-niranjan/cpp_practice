#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
  // Write your code here.
  int N = array.size();
  vector<int> products(N,1);
  int leftP = 1;
  for(int i=0; i<N; i++) {
    products[i] = leftP;
    leftP = leftP * array[i];
  }
  int rightP = 1;
  for(int i=N-1; i>=0; i--) {
    products[i] *= rightP;
    rightP *= array[i];
  }
  return products;
}

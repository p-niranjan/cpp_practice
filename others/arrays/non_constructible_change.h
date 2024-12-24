#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  // Write your code here.
  int sum = 0;
  std::sort(coins.begin(), coins.end());  
  for(int i = 0; i < coins.size()-1; i++) {
    sum += coins[i];
    if(coins[i+1] > (sum + 1))
      return sum + 1;

        
  }
  return sum + 1;
}

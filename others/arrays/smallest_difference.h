#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
  std::sort(arrayOne.begin(), arrayOne.end());
  //cout << "1 " << endl;
  std::sort(arrayTwo.begin(), arrayTwo.end());
  //cout << "2 " << endl;
  int l = 0, r = 0, first, second;
  int smallestDiff = INT_MAX;
  int currentDiff = INT_MAX;
  vector<int> pairNum(2);
  //pairNum.reserve(2);
  cout << "3 " << endl;
  while(l < arrayOne.size() && r < arrayTwo.size())
  {      
      //cout << "4 " << endl;
      first = arrayOne[l];
      second = arrayTwo[r];
      cout << "first: "<< first << " second: " << second << " l: " << l << " r: " << r << endl;
      if(second < first)
      {
        cout << "second < first " << endl;
        currentDiff = first - second;
        r++;        
      } else if(first < second) {
        cout << "first < second " << endl;
        currentDiff = second - first;
        l++;
      } else {
        cout << "first = second " << endl;
        pairNum[0] = first;
        pairNum[1] = second;
        break;
      }
      if(currentDiff < smallestDiff) {        
        cout << "smallestDiff: "<< smallestDiff << " currentDiff: " << currentDiff << endl;
        pairNum[0] = first;
        pairNum[1] = second;
        smallestDiff = currentDiff;     
      }              
  }
  //cout << "10 " << endl;
  cout << "pairNum[0]: "<< pairNum[0] << " pairNum[1]: " << pairNum[1] << endl;
  return pairNum; 
}

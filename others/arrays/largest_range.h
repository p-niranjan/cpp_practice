#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array) {
  vector<int> bestRange = {};
  unordered_map<int, bool> nums = {};
  int longest = 0;
  for(int n : array) {
    nums[n] = true;
  }

  for(int n : array) {
    if(nums[n] == false) {
      continue;
    }
    nums[n] = false;
    int cur = 1;
    int left = n-1;
    int right = n+1;
    while(nums.find(left) != nums.end()) {
      nums[left] = false;
      cur++;
      left--;      
    }
    while(nums.find(right) != nums.end()) {
      nums[right] = false;
      cur++;
      right++;      
    }

    if(cur > longest) {
      longest = cur;
      bestRange = {left+1, right-1};
    }
  }
  return bestRange;
}

#include <stdio.h>
using namespace std;

int sum(int v1, int v2) {
  int sum = 0;
  for(int i=v1; i<=v2; i++) {
    sum += i;
  }
  return sum;
}
 
vector<int> missingNumbers(vector<int> nums) {
  // Write your code here.
  int N = nums.size(); 
  if(N == 0) {
    return {1,2};
  }
  int expectedSize = N+2;
  int expectedSum = expectedSize*(expectedSize+1)/2;
  int totalSum = 0;
  for(int i=0; i<N; i++) {
    totalSum += nums[i];
  }
  printf("N = %d, expectedSum = %d, totalSum = %d\n", N, expectedSum, totalSum);  
  int diff = expectedSum - totalSum;
  int avrg = diff/2;
  int leftSum = 0, rightSum = 0;
  printf("diff = %d, avrg = %d\n", diff, avrg);
  for(int i=0; i<N; i++) {
    if(nums[i] <= avrg) {
      leftSum += nums[i];
      printf("  i = %d, nums[i] = %d, leftSum = %d\n", i, nums[i], leftSum);
    } else {
      rightSum += nums[i];
      printf("  i = %d, nums[i] = %d, rightSum = %d\n", i, nums[i], rightSum);
    }
  }
  int leftSumEx = avrg*(avrg+1)/2;
  int rightSumEx = sum(avrg+1, expectedSize);
  int dif1 = leftSumEx-leftSum;
  int dif2 = rightSumEx-rightSum;
  printf("leftSumEx = %d, rightSumEx = %d, dif1 = %d, dif2 = %d\n", leftSumEx, rightSumEx, dif1, dif2); 
  return {dif1, dif2};
}
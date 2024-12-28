// https://leetcode.com/problems/maximum-average-subarray-i/description/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0;
        int sum = 0, len = 0, maxSum = INT_MIN;
        while(r < n)
        {
            sum += nums[r];
            len = r - l + 1;
            while(len > k) {
                sum -= nums[l];
                l++;
                len --;
            }
            if(len == k) {
                maxSum = max(sum, maxSum);
            }
            r++;            
        }
        return (double)maxSum / (double)k;
    }
};
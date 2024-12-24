//https://leetcode.com/problems/maximum-subarray/description/?source=submission-ac
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, n = nums.size(), maxSum = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(sum < 0) sum = 0;
            sum += nums[i];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};
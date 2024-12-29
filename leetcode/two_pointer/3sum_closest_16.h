// https://leetcode.com/problems/3sum-closest/description/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), closest = 1e9, bestSum = 0;
        for(int i = 0; i < n-1; i++) {
            int l = i+1, r = n-1;
            while(l < r) {
                int left = nums[l], right = nums[r];
                int sum = nums[i] + left + right;
                int diff = abs(target - sum);
                if(diff == 0) return sum;

                if(sum > target) r--;
                else l++;

                if(diff < closest) {
                    closest = diff;
                    bestSum = sum;
                } 
            }            
        }
        return bestSum;
    }
};
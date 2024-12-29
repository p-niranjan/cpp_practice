// https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        int len = -1e9, zeros = 0;
        while(r < n)
        {
            if(0 == nums[r]) zeros++;
            while(zeros > k) {
                if(0 == nums[l]) zeros--;
                l++;
            }
            if(zeros <= k) len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};
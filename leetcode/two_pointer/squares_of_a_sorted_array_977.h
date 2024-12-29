// https://leetcode.com/problems/squares-of-a-sorted-array/description/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, n = nums.size(), r = n-1, i = n-1;
        vector<int> out(n);
        while(l <= r)
        {
            if(abs(nums[r]) >= abs(nums[l])) {
                out[i--] = nums[r]*nums[r];
                r--;
            } else {
                out[i--] = nums[l]*nums[l];
                l++;
            }
        }
        return out;
    }
};
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, n = nums.size(), r = 0;
        int zeros = 0, maxlen = 0;

        while (r < n) {
            if (nums[r] == 0) {
                zeros++;
            }
            
            // If more than 1 zero in the window, shrink it from the left
            while (zeros > 1) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }
            
            // Update the max length, subtracting 1 to account for deleting one element
            maxlen = max(maxlen, r - l);
            r++;
        }
        
        return maxlen;
    }
};
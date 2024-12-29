// https://leetcode.com/problems/max-number-of-k-sum-pairs/description/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int l = 0, n = nums.size(), r = n-1;
        while(l < r)
        {
            int sum = nums[l] + nums[r];
            if(sum == k) {
                cnt++;
                l++;
                r--;
            }
            else if(sum < k) l++;
            else r--;
        }
        return cnt;
    }
};